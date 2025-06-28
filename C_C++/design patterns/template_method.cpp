#include <iostream>

// 抽象基类：定义饮料制作模板
class Beverage {
public:
    // 模板方法 (final确保子类不能修改算法结构)
    virtual void prepareBeverage() final {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) { // 钩子方法
            addCondiments();
        }
    }

    virtual ~Beverage() = default; // 关键：虚析构函数

protected:
    // 基本方法分为三类：
    // 1. 具体方法（已实现）
    void boilWater() { std::cout << "Boiling water\n"; }
    void pourInCup() { std::cout << "Pouring into cup\n"; }

    // 2. 抽象方法（必须由子类实现）
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // 3. 钩子方法（可选覆盖）
    virtual bool customerWantsCondiments() { return true; }
};

// 具体子类：茶
class Tea : public Beverage {
protected:
    void brew() override {
        std::cout << "Steeping the tea\n";
    }

    void addCondiments() override {
        std::cout << "Adding lemon\n";
    }

    // 覆盖钩子方法：20%概率不加调料
    bool customerWantsCondiments() override {
        return (rand() % 5) != 0; // 随机决定
    }
};

// 具体子类：咖啡
class Coffee : public Beverage {
protected:
    void brew() override {
        std::cout << "Dripping coffee through filter\n";
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk\n";
    }
};

// 使用示例
int main() {
    Beverage* tea = new Tea();
    Beverage* coffee = new Coffee();

    std::cout << "Making tea:\n";
    tea->prepareBeverage();

    std::cout << "\nMaking coffee:\n";
    coffee->prepareBeverage();

    delete tea;
    delete coffee;
    return 0;
}