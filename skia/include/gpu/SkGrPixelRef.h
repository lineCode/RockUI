/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkGrPixelRef_DEFINED
#define SkGrPixelRef_DEFINED

#include "SkBitmap.h"
#include "SkPixelRef.h"
#include "GrTexture.h"
#include "GrRenderTarget.h"


/**
 *  Common baseclass that implements onLockPixels() by calling onReadPixels().
 *  Since it has a copy, it always returns false for onLockPixelsAreWritable().
 */
class SK_API SkROLockPixelsPixelRef : public SkPixelRef {
public:
    SK_DECLARE_INST_COUNT(SkROLockPixelsPixelRef)
    SkROLockPixelsPixelRef(const SkImageInfo&);
    virtual ~SkROLockPixelsPixelRef();

protected:
    virtual bool onNewLockPixels(LockRec*) SK_OVERRIDE;
    virtual void onUnlockPixels() SK_OVERRIDE;
    virtual bool onLockPixelsAreWritable() const SK_OVERRIDE;   // return false;

private:
    SkBitmap    fBitmap;
    typedef SkPixelRef INHERITED;
};

/**
 *  PixelRef that wraps a GrSurface
 */
class SK_API SkGrPixelRef : public SkROLockPixelsPixelRef {
public:
    SK_DECLARE_INST_COUNT(SkGrPixelRef)
    /**
     * Constructs a pixel ref around a GrSurface.
     */
    SkGrPixelRef(const SkImageInfo&, GrSurface*);
    virtual ~SkGrPixelRef();

    // override from SkPixelRef
    virtual GrTexture* getTexture() SK_OVERRIDE;

protected:
    // overrides from SkPixelRef
    virtual bool onReadPixels(SkBitmap* dst, const SkIRect* subset) SK_OVERRIDE;
    virtual SkPixelRef* deepCopy(SkColorType, SkColorProfileType,
                                 const SkIRect* subset) SK_OVERRIDE;

private:
    GrSurface*  fSurface;
    typedef SkROLockPixelsPixelRef INHERITED;
};

#endif
