#include <iostream>
#include <memory>
#include <vector>
#include <string>

// 接收者：真正执行操作的对象
class Light {
public:
    void turnOn() {
        state_ = true;
        std::cout << "灯光已打开" << std::endl;
    }

    void turnOff() {
        state_ = false;
        std::cout << "灯光已关闭" << std::endl;
    }

    void showState() const {
        std::cout << "当前状态: " << (state_ ? "开启" : "关闭") << std::endl;
    }

private:
    bool state_ = false;
};

// 命令接口
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string name() const = 0;
};

// 具体命令：开灯命令
class LightOnCommand : public Command {
public:
    explicit LightOnCommand(std::shared_ptr<Light> light)
        : light_(std::move(light)) {}

    void execute() override {
        light_->turnOn();
    }

    void undo() override {
        light_->turnOff();
    }

    std::string name() const override {
        return "开灯命令";
    }

private:
    std::shared_ptr<Light> light_;
};

// 具体命令：关灯命令
class LightOffCommand : public Command {
public:
    explicit LightOffCommand(std::shared_ptr<Light> light)
        : light_(std::move(light)) {}

    void execute() override {
        light_->turnOff();
    }

    void undo() override {
        light_->turnOn();
    }

    std::string name() const override {
        return "关灯命令";
    }

private:
    std::shared_ptr<Light> light_;
};

// 宏命令：组合多个命令
class MacroCommand : public Command {
public:
    void addCommand(std::shared_ptr<Command> cmd) {
        commands_.push_back(cmd);
    }

    void execute() override {
        std::cout << "开始执行宏命令" << std::endl;
        for (auto& cmd : commands_) {
            cmd->execute();
        }
    }

    void undo() override {
        std::cout << "开始撤销宏命令" << std::endl;
        for (auto it = commands_.rbegin(); it != commands_.rend(); ++it) {
            (*it)->undo();
        }
    }

    std::string name() const override {
        return "宏命令（包含" + std::to_string(commands_.size()) + "个子命令）";
    }

private:
    std::vector<std::shared_ptr<Command>> commands_;
};

// 调用者：触发命令的对象
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> cmd) {
        current_command_ = cmd;
    }

    void pressButton() {
        if (current_command_) {
            current_command_->execute();
            history_.push_back(current_command_);
            std::cout << "已执行: " << current_command_->name() << "\n" << std::endl;
        }
    }

    void pressUndo() {
        if (!history_.empty()) {
            std::cout << "撤销操作: " << history_.back()->name() << std::endl;
            history_.back()->undo();
            history_.pop_back();
        }
    }

    void showHistory() const {
        std::cout << "\n=== 操作历史 ===" << std::endl;
        for (const auto& cmd : history_) {
            std::cout << "- " << cmd->name() << std::endl;
        }
        std::cout << "================\n" << std::endl;
    }

private:
    std::shared_ptr<Command> current_command_;
    std::vector<std::shared_ptr<Command>> history_;
};

int main() {
    // 创建设备
    auto light = std::make_shared<Light>();
    light->showState();

    // 创建命令对象
    auto lightOn = std::make_shared<LightOnCommand>(light);
    auto lightOff = std::make_shared<LightOffCommand>(light);

    // 创建宏命令
    auto macroCmd = std::make_shared<MacroCommand>();
    macroCmd->addCommand(lightOn);
    macroCmd->addCommand(lightOff);
    macroCmd->addCommand(lightOn);

    // 创建遥控器
    RemoteControl remote;

    // 测试基础命令
    remote.setCommand(lightOn);
    remote.pressButton();
    light->showState();

    remote.setCommand(lightOff);
    remote.pressButton();
    light->showState();

    // 测试宏命令
    remote.setCommand(macroCmd);
    remote.pressButton();
    light->showState();

    // 展示历史记录
    remote.showHistory();

    // 测试撤销操作
    for (int i = 0; i < 3; ++i) {
        remote.pressUndo();
        light->showState();
    }

    return 0;
}