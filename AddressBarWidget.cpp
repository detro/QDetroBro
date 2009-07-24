#include "addressbarwidget.h"

AddressBarWidget::AddressBarWidget(QWidget *parent)
		: QWidget(parent),
		iSlidingVPosition (0),
		iSlidingToInvisible (true),
		iSlidingTimer(0)
	{
	// Setting up the UI
	ui.setupUi(this);
	setLoadingFinished(); // Init the Loading part of the UI
	
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
	connect(ui.GoPushButton, SIGNAL(clicked()), this, SIGNAL(goClicked()));
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
	}

void AddressBarWidget::resizeEvent(QResizeEvent *event)
	{
    QWidget::resizeEvent(event);
    // Calculating the Sliding "limits"
	iSlidingVPositionMin = -( ui.SlidePushButton->y() + ui.SlidePushButton->height()/2 );
	iSlidingVPositionMax = 0;
	}
