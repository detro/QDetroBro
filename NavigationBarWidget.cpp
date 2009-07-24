#include "NavigationBarWidget.h"

NavigationBarWidget::NavigationBarWidget(QWidget *parent)
		: 
		QWidget(parent),
		iSlidingTimer(0)
	{
	ui.setupUi(this);
	
	// Creating the Timer
	iSlidingTimer = new QTimer(this);	
	
	// Second-phase Initialization
	QTimer::singleShot(0, this, SLOT(initialize()));
	}

void NavigationBarWidget::initialize()
	{
	// Connecting necessary Signals to Slots
	connect(iSlidingTimer, SIGNAL(timeout()), this, SLOT(slideTick()));
	connect(ui.SlidePushButton, SIGNAL(clicked()), this, SLOT(propagateSlideClicked()));
	connect(ui.SlidePushButton, SIGNAL(clicked()), this, SLOT(slide()));
	// Attaching Signals and Slots for Zooming
	connect(ui.ZoomInPushButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
	connect(ui.ZoomOutPushButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
	// Connecting internal Signals with external ones, for encapsulation
	connect(ui.BackPushButton, SIGNAL(clicked()), this, SIGNAL(backClicked()));
	connect(ui.ForwardPushButton, SIGNAL(clicked()), this, SIGNAL(forwardClicked()));
	connect(ui.HomePushButton, SIGNAL(clicked()), this, SIGNAL(homeClicked()));
	connect(ui.ZoomSlider, SIGNAL(valueChanged(int)), this, SIGNAL(zoomLevelChanged(int)));
	}

NavigationBarWidget::~NavigationBarWidget()
	{
	// Nothing to do here
	}

bool NavigationBarWidget::isFullyVisible()
	{
	return this->y() == iSlidingVPositionMin;
	}

void NavigationBarWidget::slide()
	{
	// Understand in which position it is at the beginning of the Animation
	iSlidingToInvisible = isFullyVisible();
	iSlidingVPosition = this->y();
	iSlidingTimer->start(ANIMATION_TICK_FREQUENCY); // "Tick" every 10ms
	}

void NavigationBarWidget::slideToVisible()
	{
	if ( !isFullyVisible() )
		slide();
	}

void NavigationBarWidget::slideToInvisible()
	{
	if ( isFullyVisible() )
		slide();
	}

void NavigationBarWidget::propagateSlideClicked()
	{
	if ( isFullyVisible() )
		emit slideToInvisibleClicked();
	else
		emit slideToVisibleClicked();
	}

void NavigationBarWidget::slideTick()
	{
	iSlidingVPosition += iSlidingToInvisible ?	// Normalizing the Piece
			qMin(+ANIMATION_SLIDING_PIECE, iSlidingVPositionMax - iSlidingVPosition) :
			qMax(-ANIMATION_SLIDING_PIECE, iSlidingVPositionMin - iSlidingVPosition);
	this->move(0, iSlidingVPosition); // Move only vertically
	if ( 
			( iSlidingToInvisible && iSlidingVPosition == iSlidingVPositionMax )
			|| ( !iSlidingToInvisible && iSlidingVPosition == iSlidingVPositionMin )
		)
		{
		iSlidingTimer->stop();
		}
	}

void NavigationBarWidget::zoomIn()
	{
	ui.ZoomSlider->setValue( ui.ZoomSlider->value() + ui.ZoomSlider->singleStep() );
	}

void NavigationBarWidget::zoomOut()
	{
	ui.ZoomSlider->setValue( ui.ZoomSlider->value() - ui.ZoomSlider->singleStep() );
	}

void NavigationBarWidget::resizeEvent(QResizeEvent *event)
	{
    QWidget::resizeEvent(event);
	
    // Calculating the Sliding "limits"
	iSlidingVPositionMin = this->y();
	iSlidingVPositionMax = 
			this->y() + this->height() - ui.SlidePushButton->y() - ui.SlidePushButton->height()/2;
	}
