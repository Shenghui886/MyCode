#include <iostream>
#include <vector>
#include <memory>

// 前向声明
class ConcreteElementA;
class ConcreteElementB;

// 1. 访问者抽象接口
class Visitor {
public:
    virtual void visit(ConcreteElementA* element) = 0;
    virtual void visit(ConcreteElementB* element) = 0;
    virtual ~Visitor() = default;
};

// 2. 元素抽象接口
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() = default;
};

// 3. 具体元素实现
class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(this);  // 第一次分派
    }

    std::string featureA() const {
        return "ConcreteElementA Special Feature";
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(this);  // 第一次分派
    }

    int calculate() const {
        return 2024;
    }
};

// 4. 具体访问者实现
class DiagnosticVisitor : public Visitor {
public:
    void visit(ConcreteElementA* element) override {
        std::cout << "[Diagnostic] ElementA status: "
                  << element->featureA() << "\n";
    }

    void visit(ConcreteElementB* element) override {
        std::cout << "[Diagnostic] ElementB calculation: "
                  << element->calculate() << "\n";
    }
};

class ExportVisitor : public Visitor {
public:
    void visit(ConcreteElementA* element) override {
        std::cout << "Exporting ElementA: "
                  << element->featureA() << " -> CSV\n";
    }

    void visit(ConcreteElementB* element) override {
        std::cout << "Exporting ElementB: "
                  << element->calculate() << " -> JSON\n";
    }
};

// 5. 对象结构容器
class ObjectStructure {
    std::vector<std::unique_ptr<Element>> elements;

public:
    void addElement(Element* element) {
        elements.emplace_back(element);
    }

    void traverse(Visitor& visitor) {
        for (auto& elem : elements) {
            elem->accept(visitor);  // 触发双分派
        }
    }
};

int main() {
    ObjectStructure system;

    // 构建对象结构
    system.addElement(new ConcreteElementA);
    system.addElement(new ConcreteElementB);
    system.addElement(new ConcreteElementA);
    system.addElement(new ConcreteElementB);

    // 使用不同访问者
    DiagnosticVisitor diag;
    ExportVisitor exportVisitor;

    std::cout << "=== Running Diagnostic ===" << "\n";
    system.traverse(diag);

    std::cout << "\n=== Exporting Data ===" << "\n";
    system.traverse(exportVisitor);

    return 0;
}