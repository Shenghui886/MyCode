#include <iostream>
#include <string>
#include <memory>

// 抽象主题接口
class FileSystem {
public:
    virtual ~FileSystem() = default;
    virtual std::string readFile(const std::string& path) const = 0;
    virtual void writeFile(const std::string& path, const std::string& content) = 0;
};

// 真实主题类
class RealFileSystem : public FileSystem {
public:
    std::string readFile(const std::string& path) const override {
        // 模拟实际文件读取操作
        return "Content of " + path;
    }

    void writeFile(const std::string& path, const std::string& content) override {
        std::cout << "Writing to " << path << ": " << content << std::endl;
    }
};

// 代理类
class SecureFileProxy : public FileSystem {
    std::unique_ptr<RealFileSystem> realSystem_;
    std::string userRole_;

    bool hasReadAccess() const {
        return userRole_ == "admin" || userRole_ == "user";
    }

    bool hasWriteAccess() const {
        return userRole_ == "admin";
    }

public:
    explicit SecureFileProxy(const std::string& role)
        : userRole_(role), realSystem_(std::make_unique<RealFileSystem>()) {}

    std::string readFile(const std::string& path) const override {
        if (!hasReadAccess()) {
            throw std::runtime_error("Read access denied");
        }

        std::cout << "[LOG] Reading file: " << path << std::endl;
        return realSystem_->readFile(path);
    }

    void writeFile(const std::string& path, const std::string& content) override {
        if (!hasWriteAccess()) {
            throw std::runtime_error("Write access denied");
        }

        std::cout << "[LOG] Writing to file: " << path << std::endl;
        realSystem_->writeFile(path, content);
    }
};

// 客户端代码
int main() {
    try {
        // 普通用户访问
        SecureFileProxy userProxy("user");
        std::cout << userProxy.readFile("data.txt") << std::endl;
        // userProxy.writeFile("data.txt", "new data"); // 会抛出异常

        // 管理员访问
        SecureFileProxy adminProxy("admin");
        adminProxy.writeFile("data.txt", "sensitive data");

        // 无权限用户访问
        SecureFileProxy guestProxy("guest");
        guestProxy.readFile("data.txt"); // 会抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}