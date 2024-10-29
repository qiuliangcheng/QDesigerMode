/* ************************************************************************
> File Name:     constructor.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月29日 星期二 12时32分54秒
> Description: 建造者模式
>>> 实现步骤：
   1、提供抽象建造者类，为创建产品各个部分统一接口
   2、提供具体建造者类，具体实现抽象建造者的各个接口
   3、提供抽象产品类
   4、提供具体产品类
   5、提供一个指挥类 负责安排和调度复杂对象的各个建造过程
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;
//抽象产品类
class AbstractProduct{
public:
    virtual ~AbstractProduct(){

    }
    virtual void setKeyBoard(string name)=0;
    virtual void show()=0;
};

//具体产品类
class Computer :public AbstractProduct{
public:
    Computer(){

    }
    virtual void setKeyBoard(string name) override {
        m_name=name;
    }
    virtual void show() override{
        cout<<m_name<<endl;
    }
private:
    string m_name;

};
//抽象建造者类
class AbstractBuilder{
public:
    AbstractBuilder():pro(new Computer()){
        
    }
    virtual void BuildkeyBoard(string name)=0;
    AbstractProduct * getProduct()const {
        return pro;
    }
protected:
    AbstractProduct *pro;

};
//具体建造者类
class ConcreteBuilder:public AbstractBuilder{
public:
    void BuildkeyBoard(string name){
        pro->setKeyBoard(name);
    }
};
//指挥者
class Director{
public:
    //让谁去创建产品
    Director(AbstractBuilder* build){
        builder=build;
    }
    AbstractProduct* CrateProduct(string keyname){
        builder->BuildkeyBoard(keyname);
        return builder->getProduct();
    }
private:
    AbstractBuilder *builder;

};


int main(){
    AbstractBuilder *build=new ConcreteBuilder();
    Director *dir=new Director(build);
    AbstractProduct *pro=dir->CrateProduct("键盘");
    pro->show();
    delete dir;
    delete pro;
    delete build;
    return 0;
}



