// #include <iostream>
// #include <string>
// #include <memory>
// #include <vector>
// #include <stdexcept>

// // 原发器：需要保存和恢复状态的对象
// class TextEditor {
// private:
//     std::string text;

// public:
//     // 内部备忘录类（仅允许TextEditor访问）
//     class Snapshot {
//     private:
//         std::string text;
//         Snapshot(const std::string& t) : text(t) {}
//         friend class TextEditor; // 关键：声明友元以访问私有成员

//     public:
//         // 禁止外部拷贝构造（仅通过unique_ptr传递）
//         Snapshot(const Snapshot&) = delete;
//         Snapshot& operator=(const Snapshot&) = delete;
//     };

//     // 创建快照
//     std::unique_ptr<Snapshot> createSnapshot() const {
//         return std::make_unique<Snapshot>(text);
//     }

//     // 恢复快照
//     void restoreSnapshot(const Snapshot& snapshot) {
//         text = snapshot.text;
//     }

//     // 业务方法
//     void type(const std::string& words) { text += words; }
//     void clear() { text.clear(); }
//     std::string getText() const { return text; }
// };

// // 管理者：负责管理历史快照
// class History {
// private:
//     std::vector<std::unique_ptr<TextEditor::Snapshot>> stack_;

// public:
//     // 保存状态（使用完美转发）
//     void backup(const TextEditor& editor) {
//         stack_.push_back(editor.createSnapshot());
//     }

//     // 撤销操作
//     void undo(TextEditor& editor) {
//         if (stack_.empty()) {
//             throw std::runtime_error("Cannot undo: History is empty");
//         }
//         editor.restoreSnapshot(*stack_.back());
//         stack_.pop_back();
//     }

//     // 查看历史记录数量
//     size_t historySize() const { return stack_.size(); }
// };

// int main() {
//     TextEditor editor;
//     History history;

//     // 第一次编辑并保存
//     editor.type("Hello, ");
//     history.backup(editor);
//     std::cout << "Current text: " << editor.getText()
//               << " (Backups: " << history.historySize() << ")\n";

//     // 第二次编辑并保存
//     editor.type("World!");
//     history.backup(editor);
//     std::cout << "Current text: " << editor.getText()
//               << " (Backups: " << history.historySize() << ")\n";

//     // 第三次编辑不保存
//     editor.type(" This will be lost.");
//     std::cout << "Current text: " << editor.getText() << "\n";

//     // 第一次撤销
//     try {
//         history.undo(editor);
//         std::cout << "After undo 1: " << editor.getText()
//                   << " (Backups: " << history.historySize() << ")\n";
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << "\n";
//     }

//     // 第二次撤销
//     try {
//         history.undo(editor);
//         std::cout << "After undo 2: " << editor.getText()
//                   << " (Backups: " << history.historySize() << ")\n";
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << "\n";
//     }

//     // 尝试过度撤销
//     try {
//         history.undo(editor);
//     } catch (const std::exception& e) {
//         std::cerr << "Final undo attempt: " << e.what() << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

// 原发器：文本编辑器类
class TextEditor {
private:
    std::string text;

public:
    // 内部备忘录类（私有嵌套类）
    class Snapshot {
    private:
        std::string text;

        // 私有构造函数（只能被友元类TextEditor访问）
        explicit Snapshot(const std::string& t) : text(t) {}

        friend class TextEditor;  // 关键友元声明

    public:
        // 禁止拷贝操作
        Snapshot(const Snapshot&) = delete;
        Snapshot& operator=(const Snapshot&) = delete;
    };

    // 创建快照（使用new直接构造）
    std::unique_ptr<Snapshot> createSnapshot() const {
        return std::unique_ptr<Snapshot>(new Snapshot(text));  // 在TextEditor作用域内访问私有构造函数
    }

    // 恢复快照状态
    void restoreSnapshot(const Snapshot& snapshot) {
        text = snapshot.text;
    }

    // 文本编辑操作
    void type(const std::string& words) { text += words; }
    void clear() { text.clear(); }
    std::string getText() const { return text; }
};

// 管理者：历史记录类
class History {
private:
    std::vector<std::unique_ptr<TextEditor::Snapshot>> undoStack;

public:
    // 保存状态
    void backup(const TextEditor& editor) {
        undoStack.push_back(editor.createSnapshot());
    }

    // 执行撤销
    void undo(TextEditor& editor) {
        if (undoStack.empty()) {
            throw std::runtime_error("Undo failed: No more history");
        }
        editor.restoreSnapshot(*undoStack.back());
        undoStack.pop_back();
    }

    // 获取历史记录数量
    size_t historyCount() const { return undoStack.size(); }
};

int main() {
    TextEditor editor;
    History history;

    try {
        // 第一次编辑并保存
        editor.type("First edit\n");
        history.backup(editor);
        std::cout << "Current text:\n" << editor.getText()
                  << "History count: " << history.historyCount() << "\n\n";

        // 第二次编辑并保存
        editor.type("Second edit\n");
        history.backup(editor);
        std::cout << "Current text:\n" << editor.getText()
                  << "History count: " << history.historyCount() << "\n\n";

        // 第三次编辑不保存
        editor.type("Unsaved edit\n");
        std::cout << "Before undo:\n" << editor.getText();

        // 第一次撤销
        history.undo(editor);
        std::cout << "\nAfter first undo:\n" << editor.getText()
                  << "History count: " << history.historyCount() << "\n";

        // 第二次撤销
        history.undo(editor);
        std::cout << "\nAfter second undo:\n" << editor.getText()
                  << "History count: " << history.historyCount() << "\n";

        // 尝试过度撤销（应该抛出异常）
        history.undo(editor);
    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
    }

    return 0;
}