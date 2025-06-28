// #include <iostream>
// #include <memory>
// #include <vector>
// #include <mutex>
// #include <string>

// // 前置声明
// class Colleague;

// // 抽象中介者
// class Mediator {
// public:
//     virtual void addColleague(std::shared_ptr<Colleague> colleague) = 0;
//     virtual void send(const std::shared_ptr<Colleague>& sender, const std::string& msg) = 0;
//     virtual ~Mediator() = default;
// };

// // 抽象同事类（启用shared_from_this）
// class Colleague : public std::enable_shared_from_this<Colleague> {
// protected:
//     std::shared_ptr<Mediator> mediator_;
//     std::string name_;

// public:
//     Colleague(std::shared_ptr<Mediator> mediator, const std::string& name)
//         : mediator_(mediator), name_(name) {}

//     virtual void receive(const std::string& msg) const = 0;
//     virtual void send(const std::string& msg) = 0;  // 修改为非const以使用shared_from_this
//     virtual ~Colleague() = default;

//     std::string getName() const { return name_; }
// };

// // 具体中介者（线程安全实现）
// class ChatRoom : public Mediator {
// private:
//     std::vector<std::weak_ptr<Colleague>> colleagues_;
//     mutable std::mutex mtx_;

// public:
//     void addColleague(std::shared_ptr<Colleague> colleague) override {
//         std::lock_guard<std::mutex> lock(mtx_);
//         colleagues_.emplace_back(colleague);
//     }

//     void send(const std::shared_ptr<Colleague>& sender, const std::string& msg) override {
//         std::lock_guard<std::mutex> lock(mtx_);

//         std::cout << "\n[System] Message from " << sender->getName()
//                   << " to " << (colleagues_.size()-1) << " participants\n";

//         for (auto& weak_colleague : colleagues_) {
//             if (auto colleague = weak_colleague.lock()) {
//                 if (colleague != sender) {
//                     colleague->receive(msg);
//                 }
//             }
//         }
//     }
// };

// // 具体同事类
// class User : public Colleague {
// public:
//     User(std::shared_ptr<Mediator> mediator, const std::string& name)
//         : Colleague(mediator, name)
//     {
//         // 自动注册到中介者
//         mediator_->addColleague(shared_from_this());
//     }

//     void receive(const std::string& msg) const override {
//         std::cout << "[" << name_ << "] Received: " << msg << std::endl;
//     }

//     void send(const std::string& msg) override {
//         mediator_->send(shared_from_this(), msg);
//     }

//     // 扩展功能：定向发送
//     void sendTo(const std::string& target, const std::string& msg) {
//         // 可通过中介者实现定向消息逻辑
//         std::cout << "[" << name_ << "] -> [" << target << "]: " << msg << std::endl;
//         mediator_->send(shared_from_this(), "[DM]" + msg);  // 示例实现
//     }
// };

// int main() {
//     auto chatroom = std::make_shared<ChatRoom>();

//     auto alice = std::make_shared<User>(chatroom, "Alice");
//     auto bob = std::make_shared<User>(chatroom, "Bob");
//     auto charlie = std::make_shared<User>(chatroom, "Charlie");

//     // 测试广播消息
//     alice->send("Hello everyone!");
//     bob->send("Meeting starts now!");

//     // 测试定向消息
//     charlie->sendTo("Alice", "Can we talk privately?");

//     // 测试新成员加入
//     auto dave = std::make_shared<User>(chatroom, "Dave");
//     dave->send("Hi all, I'm new here!");

//     return 0;
// }

// /* 输出示例：
// [System] Message from Alice to 2 participants
// [Bob] Received: Hello everyone!
// [Charlie] Received: Hello everyone!

// [System] Message from Bob to 2 participants
// [Alice] Received: Meeting starts now!
// [Charlie] Received: Meeting starts now!

// [Charlie] -> [Alice]: Can we talk privately?
// [System] Message from Charlie to 3 participants
// [Alice] Received: [DM]Can we talk privately?
// [Bob] Received: [DM]Can we talk privately?
// [Dave] Received: [DM]Can we talk privately?

// [System] Message from Dave to 3 participants
// [Alice] Received: Hi all, I'm new here!
// [Bob] Received: Hi all, I'm new here!
// [Charlie] Received: Hi all, I'm new here!
// */


// #include <iostream>
// #include <memory>
// #include <vector>
// #include <mutex>
// #include <string>

// class Colleague;
// class Mediator;

// // 抽象中介者
// class Mediator {
// public:
//     virtual void addColleague(std::shared_ptr<Colleague> colleague) = 0;
//     virtual void send(const std::shared_ptr<Colleague>& sender,
//                      const std::string& msg) = 0;
//     virtual ~Mediator() = default;
// };

// // 抽象同事类
// class Colleague : public std::enable_shared_from_this<Colleague> {
// protected:
//     std::shared_ptr<Mediator> mediator_;
//     std::string name_;

// public:
//     Colleague(std::shared_ptr<Mediator> mediator, const std::string& name)
//         : mediator_(mediator), name_(name) {}

//     virtual void receive(const std::string& msg) const = 0;
//     virtual void send(const std::string& msg) = 0;
//     virtual ~Colleague() = default;

//     std::string getName() const { return name_; }
// };

