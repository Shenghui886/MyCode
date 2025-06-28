#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;

// 抽象原型
class Graphic {
public:
    virtual unique_ptr<Graphic> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Graphic() = default;
};

// 具体原型：圆形
class Circle : public Graphic {
    double radius;
public:
    Circle(double r) : radius(r) {}
    unique_ptr<Graphic> clone() const override {
        return make_unique<Circle>(*this);
    }
    void draw() const override {
        cout << "Drawing circle, radius=" << radius << endl;
    }
};

// 原型管理器
class PrototypeManager {
    unordered_map<string, unique_ptr<Graphic>> prototypes;
public:
    void registerProto(const string& key, unique_ptr<Graphic> proto) {
        prototypes[key] = move(proto);
    }
    unique_ptr<Graphic> create(const string& key) {
        return prototypes[key]->clone();
    }
};

int main() {
    PrototypeManager manager;
    manager.registerProto("default_circle", make_unique<Circle>(5.0));

    auto circle1 = manager.create("default_circle");
    auto circle2 = manager.create("default_circle");
    circle1->draw();  // Output: Drawing circle, radius=5
    circle2->draw();  // Output: Drawing circle, radius=5
    return 0;
}
