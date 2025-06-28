#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <algorithm>

// 前置声明
class Subject;

// Observer接口
class Observer : public std::enable_shared_from_this<Observer> {
public:
    virtual ~Observer() = default;
    virtual void update(const std::shared_ptr<Subject>& subject) = 0;
};

// Subject基类
class Subject : public std::enable_shared_from_this<Subject> {
protected:
    mutable std::mutex mtx_;  // 保证线程安全
    std::vector<std::weak_ptr<Observer>> observers_;

    // 清理失效的观察者
    void cleanExpired() {
        observers_.erase(
            std::remove_if(observers_.begin(), observers_.end(),
                [](const std::weak_ptr<Observer>& wp) {
                    return wp.expired();
                }),
            observers_.end()
        );
    }

public:
    virtual ~Subject() = default;

    void attach(const std::shared_ptr<Observer>& observer) {
        std::lock_guard<std::mutex> lock(mtx_);
        observers_.emplace_back(observer);
    }

    void detach(const std::shared_ptr<Observer>& observer) {
        std::lock_guard<std::mutex> lock(mtx_);
        cleanExpired();  // 先清理失效观察者

        // 查找并移除指定观察者
        observers_.erase(
            std::remove_if(observers_.begin(), observers_.end(),
                [&observer](const std::weak_ptr<Observer>& wp) {
                    auto sp = wp.lock();
                    return sp && sp == observer;
                }),
            observers_.end()
        );
    }

    void notify() {
        std::lock_guard<std::mutex> lock(mtx_);
        cleanExpired();

        auto self = shared_from_this();
        for (auto& wp : observers_) {
            if (auto sp = wp.lock()) {
                sp->update(self);
            }
        }
    }
};

// 具体Subject：温度传感器
class TemperatureSensor : public Subject {
    double temperature_ = 0.0;

public:
    void setTemperature(double value) {
        temperature_ = value;
        notify();  // 温度变化时通知观察者
    }

    double getTemperature() const { return temperature_; }
};

// 具体Observer：温度显示器
class TemperatureDisplay : public Observer {
    std::weak_ptr<TemperatureSensor> sensor_;

    void update(const std::shared_ptr<Subject>& subject) override {
        auto sensor = std::dynamic_pointer_cast<TemperatureSensor>(subject);
        if (sensor) {
            std::cout << "Temperature updated: "
                      << sensor->getTemperature() << "°C\n";
        }
    }

public:
    explicit TemperatureDisplay(const std::shared_ptr<TemperatureSensor>& sensor)
        : sensor_(sensor) {}
};

// 具体Observer：高温报警器
class HighTempAlarm : public Observer {
    const double threshold_;

    void update(const std::shared_ptr<Subject>& subject) override {
        auto sensor = std::dynamic_pointer_cast<TemperatureSensor>(subject);
        if (sensor && sensor->getTemperature() > threshold_) {
            std::cout << "ALERT! Temperature exceeds "
                     << threshold_ << "°C (Current: "
                     << sensor->getTemperature() << "°C)\n";
        }
    }

public:
    explicit HighTempAlarm(double threshold) : threshold_(threshold) {}
};

int main() {
    // 创建被观察对象
    auto sensor = std::make_shared<TemperatureSensor>();

    // 创建观察者
    auto display = std::make_shared<TemperatureDisplay>(sensor);
    auto alarm = std::make_shared<HighTempAlarm>(30.0);

    // 注册观察者
    sensor->attach(display);
    sensor->attach(alarm);

    // 模拟温度变化
    sensor->setTemperature(25.5);
    sensor->setTemperature(28.0);
    sensor->setTemperature(32.5);  // 触发报警

    // 移除报警器观察
    sensor->detach(alarm);
    sensor->setTemperature(35.0);  // 不再报警

    return 0;
}