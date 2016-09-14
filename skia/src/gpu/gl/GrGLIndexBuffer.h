/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGLIndexBuffer_DEFINED
#define GrGLIndexBuffer_DEFINED

#include "GrIndexBuffer.h"
#include "GrGLBufferImpl.h"
#include "gl/GrGLInterface.h"

class GrGLGpu;

class GrGLIndexBuffer : public GrIndexBuffer {

public:
    typedef GrGLBufferImpl::Desc Desc;

    GrGLIndexBuffer(GrGLGpu* gpu, const Desc& desc);

    GrGLuint bufferID() const { return fImpl.bufferID(); }
    size_t baseOffset() const { return fImpl.baseOffset(); }

    void bind() const {
        if (!this->wasDestroyed()) {
            fImpl.bind(this->getGpuGL());
        }
    }

protected:
    virtual void onAbandon() SK_OVERRIDE;
    virtual void onRelease() SK_OVERRIDE;

private:
    virtual void* onMap() SK_OVERRIDE;
    virtual void onUnmap() SK_OVERRIDE;
    virtual bool onUpdateData(const void* src, size_t srcSizeInBytes) SK_OVERRIDE;

    GrGLGpu* getGpuGL() const {
        SkASSERT(!this->wasDestroyed());
        return (GrGLGpu*)(this->getGpu());
    }

    GrGLBufferImpl fImpl;

    typedef GrIndexBuffer INHERITED;
};

#endif
