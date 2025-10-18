#pragma once
#include <Arduino.h>

class BitArray {
private:
    uint8_t* data;
    size_t bitCount;
    size_t byteCount;
    size_t index; // index courant du bit

public:
    BitArray(size_t nBits);
    ~BitArray();
    void ClearAll();
    void Set(size_t n);
    void Set();
    void Clear(size_t n);
    void Clear();
    void Toggle(size_t n);
    bool Read(size_t n);
    size_t GetIndex();
    void SetIndex(size_t n);
    void Next();
    size_t Size();
};

