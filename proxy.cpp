/* ************************************************************************
> File Name:     proxy.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月28日 星期一 12时44分56秒
> Description:   
 ************************************************************************/
#include<iostream>
using namespace std;
#include "./include/proxy.h"
Pursuit::Pursuit(SchoolGirl* mm){
	this->mm = mm;
}
Pursuit::~Pursuit(){
	delete mm;
}
void Pursuit::GiveDolls(){
	cout<<mm->getName()<<": give you a doll"<<endl;
}
void Pursuit::GiveFlowers(){
	cout<<mm->getName()<<": give you flowers"<<endl;
}
Proxy::Proxy(SchoolGirl* mm){
	gg = new Pursuit(mm);
}
Proxy::~Proxy(){
	delete gg;
}
void Proxy::GiveDolls(){
	gg->GiveDolls();
}
void Proxy::GiveFlowers(){
	gg->GiveFlowers();
}
string SchoolGirl::getName(){
	return this->name;
}
void SchoolGirl::setName(string name){
	this->name = name;
}
IGiveGift::IGiveGift(){

}
IGiveGift::~IGiveGift(){

}

int main(){
	SchoolGirl* girl = new SchoolGirl();
	girl->setName("jiaojiao");
	Proxy* proxy = new Proxy(girl);
	proxy->GiveDolls();
	proxy->GiveFlowers();

    return 0;
}
