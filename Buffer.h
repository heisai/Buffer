#ifndef BUFFER_H
#define BUFFER_H
#include<iostream>
#include<cstring>
#include<assert.h>
using namespace  std;
class Buffer
{
public:
    explicit Buffer();
    virtual ~Buffer();
public:
    void PutUint8(uint8_t value);
    void PutUint16(uint16_t value);
    void PutUint32(uint32_t value);
    void PutUint64(uint64_t value);
    void PutString(const string &str);
    uint8_t  ReadUint8();
    uint16_t ReadUint16();
    uint32_t ReadUint32();
    uint64_t ReadUint64();
    string ReadString(size_t len);
    void Reset();
    void Truncate(size_t index);
    void Skip(size_t index);
    size_t Length();
    size_t size();
    void Reserve(size_t size);
    size_t WriteableBytes();

private:
    uint8_t  PeekUint8();
    uint16_t PeekUint16();
    uint32_t PeekUint32();
    uint64_t PeekUint64();
    string   PeekString(size_t len);
    void Write(const void*  d, int len);
    void Read();
    unsigned char *begin();
    unsigned char* WriteBegin();
    const unsigned  char * ReadBegin();
    int Capacity()const {return capacity_;}
    void grow(size_t size);

private:
    unsigned char *buffer_;
    size_t write_index_ = 0;
    size_t read_index = 0;
    size_t capacity_ = 2048;
};
#endif // BUFFER_H
