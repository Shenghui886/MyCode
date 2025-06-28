#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// ================= 标准迭代器模式实现 =================
template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual void first() = 0;        // 重置到起始位置
    virtual void next() = 0;          // 移动到下一个元素
    virtual bool isDone() const = 0;  // 是否遍历完成
    virtual T& current() = 0;        // 获取当前元素
};

// 抽象聚合类
template <typename T>
class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual std::unique_ptr<Iterator<T>> createIterator() = 0;
    virtual size_t size() const = 0;
    virtual T& operator[](size_t index) = 0;
};

// 具体聚合类（动态数组）
template <typename T>
class DynamicArray : public Aggregate<T> {
    std::vector<T> data;
public:
    void add(const T& value) { data.push_back(value); }

    size_t size() const override { return data.size(); }
    T& operator[](size_t index) override { return data[index]; }

    // 正向迭代器
    class ForwardIterator : public Iterator<T> {
        DynamicArray& array;
        size_t currentIndex;
    public:
        ForwardIterator(DynamicArray& arr) : array(arr), currentIndex(0) {}

        void first() override { currentIndex = 0; }
        void next() override { ++currentIndex; }
        bool isDone() const override { return currentIndex >= array.size(); }
        T& current() override { return array[currentIndex]; }
    };

    // 反向迭代器
    class ReverseIterator : public Iterator<T> {
        DynamicArray& array;
        size_t currentIndex;
    public:
        ReverseIterator(DynamicArray& arr) : array(arr), currentIndex(arr.size()-1) {}

        void first() override { currentIndex = array.size() - 1; }
        void next() override { --currentIndex; }
        bool isDone() const override { return currentIndex >= array.size(); } // 无符号溢出处理
        T& current() override { return array[currentIndex]; }
    };

    std::unique_ptr<Iterator<T>> createIterator() override {
        return std::make_unique<ForwardIterator>(*this);
    }
};

// ================= STL风格迭代器实现 =================
template <typename T>
class StlDynamicArray {
    std::vector<T> data;
public:
    void add(const T& value) { data.push_back(value); }

    // 迭代器定义
    class iterator {
        typename std::vector<T>::iterator it;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit iterator(typename std::vector<T>::iterator it) : it(it) {}

        reference operator*() const { return *it; }
        pointer operator->() { return &*it; }
        iterator& operator++() { ++it; return *this; }
        iterator operator++(int) { auto tmp = *this; ++it; return tmp; }
        bool operator==(const iterator& other) const { return it == other.it; }
        bool operator!=(const iterator& other) const { return it != other.it; }
    };

    iterator begin() { return iterator(data.begin()); }
    iterator end() { return iterator(data.end()); }
};

// ================= 客户端使用示例 =================
int main() {
    std::cout << "=== 标准迭代器模式演示 ===" << std::endl;
    {
        DynamicArray<int> arr;
        arr.add(1);
        arr.add(2);
        arr.add(3);

        // 正向遍历
        auto forwardIt = arr.createIterator();
        std::cout << "Forward iteration: ";
        for (forwardIt->first(); !forwardIt->isDone(); forwardIt->next()) {
            std::cout << forwardIt->current() << " ";
        }
        std::cout << std::endl;

        // 反向遍历（需要显式创建反向迭代器）
        DynamicArray<int>::ReverseIterator reverseIt(arr);
        std::cout << "Reverse iteration: ";
        for (reverseIt.first(); !reverseIt.isDone(); reverseIt.next()) {
            std::cout << reverseIt.current() << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== STL风格迭代器演示 ===" << std::endl;
    {
        StlDynamicArray<std::string> arr;
        arr.add("Hello");
        arr.add("Iterator");
        arr.add("Pattern");

        // 使用范围for循环
        std::cout << "Range-based for loop: ";
        for (const auto& item : arr) {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        // 使用STL算法
        std::cout << "STL algorithm (transform): ";
        std::transform(arr.begin(), arr.end(), arr.begin(),
            [](std::string s) { return s + "!"; });

        for (const auto& item : arr) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}