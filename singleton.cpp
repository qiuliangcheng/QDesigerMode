#include <iostream>

using namespace std;
//懒汉模式
class Singleton{
public:
    static Singleton* getInstance(){
        static Singleton st;
        return &st;
    }

private:
    Singleton()=default;

};

//饿汉模式
class Singleton2 {
public:
	static Singleton2* getInstance() {
	    return ptr;
    }
private:
	static Singleton2* ptr;
private:
    Singleton2() = default;
    Singleton2(const Singleton2&) = delete;
    Singleton2& operator=(const Singleton2&) = delete;
};
Singleton2* Singleton2::ptr = new Singleton2;


int main(){
    Singleton* sgn1 = Singleton::getInstance();
	Singleton* sgn2 = Singleton::getInstance();
    cout<<sgn1<<"   "<<sgn2<<endl;
    Singleton2* sgn3 = Singleton2::getInstance();
	Singleton2* sgn4 = Singleton2::getInstance();
    cout<<sgn3<<"   "<<sgn4<<endl;
}
