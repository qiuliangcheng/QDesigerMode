/* ************************************************************************
> File Name:     strategy.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月28日 星期一 14时39分37秒
> Description:策略模式定义了算法家族，分别封装起来，让他们之间可以相互替换，此模式让算法的变化不会影响到使用算法的客户   
 ************************************************************************/
//通过context对不同的策略进行封装，减小算法的改变对客户端的影响

#include <iostream>
#include <string>
using namespace std;

class Strategy{
public:
	Strategy(){

	}
	virtual ~Strategy(){

	}
	virtual void algorithmInterface(){

	}
};
class ConcreteStrategyA: public Strategy{
public:
	ConcreteStrategyA():Strategy(){

	}
	virtual ~ConcreteStrategyA(){

	}
	virtual void algorithmInterface(){
		cout<<"algorithmInterfaceA"<<endl;
	}
};
class ConcreteStrategyB: public Strategy{
public:
	ConcreteStrategyB(): Strategy(){

	}
	virtual ~ConcreteStrategyB(){

	}
	virtual void algorithmInterface(){
		cout<<"algorithmInterfaceB"<<endl;

	}
};
// 上下文
class Context{
public:
	Context(Strategy* strategy){
		this->strategy = strategy;
	}
	void contextInterface(){
		this->strategy->algorithmInterface();
	}
private:
	Strategy* strategy;
};
int main(){
	Context* context;
	context = new Context(new ConcreteStrategyA());
	context->contextInterface();
	context = new Context(new ConcreteStrategyB());
	context->contextInterface();
}
