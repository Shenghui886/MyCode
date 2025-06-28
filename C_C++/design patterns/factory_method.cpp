#include <iostream>
#include <memory>

// 1. 抽象产品
class Robot {
    public:
        virtual ~Robot() = default;
        virtual void performTask() const = 0;
    };

    // 2. 具体产品
    class CleaningRobot : public Robot {
    public:
        void performTask() const override {
            std::cout << "Cleaning the floor..." << std::endl;
        }
    };

    // 3. 抽象工厂
    class RobotFactory {
    public:
        virtual ~RobotFactory() = default;
        virtual std::unique_ptr<Robot> createRobot() const = 0;
    };

    // 4. 具体工厂
    class CleaningRobotFactory : public RobotFactory {
    public:
        std::unique_ptr<Robot> createRobot() const override {
            return std::make_unique<CleaningRobot>();
        }
    };

    // 客户端代码
    int main() {
        std::unique_ptr<RobotFactory> factory = std::make_unique<CleaningRobotFactory>();
        auto robot = factory->createRobot();
        robot->performTask();
        return 0;
    }