#ifndef ADDRESSBARWIDGET_H
#define ADDRESSBARWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>
#include "ui_AddressBarWidget.h"

#define ANIMATION_SLIDING_PIECE 10
#define ANIMATION_TICK_FREQUENCY 25

class AddressBarWidget : public QWidget
{
    Q_OBJECT

public:
    AddressBarWidget(QWidget *parent = 0);
    ~AddressBarWidget();	
	
public:
    /** It says if the widget is fully visible.
     * It means that none of it is hidden/slided out of the screen.
     * 
     * @returns "true" if it's fully visible, "false" otherwise. */
    bool isFullyVisible();
    
    /** Returns the current text value of the embedded QLineEdit.
     * 
     * @returns QString with the content (current address) of the embedded QLineEdit. */
    QString address() const;
    /** Sets the current text value of the embedded QLineEdit.
     * 
     * @param aAddress The text value (address) to set for the embedded QLineEdit. */
    void setAddress(const QString aAddress);
    
public slots:
	/** Start to Slide (up if currently down, and down if currently up) */
	void slide();
	void slideToVisible();
	void slideToInvisible();
	/** Set the Loading as Started.
	 * The spinning busy icon will appear and the progress bar resetted. */ 
	void setLoadingStarted();
	/** Set the Loading Progress.
	 * @param aProgress Integer value from 0 to 100. */
	void setLoadingProgress(const int aProgress);
	/** Set the Loading as Finished (Done). 
	 * The spinning busy icon will disappear and the progress bar will be resetted. */
	void setLoadingFinished();

protected:
    void resizeEvent(QResizeEvent *event);
	
private slots:
	void initialize();
	void slideTick();
	void propagateSlideClicked();
	void setGoIcon();
	void setStopIcon();

signals:
	void goClicked();
	void stopClicked();
	void reloadClicked();
	void slideToVisibleClicked();
	void slideToInvisibleClicked();
  
private:
    Ui::AddressBarWidgetClass ui;
    
    QIcon iStopIcon;
    QIcon iGoIcon;
    
    // It's supposed to be a value minor or equal '0'
    int iSlidingVPosition;
    /** Represent the Visibility when the Animation started */
    bool iSlidingToInvisible;
    int iSlidingVPositionMin;
    int iSlidingVPositionMax;
    QTimer* iSlidingTimer;
};

#endif // ADDRESSBARWIDGET_H
