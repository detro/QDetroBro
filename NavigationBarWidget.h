#ifndef NAVIGATIONBARWIDGET_H
#define NAVIGATIONBARWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>
#include "ui_NavigationBarWidget.h"

#define ANIMATION_SLIDING_PIECE 10
#define ANIMATION_TICK_FREQUENCY 25

class NavigationBarWidget : public QWidget
{
    Q_OBJECT

public:
    NavigationBarWidget(QWidget *parent = 0);
    ~NavigationBarWidget();

public:
    /** It says if the widget is fully visible.
     * It means that none of it is hidden/slided out of the screen.
     * @returns "true" if it's fully visible, "false" otherwise. */
    bool isFullyVisible();
    
public slots:
    /** Start to Slide (down if currently up, and up if currently down) */
   	void slide();
   	void slideToVisible();
   	void slideToInvisible();

protected:
    void resizeEvent(QResizeEvent *event);
   	
private slots:
	void initialize();
	void zoomIn();
	void zoomOut();
	void slideTick();
	void propagateSlideClicked();
    
signals:
	void backClicked();
	void homeClicked();
	void forwardClicked();
	void zoomLevelChanged(int);
	void slideToVisibleClicked();
	void slideToInvisibleClicked();
	
private:
    Ui::NavigationBarWidgetClass ui;
    
	int iSlidingVPosition;
	/** Represent the Visibility when the Animation started */
	bool iSlidingToInvisible;
	int iSlidingVPositionMin;
	int iSlidingVPositionMax;
	QTimer* iSlidingTimer;
};

#endif // NAVIGATIONBARWIDGET_H
