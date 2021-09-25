# Buffer
## 前言
__在二进制传输中， 有固有的数据格式， 包头包尾，比如包头由几个字段组成，每个字段是不同的字节进行数据拼包，组成一帧完整的数据发送出去。 以及接受到数据根据不同的字段解析各个数据__
## 案例

* 版本号(1 byte)

* 功能(1 byte)

* 模式 （2 bytes）

* 数据长度(4 bytes)

* 数据 (数据长度)

* 结束标志(1 byte)
```cpp
    Buffer bf;
    bf.PutUint8(10);            // 版本号
    bf.PutUint8(11);            // 功能
    bf.PutUint16(3);            //模式
    bf.PutUint32(9);            //数据长度
    bf.PutString("qwertyuio");  //数据
    bf.PutUint8(7);             //结束标志
    std::cout<<"数据长度:"<<int(bf.size())<<std::endl;

    std::cout<<"版本号:"<<int(bf.ReadUint8())<<std::endl;
    std::cout<<"功能:"<<int(bf.ReadUint8())<<std::endl;
    std::cout<<"模式:"<<int(bf.ReadUint16())<<std::endl;
    int len = bf.ReadUint32();
    std::cout<<"数据长度:"<<len<<std::endl;
    std::cout<<"数据:"<<(bf.ReadString(len))<<std::endl;
    std::cout<<"结束标志:"<<int(bf.ReadUint8())<<std::endl;
```

   
