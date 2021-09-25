#include <iostream>
#include"Buffer.h"
using namespace std;

int main()
{
    Buffer bf;
    bf.PutUint8(10);
    bf.PutUint8(11);
    bf.PutUint16(1000);
    bf.PutUint32(10000);
    bf.PutString("qwertyuio");
    bf.PutUint8(7);
    std::cout<<int(bf.size())<<std::endl;
    std::cout<<int(bf.ReadUint8())<<std::endl;
    std::cout<<int(bf.ReadUint8())<<std::endl;
    std::cout<<int(bf.ReadUint16())<<std::endl;
    std::cout<<int(bf.ReadUint32())<<std::endl;
    std::cout<<(bf.ReadString(9))<<std::endl;
    std::cout<<int(bf.ReadUint8())<<std::endl;
   return 0;
}
