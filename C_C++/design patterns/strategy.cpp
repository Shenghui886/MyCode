#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

// 策略接口：排序算法
class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void sort(std::vector<int>& data) const = 0;
    virtual std::string name() const = 0;
};

// 具体策略：快速排序
class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        quickSort(data, 0, data.size()-1);
    }

    std::string name() const override { return "QuickSort"; }

private:
    void quickSort(std::vector<int>& data, int low, int high) const {
        if (low < high) {
            int pi = partition(data, low, high);
            quickSort(data, low, pi - 1);
            quickSort(data, pi + 1, high);
        }
    }

    int partition(std::vector<int>& data, int low, int high) const {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (data[j] < pivot) {
                std::swap(data[++i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
};

// 具体策略：冒泡排序
class BubbleSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        for (size_t i = 0; i < data.size()-1; ++i) {
            for (size_t j = 0; j < data.size()-i-1; ++j) {
                if (data[j] > data[j+1]) {
                    std::swap(data[j], data[j+1]);
                }
            }
        }
    }

    std::string name() const override { return "BubbleSort"; }
};

// 具体策略：插入排序（展示策略扩展）
class InsertionSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) const override {
        for (size_t i = 1; i < data.size(); ++i) {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j+1] = data[j];
                --j;
            }
            data[j+1] = key;
        }
    }

    std::string name() const override { return "InsertionSort"; }
};

// 上下文类
class Sorter {
private:
    std::unique_ptr<SortStrategy> strategy_;

public:
    explicit Sorter(std::unique_ptr<SortStrategy>&& strategy = nullptr)
        : strategy_(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<SortStrategy>&& newStrategy) {
        strategy_ = std::move(newStrategy);
    }

    void execute(std::vector<int>& data) const {
        if (!strategy_) {
            throw std::runtime_error("No sorting strategy set!");
        }

        auto dataCopy = data; // 保持原始数据不变
        std::cout << "Using " << strategy_->name() << ":\n";
        std::cout << "Before: ";
        printData(dataCopy);

        strategy_->sort(dataCopy);

        std::cout << "After:  ";
        printData(dataCopy);
    }

private:
    static void printData(const std::vector<int>& data) {
        for (auto num : data) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
};

// 策略工厂（可选扩展）
class SortStrategyFactory {
public:
    enum StrategyType { QUICK, BUBBLE, INSERTION };

    static std::unique_ptr<SortStrategy> create(StrategyType type) {
        switch (type) {
            case QUICK:     return std::make_unique<QuickSort>();
            case BUBBLE:    return std::make_unique<BubbleSort>();
            case INSERTION: return std::make_unique<InsertionSort>();
            default:        throw std::invalid_argument("Invalid strategy type");
        }
    }
};

// 生成测试数据
std::vector<int> generateTestData(int size = 10) {
    std::vector<int> data(size);
    std::iota(data.begin(), data.end(), 1);
    std::shuffle(data.begin(), data.end(),
                std::mt19937{std::random_device{}()});
    return data;
}


int main() {
    // 准备测试数据
    auto testData = generateTestData();

    // 创建上下文
    Sorter sorter;

    // 测试不同策略
    try {
        // 使用工厂创建策略
        sorter.setStrategy(SortStrategyFactory::create(SortStrategyFactory::QUICK));
        sorter.execute(testData);

        sorter.setStrategy(SortStrategyFactory::create(SortStrategyFactory::BUBBLE));
        sorter.execute(testData);

        sorter.setStrategy(SortStrategyFactory::create(SortStrategyFactory::INSERTION));
        sorter.execute(testData);

        // 直接设置策略
        sorter.setStrategy(std::make_unique<QuickSort>());
        sorter.execute(testData);

        // 测试未设置策略的情况
        Sorter emptySorter;
        emptySorter.execute(testData);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}