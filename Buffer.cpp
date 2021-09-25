#include"Buffer.h"
Buffer::Buffer()
{
    buffer_ = new unsigned  char[capacity_];
}

Buffer::~Buffer()
{
    if(buffer_ == nullptr)
    {
        capacity_ = 0;
        return ;
    }
    delete [] buffer_;
    buffer_ = nullptr;
    capacity_ = 0;
}

void Buffer::PutUint8(uint8_t value)
{
    Write(&value,sizeof value);
}

void Buffer::PutUint16(uint16_t value)
{
    Write(&value,sizeof value);
}

void Buffer::PutUint32(uint32_t value)
{
    Write(&value,sizeof value);
}

void Buffer::PutUint64(uint64_t value)
{
    Write(&value,sizeof(uint8_t));
}

void Buffer::PutString(const string &str)
{
    Write(str.data(),str.size());
}
uint8_t Buffer::ReadUint8()
{
    return PeekUint8();
}
uint16_t Buffer::ReadUint16()
{
    return PeekUint16();
}

uint32_t Buffer::ReadUint32()
{
    return PeekUint32();

}
uint64_t Buffer::ReadUint64()
{
    return PeekUint64();
}

string Buffer::ReadString(size_t len)
{
    return PeekString(len);
}

void Buffer::Reset()
{
    Truncate(0);
}

void Buffer::Truncate(size_t index)
{
    if(index == 0)
    {
        read_index = index;
        write_index_ = index;
    }
    else if (write_index_ > read_index + index)
    {
        write_index_ = read_index + index;
    }
    //index > write_index_ 数组越界不允许
}

void Buffer::Skip(size_t index)
{
    if(index <Length())
    {
        read_index += index;
    }
    else
    {
        Reset();
    }
}

size_t Buffer::Length()
{
    assert(write_index_ >= read_index);
    return write_index_;
}

size_t Buffer::size()
{
    return Length();
}

void Buffer::Reserve(size_t size)
{
    if(size > capacity_)
    {
        grow(size);
    }
    else
    {
        return;
    }
}

size_t Buffer::WriteableBytes()
{
    return capacity_ - write_index_;
}
void Buffer::grow(size_t size)
{
    if(WriteableBytes() < size)
    {
        size_t max_size = (capacity_<<1) + size;
        unsigned char * newbuffer = new unsigned char[max_size];
        std::memcpy(newbuffer,buffer_,Length());
        capacity_ = max_size;
        delete [] buffer_;
        buffer_ = newbuffer;
    }
}
uint8_t Buffer::PeekUint8()
{
    assert((Length() - read_index) >= sizeof(uint8_t));
    uint8_t x = 0;
    std::memcpy(&x,ReadBegin(),sizeof(uint8_t));
    read_index += sizeof(uint8_t);
    return x;
}

uint16_t Buffer::PeekUint16()
{
    assert((Length() - read_index) >= sizeof(uint16_t));
    uint16_t x = 0;
    std::memcpy(&x,ReadBegin(),sizeof(uint16_t));
    read_index += sizeof(uint16_t);
    return x;
}

uint32_t Buffer::PeekUint32()
{
    assert((Length() - read_index) >= sizeof(uint32_t));
    uint32_t x = 0;
    std::memcpy(&x,ReadBegin(),sizeof(uint32_t));
    read_index += sizeof(uint32_t);
    return x;
}

uint64_t Buffer::PeekUint64()
{
    assert((Length() - read_index) >= sizeof(uint64_t));
    uint64_t x = 0;
    std::memcpy(&x,ReadBegin(),sizeof(uint64_t));
    read_index += sizeof(uint64_t);
    return x;
}

string Buffer::PeekString(size_t len)
{
    assert((Length() - read_index) >= len);
    string str = std::string((char*)ReadBegin(),len);
    read_index += len;
    return str;
}

void Buffer::Write(const void *d, int len)
{
    std::memcpy(WriteBegin(), d, len);
    assert(write_index_ + len <= capacity_);
    write_index_ += len;
//    cout<<"write_index:"<<write_index_<<endl;
}

unsigned char *Buffer::begin()
{
    return buffer_;
}

unsigned char *Buffer::WriteBegin()
{
    return begin() + write_index_;
}



const unsigned char *Buffer::ReadBegin()
{
    return buffer_ + read_index;
}