// // 具体中介者
// class ChatRoom : public Mediator {
// private:
//     std::vector<std::weak_ptr<Colleague>> colleagues_;
//     mutable std::mutex mtx_;

// public:
//     void addColleague(std::shared_ptr<Colleague> colleague) override {
//         std::lock_guard<std::mutex> lock(mtx_);
//         colleagues_.emplace_back(colleague);
//     }

//     void send(const std::shared_ptr<Colleague>& sender,
//              const std::string& msg) override {
//         std::lock_guard<std::mutex> lock(mtx_);

//         for (auto& weak_colleague : colleagues_) {
//             if (auto colleague = weak_colleague.lock()) {
//                 if (colleague != sender) {
//                     colleague->receive(msg);
//                 }
//             }
//         }
//     }
// };

// // 具体同事类
// class User : public Colleague {
//     // 私有构造函数
//     User(std::shared_ptr<Mediator> mediator, const std::string& name)
//         : Colleague(mediator, name) {}

// public:
//     // 工厂方法
//     static std::shared_ptr<User> create(
//         std::shared_ptr<Mediator> mediator,
//         const std::string& name
//     ) {
//         auto ptr = std::shared_ptr<User>(new User(mediator, name));
//         ptr->mediator_->addColleague(ptr);
//         return ptr;
//     }

//     void receive(const std::string& msg) const override {
//         std::cout << "[" << name_ << "] Received: " << msg << std::endl;
//     }

//     void send(const std::string& msg) override {
//         mediator_->send(shared_from_this(), msg);
//     }
// };

// int main() {
//     auto chatroom = std::make_shared<ChatRoom>();

//     auto alice = User::create(chatroom, "Alice");
//     auto bob = User::create(chatroom, "Bob");
//     auto charlie = User::create(chatroom, "Charlie");

//     alice->send("Hello World!");
//     bob->send("Hi there!");

//     return 0;
// }

/* 输出：
[Bob] Received: Hello World!
[Charlie] Received: Hello World!
[Alice] Received: Hi there!
[Charlie] Received: Hi there!
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 前向声明解决循环依赖
class SmartDevice;

// 抽象中介者（包含设备管理接口）
class SmartHomeMediator {
public:
    virtual void notify(SmartDevice* sender, const std::string& event) = 0;
    virtual void addDevice(SmartDevice* device) = 0;
    virtual ~SmartHomeMediator() = default;
};

// 设备基类（抽象同事类）
class SmartDevice {
protected:
    SmartHomeMediator* mediator_;
    std::string name_;
public:
    SmartDevice(const std::string& name, SmartHomeMediator* mediator)
        : name_(name), mediator_(mediator) {}

    virtual void triggerEvent(const std::string& event) = 0;
    virtual void handleEvent(const std::string& event) = 0;

    virtual std::string getName() final
    {
        return name_;
    };

    virtual ~SmartDevice() = default;
};

// 具体中介者（实现设备协调逻辑）
class CentralHub : public SmartHomeMediator {
private:
    std::vector<SmartDevice*> devices_;
public:
    void addDevice(SmartDevice* device) override {
        devices_.push_back(device);
    }

    void notify(SmartDevice* sender, const std::string& event) override {
        std::cout << "\n【中枢系统】收到 " << sender->getName()
                  << " 的 " << event << " 事件\n";

        for (auto device : devices_) {
            if (device != sender) {
                std::cout << "--> 分发到 " << device->getName() << ": ";
                device->handleEvent(event);
            }
        }
    }
};

// 具体设备实现
class SmartLight : public SmartDevice {
public:
    using SmartDevice::SmartDevice;

    void triggerEvent(const std::string& event) override {
        std::cout << name_ << " 触发事件: " << event << std::endl;
        mediator_->notify(this, event);
    }

    void handleEvent(const std::string& event) override {
        if (event == "离家模式") {
            std::cout << "关闭所有灯光" << std::endl;
        } else if (event == "回家模式") {
            std::cout << "开启暖色主灯" << std::endl;
        }
    }
};

class AirConditioner : public SmartDevice {
public:
    using SmartDevice::SmartDevice;

    void triggerEvent(const std::string& event) override {
        std::cout << name_ << " 报告状态: " << event << std::endl;
        mediator_->notify(this, event);
    }

    void handleEvent(const std::string& event) override {
        if (event == "离家模式") {
            std::cout << "进入节能模式（26℃）" << std::endl;
        } else if (event == "回家模式") {
            std::cout << "启动快速制冷（22℃）" << std::endl;
        }
    }
};

// 使用示例
int main() {
    // 创建中介者
    CentralHub hub;

    // 创建设备并注册到中枢
    SmartLight livingRoomLight("客厅主灯", &hub);
    SmartLight bedroomLight("卧室夜灯", &hub);
    AirConditioner ac("中央空调", &hub);

    hub.addDevice(&livingRoomLight);
    hub.addDevice(&bedroomLight);
    hub.addDevice(&ac);

    // 模拟事件触发
    std::cout << "=== 触发回家模式 ===" << std::endl;
    livingRoomLight.triggerEvent("回家模式");

    std::cout << "\n=== 触发离家模式 ===" << std::endl;
    bedroomLight.triggerEvent("离家模式");

    return 0;
}
