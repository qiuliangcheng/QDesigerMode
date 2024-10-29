/* ************************************************************************
> File Name:     include/proxy.h
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月28日 星期一 12时43分44秒
> Description:   
 ************************************************************************/
#include<iostream>
using namespace std;
class SchoolGirl{
public:
	string getName();
	void setName(string name);
private:
	string name;
};
class IGiveGift{
public:
	IGiveGift();
	virtual ~IGiveGift();
	virtual void GiveDolls()=0;
	virtual void GiveFlowers()=0;
};
class Pursuit: public IGiveGift{
public:
	Pursuit(SchoolGirl* mm);
	virtual ~Pursuit();
	virtual void GiveDolls();
	virtual void GiveFlowers();
private:
	SchoolGirl* mm;
};
class Proxy: public IGiveGift{
public:
	Proxy(SchoolGirl* mm);
	virtual ~Proxy();
	virtual void GiveDolls();
	virtual void GiveFlowers();
private:
	Pursuit* gg;
};
