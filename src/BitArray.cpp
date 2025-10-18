#include "BitArray.h"

BitArray::BitArray(size_t nBits) : bitCount(nBits), byteCount((nBits + 7) / 8), index(0)
{
    data = new uint8_t[byteCount];
    ClearAll();
}

BitArray::~BitArray() {
    delete[] data;
}

void BitArray::ClearAll() {
    memset(data, 0, byteCount);
    index = 0;
}

void BitArray::Set(size_t n) {
    if (n < bitCount)
        data[n / 8] |= (1 << (n % 8));
}

void BitArray::Set() {
    if (index < bitCount)
        data[index / 8] |= (1 << (index % 8));
    Next();
}

void BitArray::Clear(size_t n) {
    if (n < bitCount)
        data[n / 8] &= ~(1 << (n % 8));
}

void BitArray::Clear() {
    if (index < bitCount)
        data[index / 8] &= ~(1 << (index % 8));
    Next();
}

void BitArray::Toggle(size_t n) {
    if (n < bitCount)
        data[n / 8] ^= (1 << (n % 8));
}

bool BitArray::Read(size_t n) const {
    if (n < bitCount)
        return (data[n / 8] >> (n % 8)) & 1;
    return false;
}

size_t BitArray::GetIndex() const { return index; }

void BitArray::SetIndex(size_t n) {
    if (n < bitCount) index = n;
}

void BitArray::Next() {
    if (++index >= bitCount)
        index = 0; // revient au début (optionnel)
}

size_t BitArray::Size() const { return bitCount; }

