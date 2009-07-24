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

#ifndef QDETROBRO_H
#define QDETROBRO_H

// External
#include <QtWebKit/QWebView>
// Internal
#include "AddressBarWidget.h"
#include "NavigationBarWidget.h"

// Constants/Macros
#define STARTING_ZOOM_LEVEL 100
#define HOME_URL "http://www.google.com/"
//#define HOME_URL "file:///c:/index.html"
#define STYLE_SHEET " \
	QAbstractButton, QLineEdit, QProgressBar, QSlider { \
		background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 180), stop:1 rgba(0,0,0,140)); \
		border: 2px solid black; \
		border-radius: 5px; \
	} \
	\
	QAbstractButton:pressed, QLineEdit:focus { \
		background-color: rgba(0, 0, 0, 200); \
	}"

// Pre-declaration
class QUrl;

class QDetroBro : public QWidget
{
    Q_OBJECT

public:
	QDetroBro(QWidget *parent = 0);
    ~QDetroBro();

private slots:
    void initialize();
    void loadHomeUrl();
    void loadCurrentUrl();
    void updateWebViewZoomLevel(int aValue);
    void updateAddressLineEdit(const QUrl& aUrl);
    void handleFocusChange(QWidget* aOldFocusWidget, QWidget* aNowFocusWidget);

protected:
    void resizeEvent(QResizeEvent *event);
    
private:    
    QWebView* iWebView;
    AddressBarWidget* iAddressBarWidget;
    NavigationBarWidget* iNavigationBarWidget;
};

#endif // QDETROBRO_H
