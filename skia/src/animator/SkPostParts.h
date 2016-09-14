
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkPostParts_DEFINED
#define SkPostParts_DEFINED

#include "SkDisplayInput.h"

class SkPost;

class SkDataInput: public SkInput {
    DECLARE_MEMBER_INFO(DataInput);
    SkDataInput();
    bool add();
    virtual void dirty() SK_OVERRIDE;
    virtual SkDisplayable* getParent() const SK_OVERRIDE;
    virtual void onEndElement(SkAnimateMaker& ) SK_OVERRIDE;
    virtual bool setParent(SkDisplayable* ) SK_OVERRIDE;
protected:
    SkPost* fParent;
    typedef SkInput INHERITED;
    friend class SkPost;
};

#endif // SkPostParts_DEFINED
