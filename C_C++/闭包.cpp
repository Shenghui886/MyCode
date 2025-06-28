/************************************
||    Author: Modest_xiaofeng      ||
||   Date: 2025-02-07 22:26:42     ||
|| Operating system: Ubuntu 24.04  ||
||         Editor: Vim             ||
||       QQ: 3198133420            ||
************************************/

#include <iostream>
using namespace std;

auto createCounter() {
    int count = 0;
    return [count]() mutable {
        return ++count;
    };
};

int main(int argc, char *argv []) {

    auto counter = createCounter();
    std::cout << counter() << std::endl;  // 输出: 1
    std::cout << counter() << std::endl;  // 输出: 2
    std::cout << counter() << std::endl;  // 输出: 3

    return 0;
}

