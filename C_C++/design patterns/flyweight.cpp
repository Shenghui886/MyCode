// #include <iostream>
// #include <map>
// #include <memory>
// #include <mutex>
// #include <string>
// #include <tuple>

// // 定义 Flyweight 的键类型（内部状态）
// using Key = std::tuple<char, std::string, std::string>;  // 字符 + 字体 + 颜色

// // Flyweight 类：封装字符及其不可变共享属性
// class CharacterFlyweight {
// private:
//     char m_char;
//     std::string m_font;
//     std::string m_color;

// public:
//     CharacterFlyweight(char c, std::string font, std::string color)
//         : m_char(c), m_font(std::move(font)), m_color(std::move(color)) {}

//     // 渲染方法：外部状态通过参数传入
//     void display(int x, int y, int fontSize) const {
//         std::cout << "Display '" << m_char
//                   << "' at (" << x << ", " << y << ")"
//                   << " with font: " << m_font
//                   << ", color: " << m_color
//                   << ", size: " << fontSize << "\n";
//     }

//     // 获取内部状态（用于调试）
//     Key getKey() const {
//         return std::make_tuple(m_char, m_font, m_color);
//     }
// };

// // Flyweight 工厂（线程安全 + 智能指针管理）
// class FlyweightFactory {
// private:
//     std::map<Key, std::shared_ptr<CharacterFlyweight>> m_flyweights;
//     std::mutex m_mutex;  // 保证线程安全

// public:
//     // 获取 Flyweight 对象（自动创建新对象或返回现有）
//     std::shared_ptr<CharacterFlyweight> getFlyweight(
//         char c,
//         const std::string& font = "Arial",
//         const std::string& color = "black")
//     {
//         const Key key = std::make_tuple(c, font, color);

//         std::lock_guard<std::mutex> lock(m_mutex);  // 自动加锁

//         auto it = m_flyweights.find(key);
//         if (it == m_flyweights.end()) {
//             std::cout << "Creating new Flyweight: " << c
//                       << " (font: " << font
//                       << ", color: " << color << ")\n";
//             auto flyweight = std::make_shared<CharacterFlyweight>(c, font, color);
//             m_flyweights[key] = flyweight;
//             return flyweight;
//         }
//         return it->second;
//     }

//     size_t count() const {
//         return m_flyweights.size();
//     }
// };

// // 客户端使用示例
// int main() {
//     FlyweightFactory factory;

//     // 第一段落：红色宋体文字
//     std::string text1 = "设计模式";
//     for (size_t i = 0; i < text1.size(); ++i) {
//         auto c = factory.getFlyweight(text1[i], "SimSun", "red");
//         c->display(i * 20, 50, 12);  // 不同位置相同样式
//     }

//     // 第二段落：重复使用部分 Flyweight
//     std::string text2 = "模式实践";
//     for (size_t i = 0; i < text2.size(); ++i) {
//         // "模" 和 "式" 会复用之前的 Flyweight
//         auto c = factory.getFlyweight(text2[i], "SimSun", "red");
//         c->display(i * 20, 100, 12);
//     }

//     // 第三段落：创建新的 Flyweight
//     auto c = factory.getFlyweight('A', "Times New Roman", "blue");
//     c->display(0, 150, 14);

//     // 统计结果
//     std::cout << "\nTotal Flyweights created: " << factory.count() << std::endl;

//     return 0;
// }


#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <tuple>

// 定义 Flyweight 的键类型（内部状态）
using Key = std::tuple<char, std::string, std::string>;  // 字符 + 字体 + 颜色

// Flyweight 类：封装字符及其不可变共享属性
class CharacterFlyweight {
private:
    char m_char;
    std::string m_font;
    std::string m_color;

public:
    CharacterFlyweight(char c, std::string font, std::string color)
        : m_char(c), m_font(std::move(font)), m_color(std::move(color)) {}

    // 渲染方法：外部状态通过参数传入
    void display(int x, int y, int fontSize) const {
        std::cout << "Character '" << m_char
                  << "' at (" << x << ", " << y << ")"
                  << " - Font: " << m_font
                  << ", Color: " << m_color
                  << ", Size: " << fontSize << "\n";
    }

    // 获取内部状态（用于调试）
    Key getKey() const {
        return std::make_tuple(m_char, m_font, m_color);
    }
};

// Flyweight 工厂（线程安全 + 智能指针管理）
class FlyweightFactory {
private:
    std::map<Key, std::shared_ptr<CharacterFlyweight>> m_flyweights;
    std::mutex m_mutex;  // 保证线程安全

public:
    // 获取 Flyweight 对象（自动创建新对象或返回现有）
    std::shared_ptr<CharacterFlyweight> getFlyweight(
        char c,
        const std::string& font = "Arial",
        const std::string& color = "black")
    {
        const Key key = std::make_tuple(c, font, color);

        std::lock_guard<std::mutex> lock(m_mutex);  // 自动加锁

        auto it = m_flyweights.find(key);
        if (it == m_flyweights.end()) {
            std::cout << "[Factory] Creating new instance for: '" << c
                      << "' (Font: " << font
                      << ", Color: " << color << ")\n";
            auto flyweight = std::make_shared<CharacterFlyweight>(c, font, color);
            m_flyweights[key] = flyweight;
            return flyweight;
        }
        return it->second;
    }

