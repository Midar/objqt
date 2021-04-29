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

#import "QtEvent.h"

@implementation QtEvent
@synthesize qEvent = _qEvent;

+ (int)registerEventType: (int)hint
{
	return QEvent::registerEventType(hint);
}

- (instancetype)init
{
	OF_INVALID_INIT_METHOD
}

- (instancetype)initWithQEvent: (QEvent *)qEvent
{
	self = [super init];

	_qEvent = qEvent;

	return self;
}

- (void)dealloc
{
	if (_ownsEvent)
		delete _qEvent;

	[super dealloc];
}

- (void)takeOwnership
{
	OFEnsure(!_ownsEvent);
	_ownsEvent = true;
}

- (void)giveUpOwnership
{
	OFEnsure(_ownsEvent);
	_ownsEvent = false;
}

- (void)accept
{
	_qEvent->accept();
}

- (void)ignore
{
	_qEvent->ignore();
}

- (bool)isAccepted
{
	return _qEvent->isAccepted();
}

- (void)setAccepted: (bool)accepted
{
	_qEvent->setAccepted(accepted);
}

- (bool)isSpontaneous
{
	return _qEvent->spontaneous();
}

- (QEvent::Type)type
{
	return _qEvent->type();
}
@end
