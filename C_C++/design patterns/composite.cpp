#include <iostream>
#include <vector>
#include <algorithm>

// 抽象组件接口（透明模式）
class Component {
public:
    virtual ~Component() = default;
    virtual void operation() const = 0;
    virtual void add(Component* component) {}     // 默认空实现
    virtual void remove(Component* component) {}  // 默认空实现
    virtual Component* getChild(int index) { return nullptr; }
};

// 叶子节点实现
class Leaf : public Component {
public:
    explicit Leaf(const std::string& name) : name_(name) {}

    void operation() const override {
        std::cout << "Leaf [" << name_ << "] operation" << std::endl;
    }

private:
    std::string name_;
};

// 组合节点实现
class Composite : public Component {
public:
    explicit Composite(const std::string& name) : name_(name) {}

    ~Composite() {
        for (auto& child : children_) {
            delete child;
        }
    }

    void operation() const override {
        std::cout << "Composite [" << name_ << "] operation" << std::endl;
        for (const auto& child : children_) {
            child->operation();  // 递归调用
        }
    }

    void add(Component* component) override {
        children_.push_back(component);
    }

    void remove(Component* component) override {
        auto it = std::find(children_.begin(), children_.end(), component);
        if (it != children_.end()) {
            delete *it;  // 释放内存
            children_.erase(it);
        }
    }

    Component* getChild(int index) override {
        if (index >= 0 && index < children_.size()) {
            return children_[index];
        }
        return nullptr;
    }

private:
    std::vector<Component*> children_;
    std::string name_;
};

// 客户端使用示例
int main() {
    // 创建树形结构
    Composite* root = new Composite("Root");
    root->add(new Leaf("Leaf A"));
    root->add(new Leaf("Leaf B"));

    Composite* branch = new Composite("Branch 1");
    branch->add(new Leaf("Leaf C"));
    branch->add(new Leaf("Leaf D"));

    Composite* subBranch = new Composite("Sub Branch");
    subBranch->add(new Leaf("Leaf E"));
    branch->add(subBranch);

    root->add(branch);

    // 统一操作
    root->operation();

    // 内存清理
    delete root;
    return 0;
}
