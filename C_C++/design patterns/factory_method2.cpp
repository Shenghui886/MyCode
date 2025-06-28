#include <iostream>
#include <memory>
#include <map>
#include <functional>

// 1. 抽象产品
class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const std::string& message) = 0;
};

// 2. 具体产品
class FileLogger : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << "Log to file: " << message << std::endl;
    }
};

// 3. 工厂注册表（支持运行时扩展）
class LoggerFactory {
public:
    using CreatorFunc = std::function<std::unique_ptr<ILogger>()>;
    static void registerType(const std::string& type, CreatorFunc creator) {
        registry()[type] = creator;
    }
    static std::unique_ptr<ILogger> create(const std::string& type) {
        return registry().at(type)();
    }
private:
    static std::map<std::string, CreatorFunc>& registry() {
        static std::map<std::string, CreatorFunc> instance;
        return instance;
    }
};


// 客户端代码
int main() {
    // 注册具体工厂
    LoggerFactory::registerType("file", [] { return std::make_unique<FileLogger>(); });

    auto logger = LoggerFactory::create("file");
    logger->log("System started.");
    return 0;
}