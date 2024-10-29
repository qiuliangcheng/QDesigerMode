/* ************************************************************************
> File Name:     prototype.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月29日 星期二 11时26分56秒
> Description:原型模式是对一个类的拷贝，也许有人说那这和拷贝构造函数有什么区别呢？ 区别在于原型模式里，你可以保存基类指针，最后生成的是这个指针真正指向的子类，而拷贝构造函数你必须搞一个具体的类进去，生成的object也是固定的。通俗来说就是如何想考拷贝一个基类指针指向一个派生类对象的时候就要用原型模式   
 ************************************************************************/
#include <iostream>
using namespace std;


class Prototype{
public:
	virtual ~Prototype(){

	}
	virtual Prototype* Clone() const = 0;
protected:
	Prototype(){

	}
};

class ConcretePrototype:public Prototype{
public:
	ConcretePrototype(){

	}
	ConcretePrototype(const ConcretePrototype& cp){
		*this = cp;
		cout<<"ConcretePrototype copy ..."<<endl;
	}
	~ConcretePrototype(){

	}
	virtual Prototype* Clone() const{
		return new ConcretePrototype(*this);
	}
};


int main(){
    //这里之所以用原型 是因为我想通过基类指针去进行子类的拷贝  因为如果说我得到的是基类的指针 我没办法用基类的拷贝构造去拷贝子类
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->Clone();
	Prototype* p2 = p->Clone();
    delete p1;
    delete p2;
}

