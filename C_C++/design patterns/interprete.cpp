#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

// 抽象表达式接口
class Expression {
public:
    virtual int interpret(std::unordered_map<char, int>& context) = 0;
    virtual ~Expression() = default;
};

// 终结符表达式：整数常量
class Number : public Expression {
    int value;
public:
    explicit Number(int v) : value(v) {}
    int interpret(std::unordered_map<char, int>&) override {
        return value;
    }
};

// 终结符表达式：变量
class Variable : public Expression {
    char name;
public:
    explicit Variable(char c) : name(c) {}
    int interpret(std::unordered_map<char, int>& context) override {
        if (context.find(name) == context.end()) {
            throw std::runtime_error("Undefined variable: " + std::string(1, name));
        }
        return context[name];
    }
};

// 非终结符表达式基类
class BinaryOperation : public Expression {
protected:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    BinaryOperation(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {}
};

// 加法运算
class Add : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    int interpret(std::unordered_map<char, int>& context) override {
        return left->interpret(context) + right->interpret(context);
    }
};

// 减法运算
class Subtract : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    int interpret(std::unordered_map<char, int>& context) override {
        return left->interpret(context) - right->interpret(context);
    }
};

// 乘法运算
class Multiply : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    int interpret(std::unordered_map<char, int>& context) override {
        return left->interpret(context) * right->interpret(context);
    }
};

// 除法运算
class Divide : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    int interpret(std::unordered_map<char, int>& context) override {
        int divisor = right->interpret(context);
        if (divisor == 0) throw std::runtime_error("Division by zero");
        return left->interpret(context) / divisor;
    }
};

// 布尔表达式
class BooleanExpr : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    std::string op;

public:
    BooleanExpr(std::unique_ptr<Expression> l,
               std::unique_ptr<Expression> r,
               std::string o)
        : left(std::move(l)), right(std::move(r)), op(o) {}

    int interpret(std::unordered_map<char, int>& context) override {
        int lval = left->interpret(context);
        int rval = right->interpret(context);

        if(op == ">") return lval > rval;
        if(op == "<") return lval < rval;
        if(op == "==") return lval == rval;
        throw std::runtime_error("Unknown operator: " + op);
    }
};

// 变量赋值
class Assign : public Expression {
    char name;
    std::unique_ptr<Expression> value;

public:
    Assign(char n, std::unique_ptr<Expression> v)
        : name(n), value(std::move(v)) {}

    int interpret(std::unordered_map<char, int>& context) override {
        int result = value->interpret(context);
        context[name] = result;
        return result;
    }
};

// 表达式构建工厂
class ExpressionFactory {
public:
    static std::unique_ptr<Expression> create(char c) {
        return std::make_unique<Variable>(c);
    }

    static std::unique_ptr<Expression> create(int n) {
        return std::make_unique<Number>(n);
    }

    template<typename T, typename... Args>
    static std::unique_ptr<Expression> create(Args&&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
};

int main() {
    std::unordered_map<char, int> context;

    try {
        // 构建并执行赋值表达式：x = 10
        auto assign_x = ExpressionFactory::create<Assign>(
            'x',
            ExpressionFactory::create(10)
        );
        assign_x->interpret(context);
        std::cout << "x = " << context['x'] << std::endl;

        // 构建复杂表达式：(x + 5) * 3 - 2
        auto complex_expr = ExpressionFactory::create<Subtract>(
            ExpressionFactory::create<Multiply>(
                ExpressionFactory::create<Add>(
                    ExpressionFactory::create('x'),
                    ExpressionFactory::create(5)
                ),
                ExpressionFactory::create(3)
            ),
            ExpressionFactory::create(2)
        );

        int result = complex_expr->interpret(context);
        std::cout << "(x+5)*3-2 = " << result << std::endl;

        // 布尔表达式测试：x > 15
        auto bool_expr = ExpressionFactory::create<BooleanExpr>(
            ExpressionFactory::create('x'),
            ExpressionFactory::create(15),
            ">"
        );

        std::cout << "x > 15? "
                  << (bool_expr->interpret(context) ? "true" : "false")
                  << std::endl;

        // 测试除法
        auto divide_expr = ExpressionFactory::create<Divide>(
            ExpressionFactory::create(20),
            ExpressionFactory::create(0)  // 这里会抛出异常
        );
        divide_expr->interpret(context);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}