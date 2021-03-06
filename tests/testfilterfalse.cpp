#include <filterfalse.hpp>

#include <vector>
#include <iostream>

using iter::filterfalse;

bool greater_than_four(int i) {
    return i > 4;
}

class LessThanValue {
    private:
        int compare_val;

    public:
        LessThanValue() = delete;
        LessThanValue(int v) : compare_val(v) { }
        
        bool operator() (int i) const {
            return i < this->compare_val;
        }
};


int main() {
    std::vector<int> vec{1, 5, 6, 7, 2, 3, 8, 3, 2, 1};

    std::cout << "Greater than 4 (function pointer)\n";
    for (auto i : filterfalse(greater_than_four, vec)) {
        std::cout << i << '\n';
    }

    std::cout << "Less than 4 (lambda)\n";
    for (auto i : filterfalse([] (const int i) { return i < 4; }, vec)) {
        std::cout << i << '\n';
    }

    LessThanValue lv(4);
    std::cout << "Less than 4 (callable object)\n";
    for (auto i : filterfalse(lv, vec)) {
        std::cout << i << '\n';
    }

    std::cout << "zero ints filter(vec2)\n";
    std::vector<int> vec2 {0, 1, 2, 0, 3, 0, 0, 0, 4, 5, 0};
    for (auto i : filterfalse(vec2)) {
        std::cout << i << '\n';
    }

    std::cout << "Constness tests\n";
    const std::vector<int> cvec(vec);
    for (auto i : filterfalse(greater_than_four, cvec)) {
        std::cout << i << '\n';
    }

    for (auto i : filterfalse([] (const int & i) { return i < 4; }, cvec)) {
        std::cout << i << '\n';
    }

    return 0;
}
