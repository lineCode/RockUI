
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkCubicInterval_DEFINED
#define SkCubicInterval_DEFINED

#include "SkPoint.h"

SkScalar SkEvalCubicInterval(SkScalar x1, SkScalar y1,
                             SkScalar x2, SkScalar y2,
                             SkScalar unitX);

static inline SkScalar SkEvalCubicInterval(const SkPoint pts[2], SkScalar x) {
    return SkEvalCubicInterval(pts[0].fX, pts[0].fY,
                               pts[1].fX, pts[1].fY, x);
}

#endif
