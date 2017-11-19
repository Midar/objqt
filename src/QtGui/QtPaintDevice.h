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

#import <ObjFW/ObjFW.h>

#include <QPaintDevice>

@protocol QtPaintDevice
@property (readonly, nonatomic) QPaintDevice *qPaintDevice;
@property (readonly, nonatomic) int colorCount;
@property (readonly, nonatomic) int depth;
@property (readonly, nonatomic) int devicePixelRatio;
#if QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
@property (readonly, nonatomic) double devicePixelRatioF;
#endif
@property (readonly, nonatomic) int height;
@property (readonly, nonatomic) int heightMM;
@property (readonly, nonatomic) int logicalDPIX;
@property (readonly, nonatomic) int logicalDPIY;
@property (readonly, nonatomic) QPaintEngine *paintEngine;
@property (readonly, nonatomic) bool paintingActive;
@property (readonly, nonatomic) int physicalDPIX;
@property (readonly, nonatomic) int physicalDPIY;
@property (readonly, nonatomic) int width;
@property (readonly, nonatomic) int widthMM;
@end

@interface QtPaintDevice: OFObject <QtPaintDevice>
@property (readonly, nonatomic) QObject *qObject;
@end

namespace ObjQt {

static OF_INLINE QPaintDevice *
toQt(QtPaintDevice *paintDevice)
{
	return [paintDevice qPaintDevice];
}

}
