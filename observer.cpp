/* ************************************************************************
> File Name:     observer.cpp
> Author:         qlc
> WeChat:           a2744561792
> Created Time:  2024年10月28日 星期一 12时20分36秒
> Description    belong to publish->subcribe model  one -> mutil
观察者模式（发布-订阅模式）属于行为型模式，定义了一种一对多的依赖关系，让多个观察者对象同时监听一个主题对象，当主题对象的状态发生变化时，所有依赖于它的观察者都得到通知并被自动更新。
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Observer {
public:
    virtual void update(int hour) = 0;
    virtual ~Observer() = default; // 添加虚析构函数
};

class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default; // 添加虚析构函数
};

// 具体主题实现
class Clock : public Subject {
private:
    std::vector<Observer*> observers;
    int hour;

public:
    Clock() : hour(0) {}

    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(hour);
        }
    }

    // 添加获取观察者的函数
    const std::vector<Observer*>& getObservers() const {
        return observers;
    }

    void tick() {
        hour = (hour + 1) % 24; // 模拟时间的推移
        notifyObservers();
    }
};


// 具体观察者实现
class Student : public Observer {
private:
    std::string name;

public:
    Student(const std::string& name) : name(name) {}

    void update(int hour) override {
        std::cout << name << " " << hour << std::endl;
    }
};
int main() {
    // 读取学生数量
    int N=5;
    // 创建时钟
    Clock clock;
    // 注册学生观察者
    for (int i = 0; i < N; i++) {
        std::string studentName="Student:"+std::to_string(i);
        clock.registerObserver(new Student(studentName));
    }
    // 读取时钟更新次数
    int updates=5;
    // 模拟时钟每隔一个小时更新一次
    for (int i = 0; i < updates; i++) {
        clock.tick();
    }

    // 释放动态分配的观察者对象
    for (Observer* observer : clock.getObservers()) {
        delete observer;
    }

    return 0;
}
