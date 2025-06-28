#include <iostream>
#include <memory>
#include <string>

using namespace std;

// 抽象组件：咖啡基类
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// 具体组件：基础咖啡
class SimpleCoffee : public Coffee {
public:
    string getDescription() const override {
        return "Simple Coffee";
    }

    double getCost() const override {
        return 3.0;
    }
};

// 装饰器基类
class CoffeeDecorator : public Coffee {
protected:
    unique_ptr<Coffee> decoratedCoffee;
public:
    explicit CoffeeDecorator(unique_ptr<Coffee> coffee)
        : decoratedCoffee(move(coffee)) {}

    string getDescription() const override {
        return decoratedCoffee->getDescription();
    }

    double getCost() const override {
        return decoratedCoffee->getCost();
    }
};

// 具体装饰器：牛奶
class MilkDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    string getDescription() const override {
        return CoffeeDecorator::getDescription() + " + Milk";
    }

    double getCost() const override {
        return CoffeeDecorator::getCost() + 0.5;
    }
};

// 具体装饰器：糖
class SugarDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    string getDescription() const override {
        return CoffeeDecorator::getDescription() + " + Sugar";
    }

    double getCost() const override {
        return CoffeeDecorator::getCost() + 0.2;
    }
};

// 具体装饰器：奶油
class WhippedCreamDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    string getDescription() const override {
        return CoffeeDecorator::getDescription() + " + Whipped Cream";
    }

    double getCost() const override {
        return CoffeeDecorator::getCost() + 1.2;
    }
};

// 客户端代码
int main() {
    // 创建基础咖啡
    auto coffee = make_unique<SimpleCoffee>();
    cout << "Basic coffee: " << coffee->getDescription()
         << ", Cost: $" << coffee->getCost() << endl;

    // 第一次装饰：加牛奶和糖
    auto coffeeWithMilkAndSugar = make_unique<MilkDecorator>(
        make_unique<SugarDecorator>(
            move(coffee)
        )
    );
    cout << "After first decoration: " << coffeeWithMilkAndSugar->getDescription()
         << ", Cost: $" << coffeeWithMilkAndSugar->getCost() << endl;

    // 第二次装饰：再加奶油
    auto deluxeCoffee = make_unique<WhippedCreamDecorator>(
        move(coffeeWithMilkAndSugar)
    );
    cout << "After second decoration: " << deluxeCoffee->getDescription()
         << ", Cost: $" << deluxeCoffee->getCost() << endl;

    // 动态组合装饰顺序
    auto customCoffee = make_unique<WhippedCreamDecorator>(
        make_unique<MilkDecorator>(
            make_unique<SugarDecorator>(
                make_unique<SimpleCoffee>()
            )
        )
    );
    cout << "\nCustom combination: " << customCoffee->getDescription()
         << ", Cost: $" << customCoffee->getCost() << endl;

    return 0;
}
