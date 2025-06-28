#include <iostream>
using namespace std;

// 实现接口：绘图方式（Implementor）
class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() = default;  // 虚析构确保正确释放资源[6](@ref)
};

// 具体实现：屏幕绘制（ConcreteImplementorA）
class ScreenDrawingAPI : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        cout << "屏幕绘制圆形：位置(" << x << "," << y << "), 半径" << radius << endl;
    }
};

// 具体实现：打印机绘制（ConcreteImplementorB）← 原示例缺失的部分
class PrinterDrawingAPI : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        cout << "打印机绘制圆形：位置(" << x << "," << y << "), 半径" << radius << endl;
    }
};

// 抽象类：图形（Abstraction）
class Shape {
protected:
    DrawingAPI* drawingAPI;  // 桥接关键：持有实现接口的指针[6,2](@ref)
public:
    Shape(DrawingAPI* api) : drawingAPI(api) {}
    virtual void draw() = 0;
    virtual void resize(double factor) = 0;  // 扩展操作示例[6](@ref)
    virtual ~Shape() = default;
};

// 扩展抽象类：圆形（RefinedAbstraction）
class Circle : public Shape {
    double x, y, radius;
public:
    Circle(double x, double y, double r, DrawingAPI* api)
        : Shape(api), x(x), y(y), radius(r) {}

    void draw() override {
        drawingAPI->drawCircle(x, y, radius);  // 委托具体实现[6,5](@ref)
    }

    void resize(double factor) override {
        radius *= factor;  // 抽象层的扩展功能[6](@ref)
    }
};

// 客户端使用（完整版）
int main() {
    // 创建两种绘图方式
    DrawingAPI* screenAPI = new ScreenDrawingAPI();
    DrawingAPI* printerAPI = new PrinterDrawingAPI();

    // 创建不同绘制方式的圆形
    Shape* circle1 = new Circle(1,2,3, screenAPI);
    Shape* circle2 = new Circle(5,6,4, printerAPI);

    circle1->draw();  // 屏幕绘制
    circle2->draw();  // 打印机绘制

    // 测试扩展功能
    circle1->resize(2.0);
    circle1->draw();  // 输出更新后的尺寸

    // 释放资源（建议使用智能指针优化，此处为演示原始指针管理）
    delete screenAPI;
    delete printerAPI;
    delete circle1;
    delete circle2;
    return 0;
}
