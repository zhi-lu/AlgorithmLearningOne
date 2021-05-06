//
// Created by APPLE on 2021/5/5.
//
/**
 * @author apple
 * @version c++ 20
 * @date 2021/5/1
 * // 对 template和auto的使用
 * // 此文件对STL中的属性进行讲解......
 */
#include <iostream>
#include <vector>

// 创建一个泛型模版 T.
template<class T>
class Compare {
public:
    // 初始化类的构造方法.
    Compare(T oneNum, T twoNum) {
        numOne = oneNum;
        numTwo = twoNum;
    }

    // 比较,输出大的数字.
    T max() {
        return (numTwo > numOne) ? numTwo : numOne;
    }

    // 比较, 输出小的数字.
    T min() {
        return (numTwo < numOne) ? numTwo : numOne;
    }
    // 将属性定义为私有满足面试对象的操作.
private:
    T numOne, numTwo;
};

int main() {

    Compare compare(2.2, 3.1);
    // 对STL中vector<T>进行阐述.
    std::vector<int> vector = {1, 2, 3, 4, 5, 6};
    for (auto output : vector) {
        std::cout << "输出的迭代值为:"
                  << output;
        std::cout << std::endl;
    }
    auto sayHello = "Hello,World";
    // 对STL中rotate()
    auto iterator = std::rotate(std::begin(vector), std::begin(vector) + 3, std::end(vector));
    // 对STL中copy()
    std::copy(std::begin(vector), std::end(vector), std::ostream_iterator<int>{std::cout, ","});
    std::cout << std::endl << "First element before location: " << *iterator << std::endl;
    std::cout << sayHello << std::endl;
    std::cout << compare.max() << std::endl;
    std::cout << compare.min();

    return 0;
}

