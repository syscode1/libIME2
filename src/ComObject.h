#pragma once

#include <Unknwn.h>
#include <cassert>

namespace Ime {

// Common base class to implement COM objects.
template <typename... Interfaces>
class ComObject : public IUnknown, public Interfaces... {
public:
    ComObject() : refCount_{ 1 } {}

    virtual ~ComObject() {}

    int refCount() const {
        return refCount_;
    }

    STDMETHODIMP QueryInterface(REFIID riid, void** ppvObj) {
        if (ppvObj == nullptr) {
            return E_POINTER;
        }
        *ppvObj = queryInterface<IUnknown, Interfaces...>(riid);
        if (*ppvObj) {
            AddRef();
            return S_OK;
        }
        return E_NOINTERFACE;
    }

    STDMETHODIMP_(ULONG) AddRef() {
        return ++refCount_;
    }

    STDMETHODIMP_(ULONG) Release() {
        assert(refCount_ > 0);
        const ULONG newCount = --refCount_;
        if (0 == refCount_) {
            delete this;
        }
        return newCount;
    }

private:

    template <typename T>
    void* queryInterface(REFIID riid) {
        return riid == __uuidof(T) ? (T*)this : nullptr;
    }

    template <typename T, typename U, typename... Args>
    void* queryInterface(REFIID riid) {
        return riid == __uuidof(T) ? (T*)this : queryInterface<U, Args...>(riid);
    }

private:
    int refCount_;
};

} // namespace Ime