    // 统计已创建的 Flyweight 数量
    size_t count() const {
        return m_flyweights.size();
    }
};

int main() {
    FlyweightFactory factory;

    // 第一段落：红色Arial字体
    std::string text1 = "HELLO";
    for (size_t i = 0; i < text1.size(); ++i) {
        auto c = factory.getFlyweight(text1[i], "Arial", "red");
        c->display(i * 20, 50, 12);
    }

    // 第二段落：复用部分Flyweight
    std::string text2 = "WORLD";
    for (size_t i = 0; i < text2.size(); ++i) {
        auto c = factory.getFlyweight(text2[i], "Arial", "red");
        c->display(i * 20, 100, 12);
    }

    // 第三段落：创建新Flyweight
    auto c = factory.getFlyweight('Z', "Times New Roman", "blue");
    c->display(0, 150, 14);

    std::cout << "\nTotal flyweight instances: " << factory.count() << std::endl;

    return 0;
}


// #include <iostream>
// #include <map>
// #include <memory>
// #include <mutex>
// #include <string>
// #include <tuple>
// #include <locale>
// #include <codecvt>

// // 定义 Flyweight 的键类型（内部状态）
// using Key = std::tuple<wchar_t, std::wstring, std::wstring>;  // 宽字符支持

// // Flyweight 类：封装字符及其不可变共享属性
// class CharacterFlyweight {
// private:
//     wchar_t m_char;
//     std::wstring m_font;
//     std::wstring m_color;

// public:
//     CharacterFlyweight(wchar_t c, std::wstring font, std::wstring color)
//         : m_char(c), m_font(std::move(font)), m_color(std::move(color)) {}

//     // 渲染方法：外部状态通过参数传入
//     void display(int x, int y, int fontSize) const {
//         std::wcout << L"显示 '" << m_char
//                   << L"' 位置 (" << x << L", " << y << L")"
//                   << L" 字体: " << m_font
//                   << L" 颜色: " << m_color
//                   << L" 字号: " << fontSize << L"\n";
//     }

//     // 获取内部状态（用于调试）
//     Key getKey() const {
//         return std::make_tuple(m_char, m_font, m_color);
//     }
// };

// // Flyweight 工厂（线程安全 + 智能指针管理）
// class FlyweightFactory {
// private:
//     std::map<Key, std::shared_ptr<CharacterFlyweight>> m_flyweights;
//     std::mutex m_mutex;

// public:
//     std::shared_ptr<CharacterFlyweight> getFlyweight(
//         wchar_t c,
//         const std::wstring& font = L"宋体",
//         const std::wstring& color = L"黑色")
//     {
//         const Key key = std::make_tuple(c, font, color);

//         std::lock_guard<std::mutex> lock(m_mutex);

//         auto it = m_flyweights.find(key);
//         if (it == m_flyweights.end()) {
//             std::wcout << L"创建新 Flyweight: " << c
//                       << L" (字体: " << font
//                       << L", 颜色: " << color << L")\n";
//             auto flyweight = std::make_shared<CharacterFlyweight>(c, font, color);
//             m_flyweights[key] = flyweight;
//             return flyweight;
//         }
//         return it->second;
//     }

//     size_t count() const {
//         return m_flyweights.size();
//     }
// };

// // 设置中文环境
// void setupLocale() {
//     std::locale::global(std::locale("zh_CN.UTF-8"));
//     std::wcout.imbue(std::locale("zh_CN.UTF-8"));
// }

// // 客户端使用示例
// int main() {
//     setupLocale();  // 必须的本地化设置

//     FlyweightFactory factory;

//     // 第一段落：红色宋体文字
//     std::wstring text1 = L"设计模式";
//     for (size_t i = 0; i < text1.size(); ++i) {
//         auto c = factory.getFlyweight(text1[i], L"宋体", L"红色");
//         c->display(static_cast<int>(i * 20), 50, 12);
//     }

//     // 第二段落：复用部分 Flyweight
//     std::wstring text2 = L"模式实践";
//     for (size_t i = 0; i < text2.size(); ++i) {
//         auto c = factory.getFlyweight(text2[i], L"宋体", L"红色");
//         c->display(static_cast<int>(i * 20), 100, 12);
//     }

//     // 第三段落：创建新的 Flyweight
//     auto c = factory.getFlyweight(L'A', L"Times New Roman", L"蓝色");
//     c->display(0, 150, 14);

//     std::wcout << L"\n总创建 Flyweight 数量: " << factory.count() << std::endl;

//     return 0;
// }