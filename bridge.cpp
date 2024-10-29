/* ************************************************************************
> File Name:     bridge.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月28日 星期一 14时58分05秒
> Description:   
 ************************************************************************/
#include <iostream>
using namespace std;
class Handsetsoft{
public:
	Handsetsoft(){

	}
	virtual ~Handsetsoft(){

	}
	virtual void run()=0;
};
class HandsetGame:public Handsetsoft{
public:
	HandsetGame():Handsetsoft(){

	}
	virtual ~HandsetGame(){

	}
	virtual void run(){
		cout<<"run game"<<endl;
	}

};
class HandsetAddressList: public Handsetsoft{
public:
	HandsetAddressList():Handsetsoft(){

	}
	virtual ~HandsetAddressList(){

	}
	virtual void run(){
		cout<<"run addressList"<<endl;
	}
};



class HandsetBrand
{
public:
	HandsetBrand(){

	}
	virtual ~HandsetBrand(){
		delete soft;
	}
	virtual void setHandsetsoft(Handsetsoft* soft){
		this->soft = soft;

	}
	virtual void run(){

	}
protected:
	Handsetsoft* soft;
};

class Iphone: public HandsetBrand{
public:
	Iphone():HandsetBrand(){

	}
	virtual ~Iphone(){

	}
	virtual void run(){
		soft->run();
	}
};


class Android: public HandsetBrand{
public:
	Android():HandsetBrand(){

	}
	virtual ~Android(){

	}
	virtual void run(){
		soft->run();
	}
};
int main(){
	HandsetBrand* iphone = new Iphone();
	iphone->setHandsetsoft(new HandsetGame());
	iphone->run();
	HandsetBrand* android = new Android();
	android->setHandsetsoft(new HandsetAddressList());
	android->run();
}
