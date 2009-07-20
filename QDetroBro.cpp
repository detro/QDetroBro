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
    QMainWindow(parent),
    iHomeUrl(new QUrl(MHOME_URL)),
    iCurrentZoomLevel(100)
{
	ui.setupUi(this);
	QTimer::singleShot(0, this, SLOT(initialize()));
}

void QDetroBro::initialize()
	{
	// Connect buttons' signals to the proper slot
	// Signals that make the WebView go Back and Forward in the History
	connect(ui.BackButton, SIGNAL(clicked()), ui.WebView, SLOT(back()));
	connect(ui.ForwardButton, SIGNAL(clicked()), ui.WebView, SLOT(forward()));
	// Signals that make the WebView reload the current page
	connect(ui.ReloadButton, SIGNAL(clicked()), ui.WebView, SLOT(reload()));
	// Signals managed by this Class's Slots
	connect(ui.HomeButton, SIGNAL(clicked()), this, SLOT(loadHomeUrl()));
	connect(ui.GoButton, SIGNAL(clicked()), this, SLOT(loadCurrentUrl()));
	connect(ui.WebView, SIGNAL(urlChanged(const QUrl&)), this, SLOT(updateAddressLineEdit(const QUrl&)));
	connect(ui.ZoomSlider, SIGNAL(valueChanged(int)), this, SLOT(updateWebViewZoomLevel(int)));
	// Signals that Reset the Progress Bar
	connect(ui.GoButton, SIGNAL(clicked()), ui.ProgressBar, SLOT(reset()));
	connect(ui.HomeButton, SIGNAL(clicked()), ui.ProgressBar, SLOT(reset()));
	connect(ui.ReloadButton, SIGNAL(clicked()), ui.ProgressBar, SLOT(reset()));
	connect(ui.WebView, SIGNAL(loadStarted()), ui.ProgressBar, SLOT(reset()));
	// Signals that Set a Value on the Progress Bar
	connect(ui.WebView, SIGNAL(loadProgress(int)), ui.ProgressBar, SLOT(setValue(int)));
	// Signals that Set the "Loading Label" using this Class's Slots
	connect(ui.GoButton, SIGNAL(clicked()), this, SLOT(setAsLoading()));
	connect(ui.HomeButton, SIGNAL(clicked()), this, SLOT(setAsLoading()));
	connect(ui.ReloadButton, SIGNAL(clicked()), this, SLOT(setAsLoading()));
	connect(ui.WebView, SIGNAL(loadStarted()), this, SLOT(setAsLoading()));
	connect(ui.WebView, SIGNAL(loadFinished(bool)), this, SLOT(setAsDoneLoading()));
	
	// Setting the WebView
	QPalette pal = ui.WebView->palette();
	pal.setBrush(QPalette::Base, Qt::white);
	ui.WebView->setPalette(pal);
	updateWebViewZoomLevel(ui.ZoomSlider->value());
	// Applying the WebView Touch Events Handler
	FlickCharm *flickCharm = new FlickCharm(this);
	flickCharm->activateOn(ui.WebView);
	
	// Load the Home URL
	loadHomeUrl();
	// Give focus to the WebView
	ui.WebView->setFocus();
	}

void QDetroBro::loadHomeUrl()
	{
	ui.WebView->load(*iHomeUrl);
	}

void QDetroBro::loadCurrentUrl()
	{
	ui.WebView->load(guessUrlFromString(ui.AddressLineEdit->text()));
	}

void QDetroBro::updateAddressLineEdit(const QUrl& aUrl)
	{
	ui.AddressLineEdit->setText(aUrl.toString());
	}

void QDetroBro::updateWebViewZoomLevel(int aValue)
	{
	ui.WebView->setZoomFactor(static_cast<qreal>(aValue)/100.0);
	}

void QDetroBro::setAsLoading()
	{
	ui.LoadingLabel->setText("load");
	}

void QDetroBro::setAsDoneLoading()
	{
	ui.LoadingLabel->setText("done");
	}

QDetroBro::~QDetroBro()
{
	if ( NULL != iHomeUrl )
		delete iHomeUrl;
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
