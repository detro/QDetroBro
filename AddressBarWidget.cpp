#include "AddressBarWidget.h"

AddressBarWidget::AddressBarWidget(QWidget *parent)
		: QWidget(parent),
		iSlidingVPosition (0),
		iSlidingToInvisible (true),
		iSlidingTimer(0)
	{
	// Setting up the UI
	ui.setupUi(this);
	setLoadingFinished(); // Init the Loading part of the UI
	
	// Setting up the Icons for the "GoStopPushButton"
	iStopIcon.addFile(QString::fromUtf8(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::On);
	iGoIcon.addFile(QString::fromUtf8(":/images/go.png"), QSize(), QIcon::Normal, QIcon::On);
	
	// Setting the Color for the "Busy Loading Chase Widget" (Orange official color)
	ui.BusyLoadingChaseWidget->setBaseColor(QColor(255, 102, 0));
	
	// Creating the Timer
	iSlidingTimer = new QTimer(this);	
	
	// Second-phase Initialization
	QTimer::singleShot(0, this, SLOT(initialize()));
	}

void AddressBarWidget::initialize()
	{	
	// Connecting necessary Signals to Slots
	connect(iSlidingTimer, SIGNAL(timeout()), this, SLOT(slideTick()));
	connect(ui.SlidePushButton, SIGNAL(clicked()), this, SLOT(propagateSlideClicked()));
	connect(ui.SlidePushButton, SIGNAL(clicked()), this, SLOT(slide()));
	// Connecting internal Signals with external ones
	connect(ui.GoStopPushButton, SIGNAL(clicked()), this, SIGNAL(goClicked()));
	connect(ui.ReloadPushButton, SIGNAL(clicked()), this, SIGNAL(reloadClicked()));
	}

AddressBarWidget::~AddressBarWidget()
	{
	// Nothing to do here
	}

QString AddressBarWidget::address() const
	{
	return ui.AddressLineEdit->text();
	}
   
void AddressBarWidget::setAddress(const QString aAddress)
	{
	ui.AddressLineEdit->setText(aAddress);
	}

bool AddressBarWidget::isFullyVisible()
	{
	return this->y() == iSlidingVPositionMax;
	}

void AddressBarWidget::slide()
	{
	// Understand in which position it is at the beginning of the Animation
	iSlidingToInvisible = isFullyVisible();
	iSlidingVPosition = this->y();
	iSlidingTimer->start(ANIMATION_TICK_FREQUENCY); // "Tick" every 10ms
	}

void AddressBarWidget::slideToVisible()
	{
	if ( !isFullyVisible() )
		slide();
	}

void AddressBarWidget::slideToInvisible()
	{
	if ( isFullyVisible() )
		slide();
	}

void AddressBarWidget::propagateSlideClicked()
	{
	if ( isFullyVisible() )
		emit slideToInvisibleClicked();
	else
		emit slideToVisibleClicked();
	}

void AddressBarWidget::slideTick()
	{
	iSlidingVPosition += iSlidingToInvisible ?	// Normalizing the Piece
			qMax(-ANIMATION_SLIDING_PIECE, iSlidingVPositionMin - iSlidingVPosition) :
			qMin(+ANIMATION_SLIDING_PIECE, iSlidingVPositionMax - iSlidingVPosition);
	this->move(0, iSlidingVPosition); // Move only vertically
	if ( 
			( iSlidingToInvisible && iSlidingVPosition == iSlidingVPositionMin )
			|| ( !iSlidingToInvisible && iSlidingVPosition == iSlidingVPositionMax )
		)
		{
		iSlidingTimer->stop();
		}
	}

void AddressBarWidget::setLoadingStarted()
	{
	if ( !isFullyVisible() )
		{
		// Slide down if it's not already visible
		slide();
		}
	ui.BusyLoadingChaseWidget->setAnimated(true);
	ui.BusyLoadingChaseWidget->show();
	ui.LoadingProgressBar->show();
	
	// Set to show the "Stop" Icon
	setStopIcon();
	}
	
void AddressBarWidget::setLoadingProgress(const int aProgress)
	{
	ui.LoadingProgressBar->setValue(aProgress);
	}
	
void AddressBarWidget::setLoadingFinished()
	{
	ui.BusyLoadingChaseWidget->setAnimated(false);
	ui.BusyLoadingChaseWidget->hide();
	ui.LoadingProgressBar->hide();
	
	// Set to show the "Go" Icon
	setGoIcon();
	}

void AddressBarWidget::setGoIcon()
	{
	ui.GoStopPushButton->setIcon(iGoIcon);
	ui.GoStopPushButton->setIconSize(QSize(40, 40));
	ui.GoStopPushButton->setFlat(false);
	
	// Put the proper Signal Connections in place:
	// 	when the GoStopPushButton is clicked, sent a "goClicked" signal.
	disconnect(ui.GoStopPushButton, SIGNAL(clicked()), this, SIGNAL(stopClicked()));
	connect(ui.GoStopPushButton, SIGNAL(clicked()), this, SIGNAL(goClicked()));
	}

void AddressBarWidget::setStopIcon()
	{
	ui.GoStopPushButton->setIcon(iStopIcon);
	ui.GoStopPushButton->setIconSize(QSize(40, 40));
	ui.GoStopPushButton->setFlat(false);
	
	// Put the proper Signal Connections in place:
	// 	when the GoStopPushButton is clicked, sent a "sopClicked" signal.
	disconnect(ui.GoStopPushButton, SIGNAL(clicked()), this, SIGNAL(goClicked()));
	connect(ui.GoStopPushButton, SIGNAL(clicked()), this, SIGNAL(stopClicked()));
	}

void AddressBarWidget::resizeEvent(QResizeEvent *event)
	{
    QWidget::resizeEvent(event);
    // Calculating the Sliding "limits"
	iSlidingVPositionMin = -( ui.SlidePushButton->y() + ui.SlidePushButton->height()/2 );
	iSlidingVPositionMax = 0;
	}
