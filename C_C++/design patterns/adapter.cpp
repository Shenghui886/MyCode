// #include <iostream>
// #include <memory>

// // -------------------------------
// // 旧接口类（Adaptee）
// class OldPrinter {
// public:
//     void printOld() {
//         std::cout << "旧式打印机输出：黑白文字" << std::endl;
//     }
// };

// // -------------------------------
// // 新接口抽象类（Target）
// class NewPrinter {
// public:
//     virtual void printNew() = 0;
//     virtual ~NewPrinter() = default;
// };

// // -------------------------------
// // 适配器类（对象适配器）
// class PrinterAdapter : public NewPrinter {
// private:
//     std::unique_ptr<OldPrinter> oldPrinter; // 组合旧类对象
// public:
//     PrinterAdapter() : oldPrinter(std::make_unique<OldPrinter>()) {}

//     void printNew() override {
//         std::cout << "适配器调用旧接口..." << std::endl;
//         oldPrinter->printOld(); // 委托旧类的方法
//     }
// };

// // -------------------------------
// // 客户端调用
// int main() {
//     std::unique_ptr<NewPrinter> printer = std::make_unique<PrinterAdapter>();
//     printer->printNew(); // 输出：适配器调用旧接口... 旧式打印机输出：黑白文字
//     return 0;
// }

#include <iostream>

// -------------------------------
// 被适配者类（Adaptee）
class LegacyOutlet {
public:
    void supplyPower() {
        std::cout << "传统电源供电：220V 交流电" << std::endl;
    }
};

// -------------------------------
// 目标接口（Target）
class USBOutlet {
public:
    virtual void chargeViaUSB() = 0;
    virtual ~USBOutlet() = default;
};

// -------------------------------
// 适配器类（类适配器，通过多重继承）
class USBAdapter : public USBOutlet, private LegacyOutlet {
public:
    void chargeViaUSB() override {
        std::cout << "USB适配器转换中..." << std::endl;
        supplyPower(); // 直接调用继承的旧方法
    }
};

// -------------------------------
// 客户端调用
int main() {
    USBOutlet* adapter = new USBAdapter();
    adapter->chargeViaUSB(); // 输出：USB适配器转换中... 传统电源供电：220V 交流电
    delete adapter;
    return 0;
}
