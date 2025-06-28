#include <iostream>
#include <string>

// 日志级别枚举
enum class LogLevel {
    INFO,    // 普通信息
    DEBUG,   // 调试信息
    ERROR    // 错误信息
};

// 抽象日志处理者
class Logger {
public:
    virtual ~Logger() = default;
    void setNext(Logger* next) { next_ = next; }
    virtual void logMessage(LogLevel level, const std::string& message) = 0;

protected:
    Logger* next_ = nullptr;
};

// 控制台日志处理者（处理INFO及以上）
class ConsoleLogger : public Logger {
public:
    explicit ConsoleLogger(LogLevel level) : level_(level) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level >= level_) {
            std::cout << "[INFO] Console: " << message << std::endl;
        }
        if (next_) next_->logMessage(level, message); // 继续传递
    }

private:
    LogLevel level_;
};

// 文件日志处理者（处理DEBUG及以上）
class FileLogger : public Logger {
public:
    explicit FileLogger(LogLevel level) : level_(level) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level >= level_) {
            std::cout << "[DEBUG] File: " << message << std::endl;
        }
        if (next_) next_->logMessage(level, message); // 继续传递
    }

private:
    LogLevel level_;
};

// 错误日志处理者（处理ERROR）
class ErrorLogger : public Logger {
public:
    explicit ErrorLogger(LogLevel level) : level_(level) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level >= level_) {
            std::cerr << "[ERROR] Alert: " << message << std::endl;
        }
        if (next_) next_->logMessage(level, message); // 继续传递
    }

private:
    LogLevel level_;
};

// 客户端代码
int main() {
    // 创建处理者并按优先级链接
    Logger* console = new ConsoleLogger(LogLevel::INFO);
    Logger* file = new FileLogger(LogLevel::DEBUG);
    Logger* error = new ErrorLogger(LogLevel::ERROR);

    console->setNext(file);  // Console -> File
    file->setNext(error);    // File -> Error

    // 发送日志请求
    console->logMessage(LogLevel::INFO, "System started.");
    console->logMessage(LogLevel::DEBUG, "Debugging process.");
    console->logMessage(LogLevel::ERROR, "Critical failure!");

    // 释放资源
    delete console;
    delete file;
    delete error;

    return 0;
}