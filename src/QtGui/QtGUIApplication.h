/*
 * Copyright (c) 2017, Jonathan Schleifer <js@heap.zone>
 *
 * https://heap.zone/git/objqt.git
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice is present in all copies.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import "QtCoreApplication.h"

#include <QGuiApplication>

@interface QtGUIApplication: QtCoreApplication
@property (readonly, nonatomic) QGuiApplication *qGuiApplication;
@property (nonatomic, copy) OFString *applicationDisplayName;
#if QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
@property (nonatomic, copy) OFString *desktopFileName;
#endif
@property (nonatomic) Qt::LayoutDirection layoutDirection;
@property (readonly, nonatomic) OFString *platformName;
@property (readonly, nonatomic) QScreen *primaryScreen;
@property (nonatomic) bool quitsOnLastWindowClosed;
@property (nonatomic) QIcon windowIcon;
@property (readonly, nonatomic) OFString *sessionID;
@property (readonly, nonatomic) OFString *sessionKey;

- (instancetype)initWithQCoreApplication: (QCoreApplication *)qCoreApplication
    OF_UNAVAILABLE;
- (instancetype)initWithQGuiApplication: (QGuiApplication *)qGuiApplication
    OF_DESIGNATED_INITIALIZER;
- (double)devicePixelRatio;
- (bool)isSavingSession;
- (bool)isSessionRestored;
@end

namespace ObjQt {

static OF_INLINE QtGUIApplication *
toOF(QGuiApplication *qGuiApplication)
{
	if (qGuiApplication == NULL)
		return nil;

	return [[[QtGUIApplication alloc]
	    initWithQGuiApplication: qGuiApplication] autorelease];
}

static OF_INLINE QGuiApplication *
toQt(QtGUIApplication *GUIApplication)
{
	return GUIApplication.qGuiApplication;
}

}
