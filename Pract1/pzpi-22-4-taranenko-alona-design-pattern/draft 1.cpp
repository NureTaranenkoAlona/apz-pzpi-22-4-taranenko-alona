#include <iostream>
#include <vector>
#include <algorithm>


// Інтерфейс стратегії
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortingStrategy() = default;
};

// Реалізація стратегії: BubbleSort
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Sorting by BubbleSort\n";
        for (size_t i = 0; i < data.size() - 1; ++i) {
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Реалізація стратегії: QuickSort
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "QuickSort\n";
        quickSort(data, 0, data.size() - 1);
    }

private:
    void quickSort(std::vector<int>& data, int left, int right) {
        if (left < right) {
            int pivot = partition(data, left, right);
            quickSort(data, left, pivot - 1);
            quickSort(data, pivot + 1, right);
        }
    }

    int partition(std::vector<int>& data, int left, int right) {
        int pivot = data[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[right]);
        return i + 1;
    }
};

// Контекст
class SortContext {
private:
    SortingStrategy* strategy;
public:
    void setStrategy(SortingStrategy* strat) {
        strategy = strat;
    }
    void executeStrategy(std::vector<int>& data) {
        if (strategy) {
            strategy->sort(data);
        }
    }
};

// Головна функція
int main() {
    std::vector<int> numbers = { 5, 3, 8, 1, 2 };
    SortContext context;

    // Використання BubbleSort
    BubbleSort bubble;
    context.setStrategy(&bubble);
    context.executeStrategy(numbers);
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    // Використання QuickSort
    numbers = { 5, 3, 8, 1, 2 };
    QuickSort quick;
    context.setStrategy(&quick);
    context.executeStrategy(numbers);
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
