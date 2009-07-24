/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/

#include "QDetroBro.h"

#include <QtGui>
#include <QtNetwork>
#include <QtWebKit>

#include "FlickCharm.h"

QUrl guessUrlFromString(const QString &string);

QDetroBro::QDetroBro(QWidget *parent)
		:
		QWidget(parent),
		iWebView(0),
		iAddressBarWidget(0),
		iNavigationBarWidget(0)
	{
	// Load and Apply Stylesheet to the Application
	qApp->setStyleSheet(STYLE_SHEET);

	// Allocating the UI elements
	iWebView = new QWebView(this);
	iAddressBarWidget = new AddressBarWidget(this);
	iNavigationBarWidget = new NavigationBarWidget(this);
	
	// Second-phase Initialization
	QTimer::singleShot(0, this, SLOT(initialize()));
	}

void QDetroBro::initialize()
	{
	// Initializing the QWebView
	QPalette pal = iWebView->palette();
	pal.setBrush(QPalette::Base, Qt::white);
	iWebView->setPalette(pal);
	updateWebViewZoomLevel(STARTING_ZOOM_LEVEL);
	// Applying the WebView Touch Events Handler
	FlickCharm *flickCharm = new FlickCharm(this);
	flickCharm->activateOn(iWebView);
	iWebView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	// Give focus to the WebView
	iWebView->setFocus();

	// iNavigationBarWidget Signals
	connect(iNavigationBarWidget, SIGNAL(backClicked()), iWebView, SLOT(back()));
	connect(iNavigationBarWidget, SIGNAL(forwardClicked()), iWebView, SLOT(forward()));
	connect(iNavigationBarWidget, SIGNAL(homeClicked()), this, SLOT(loadHomeUrl()));
	connect(iNavigationBarWidget, SIGNAL(zoomLevelChanged(int)), this, SLOT(updateWebViewZoomLevel(int)));
	// iAddressBarWidget Signals
	connect(iAddressBarWidget, SIGNAL(reloadClicked()), iWebView, SLOT(reload()));
	connect(iAddressBarWidget, SIGNAL(goClicked()), this, SLOT(loadCurrentUrl()));
	// iWebView Signals
	connect(iWebView, SIGNAL(urlChanged(const QUrl&)), this, SLOT(updateAddressLineEdit(const QUrl&)));
	connect(iWebView, SIGNAL(loadStarted()), iAddressBarWidget, SLOT(setLoadingStarted()));
	connect(iWebView, SIGNAL(loadProgress(int)), iAddressBarWidget, SLOT(setLoadingProgress(int)));
	connect(iWebView, SIGNAL(loadFinished(bool)), iAddressBarWidget, SLOT(setLoadingFinished()));
	// Connect to Signal to know about Focus Change events within the App
	connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(handleFocusChange(QWidget*, QWidget*)));
	// Connect the Sliding so that a click on one Slide, makes also the other Bar slide
	connect(iAddressBarWidget, SIGNAL(slideToVisibleClicked()), iNavigationBarWidget, SLOT(slideToVisible()));
	connect(iAddressBarWidget, SIGNAL(slideToInvisibleClicked()), iNavigationBarWidget, SLOT(slideToInvisible()));
	connect(iNavigationBarWidget, SIGNAL(slideToVisibleClicked()), iAddressBarWidget, SLOT(slideToVisible()));
	connect(iNavigationBarWidget, SIGNAL(slideToInvisibleClicked()), iAddressBarWidget, SLOT(slideToInvisible()));
	
	// Load the Home URL
	loadHomeUrl();
	}

void QDetroBro::loadHomeUrl()
	{
	iWebView->load(QUrl(HOME_URL));
	}

void QDetroBro::loadCurrentUrl()
	{
	iWebView->load(guessUrlFromString(iAddressBarWidget->address()));
	}

void QDetroBro::updateAddressLineEdit(const QUrl& aUrl)
	{
	iAddressBarWidget->setAddress(aUrl.toString());
 	}

void QDetroBro::updateWebViewZoomLevel(int aValue)
	{
	iWebView->setZoomFactor(static_cast<qreal>(aValue)/100.0);
	}

void QDetroBro::handleFocusChange(QWidget* aOldFocusWidget, QWidget* aNowFocusWidget)
	{	
	QWebView* webViewWidget = dynamic_cast<QWebView*>(aNowFocusWidget);
	if (webViewWidget)
		{
		if ( iAddressBarWidget->isFullyVisible() )
			iAddressBarWidget->slide();
		
		if ( iNavigationBarWidget->isFullyVisible() )
			iNavigationBarWidget->slide();
		}
	}

QDetroBro::~QDetroBro()
	{
	// Nothing to do here
	}

void QDetroBro::resizeEvent(QResizeEvent *event)
	{
    QWidget::resizeEvent(event);
    
    // Positioning the AddressBarWidget
    iAddressBarWidget->setGeometry(0, 0, width(), iAddressBarWidget->height());
    // Positioning the NavigationBarWidget
    iNavigationBarWidget->setGeometry(0, height() - iNavigationBarWidget->height(), width(), iNavigationBarWidget->height());
    // Positioning the WebView
    iWebView->setGeometry(0, 0, width(), height());    
	}

// from Demo Browser
QUrl guessUrlFromString(const QString &string)
	{
    QString urlStr = string.trimmed();
    QRegExp test(QLatin1String("^[a-zA-Z]+\\:.*"));

    // Check if it looks like a qualified URL. Try parsing it and see.
    bool hasSchema = test.exactMatch(urlStr);
    if (hasSchema) {
        QUrl url = QUrl::fromEncoded(urlStr.toUtf8(), QUrl::TolerantMode);
        if (url.isValid())
            return url;
    }

    // Might be a file.
    if (QFile::exists(urlStr)) {
        QFileInfo info(urlStr);
        return QUrl::fromLocalFile(info.absoluteFilePath());
    }

    // Might be a shorturl - try to detect the schema.
    if (!hasSchema) {
        int dotIndex = urlStr.indexOf(QLatin1Char('.'));
        if (dotIndex != -1) {
            QString prefix = urlStr.left(dotIndex).toLower();
            QString schema = (prefix == QString("ftp")) ? prefix.toLatin1() : QString("http");
            QString location = schema + "://" + urlStr;
            QUrl url = QUrl::fromEncoded(location.toUtf8(), QUrl::TolerantMode);
            if (url.isValid())
                return url;
        }
    }

    // Fall back to QUrl's own tolerant parser.
    QUrl url = QUrl::fromEncoded(string.toUtf8(), QUrl::TolerantMode);

    // finally for cases where the user just types in a hostname add http
    if (url.scheme().isEmpty())
        url = QUrl::fromEncoded("http://" + string.toUtf8(), QUrl::TolerantMode);
    return url;
	}
