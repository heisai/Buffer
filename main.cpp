#include <iostream>
#include<algorithm>
#include"Buffer.h"
using namespace std;

int main()
{

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
    auto it = std::find(bf.begin(),bf.end(),'q');
    std::cout<<"iter:"<<*it<<endl;
   return 0;
}
