#include <iostream>
#include <string>
using namespace std;

//construcion desiger 
class USB{
public:
    virtual void charge()=0;
};
class TypeC{
public:
    virtual void chargeWithTypeC()=0;
};

class TypeCAdapter : public USB {
private:
    TypeC* typeC;

public:
    TypeCAdapter(TypeC* typeC) : typeC(typeC) {}

    void charge() override {
        typeC->chargeWithTypeC();
    }
};
class NewComputer : public TypeC {
public:
    void chargeWithTypeC() override {
        std::cout << "TypeC" << std::endl;
    }
};

// 适配器充电器类，使用 USB 接口
class AdapterCharger : public USB {
public:
    void charge() override {
        std::cout << "USB Adapter" << std::endl;
    }
};
int main() {
    USB *usb1=new AdapterCharger();
    usb1->charge();
    TypeC *type=new NewComputer();
    USB *usb2=new TypeCAdapter(type);
    usb2->charge();

    return 0;
}
