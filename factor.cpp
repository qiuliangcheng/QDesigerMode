/* ************************************************************************
> File Name:     factor.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月27日 星期日 23时28分32秒
> Description:  factor desiger  
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;
 
class Computer{
public:
    virtual void price()=0;
    virtual void description()=0;
    virtual ~Computer(){

    }
};

class Laptop: public Computer
{
public:
	void price()
	{
		cout<<"4000$"<<endl;
	}
	void description()
	{
		cout<<"Laptops are mobile, portable and multimedia"<<endl;
	}
	virtual ~Laptop() {};
};

class Desktop: public Computer
{
public:
	void price()
	{
		cout<<"5000$"<<endl;
	}
	void description()
	{
		cout<<"Desktops are fixed"<<endl;
	}
	virtual ~Desktop(){

	}
};

class ComputerFactory
{
public:
	static Computer *NewComputer(const std::string &description)
	{
		if(description == "laptop")
			return new Laptop;
		if(description == "desktop")
			return new Desktop;
		return NULL;
	}
};

class ComputerMultiFactory {
public:
  	Computer *NewMultiLaptop () {
    	return new Laptop();
  	}
  	Computer *NewMultiDesktop() {
    	return new Desktop();
  	}
};

class ComputerStaticFactory {
public:
  	static Computer *NewStaticLaptop() {
    	return new Laptop();
  	}
  	static Computer *NewStaticDesktop() {
    	return new Desktop();
  	}
};

int main()
{
	Computer *computer1 = ComputerFactory::NewComputer("laptop");
	computer1->price();
	computer1->description();
	Computer *computer2 = ComputerFactory::NewComputer("desktop");
	computer2->price();
	computer2->description();
  	cout << "----------" << endl;

	ComputerMultiFactory *factory = new ComputerMultiFactory();
	Computer *multiLaptop = factory->NewMultiLaptop();
	multiLaptop->price();
	multiLaptop->description();
	cout << "----------" << endl;

	Computer *staticLaptop = ComputerStaticFactory::NewStaticLaptop();
	Computer *staticLaptop2 = ComputerStaticFactory::NewStaticLaptop();
    cout<<staticLaptop<<"    "<<staticLaptop2<<endl;
    cout<<"=========================="<<endl;
    staticLaptop->price();
	staticLaptop->description();
	cout << "----------" << endl;
}
