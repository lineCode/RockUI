/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkArcToPathEffect_DEFINED
#define SkArcToPathEffect_DEFINED

#include "SkPathEffect.h"

class SK_API SkArcToPathEffect : public SkPathEffect {
public:
    /** radius must be > 0 to have an effect. It specifies the distance from each corner
        that should be "rounded".
    */
    static SkPathEffect* Create(SkScalar radius) {
        if (radius <= 0) {
            return NULL;
        }
        return SkNEW_ARGS(SkArcToPathEffect, (radius));
    }

    bool filterPath(SkPath* dst, const SkPath& src, SkStrokeRec*, const SkRect*) const SK_OVERRIDE;

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkArcToPathEffect)

protected:
    explicit SkArcToPathEffect(SkScalar radius);
    virtual void flatten(SkWriteBuffer&) const SK_OVERRIDE;

private:
    SkScalar fRadius;

    typedef SkPathEffect INHERITED;
};

#endif
