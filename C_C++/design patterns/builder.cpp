#include <iostream>
#include <string>

// 产品类：Computer
class Computer {
public:
    void setCPU(const std::string& cpu) { cpu_ = cpu; }
    void setRAM(const std::string& ram) { ram_ = ram; }
    void setSSD(const std::string& ssd) { ssd_ = ssd; }

    void showSpec() const {
        std::cout << "CPU: " << cpu_ << "\n"
                  << "RAM: " << ram_ << "\n"
                  << "SSD: " << ssd_ << "\n";
    }

private:
    std::string cpu_;
    std::string ram_;
    std::string ssd_;
};

// 抽象建造者接口
class ComputerBuilder {
public:
    virtual ~ComputerBuilder() = default;
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildSSD() = 0;
    virtual Computer* getResult() = 0;
};

// 具体建造者：游戏电脑
class GamingComputerBuilder : public ComputerBuilder {
public:
    GamingComputerBuilder() { computer_ = new Computer(); }

    void buildCPU() override { computer_->setCPU("Intel i9"); }
    void buildRAM() override { computer_->setRAM("32GB DDR5"); }
    void buildSSD() override { computer_->setSSD("1TB NVMe"); }

    Computer* getResult() override { return computer_; }

private:
    Computer* computer_;
};

// 指挥者类
class Director {
public:
    void setBuilder(ComputerBuilder* builder) { builder_ = builder; }

    Computer* construct() {
        builder_->buildCPU();
        builder_->buildRAM();
        builder_->buildSSD();
        return builder_->getResult();
    }

private:
    ComputerBuilder* builder_;
};

// 客户端使用
int main() {
    Director director;
    GamingComputerBuilder gamingBuilder;

    director.setBuilder(&gamingBuilder);
    Computer* gamingPC = director.construct();

    std::cout << "Gaming Computer Specs:\n";
    gamingPC->showSpec();

    delete gamingPC;  // 实际开发中建议用智能指针
    return 0;
}

