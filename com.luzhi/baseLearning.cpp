//
// Created by APPLE on 2021/5/5.
//
/**
 * @author apple
 * @version c++ 20
 * 对于学习c++中STL先预先复习原来对知识.
 * // 复习1:
 */
#include <iostream>
#include <vector>

// 先声明一个模版,定义虚拟类为T
class BasicReview {
public:
    // 定义类的初始化构造方法.
    BasicReview() {
        std::cout << "复习相关的c++知识." << std::endl;
    }

    // 静态方法
    // 对review方法进行实现,首先复习相关==取值运算符 *,和 地址运算符 &
    [[maybe_unused]] static void reviewOne(int numOne) {
        std::cout << "对地址运算符&的操作,numOne的地址为:"
                  << &numOne << std::endl;
        int *a = &numOne;
        // 取值操作符对原来的值进行操作,会修改该地址中原来的值.
        *a = 10;
        int *p = &numOne;
        std::cout << p << std::endl
                  << *p
                  << std::endl;
        int **b = &a;
        std::cout << "打印a的值为:" << a
                  << ",打印*a的值为:" << *a
                  << ",打印&a的值为:" << &a
                  << ",打印*&a的值为" << *&a << std::endl
                  << "输出b的值为:" << b
                  << ",输出*b的值为:" << *b
                  << ",输出**b的值为:" << **b << std::endl
                  << "输出&b的值为:" << &b
                  << ",输出&*b的值为:" << &*b
                  << "输出&**b的值为:" << &**b << std::endl;
    };

    // 静态方法方法,进行实现
    [[maybe_unused]] static void reviewTwo();

    // 复习相关的知识
    [[maybe_unused]] static std::string reviewThree(const std::string &string);

    // 学习STL中基本vector
    [[maybe_unused]] static void reviewFour();
};

int main() {

    std::string string("hello,luzhi");
    BasicReview::reviewTwo();
    std::cout << "对字符串未进行reverse操作之前输出:" << string << std::endl;
    std::cout << "对字符串进行相关的reverse后的结果为:" << BasicReview::reviewThree(string) << std::endl;
    std::cout << "<===============================================================================>" << std::endl;
    BasicReview::reviewFour();
    return 0;
}

// 此方法探究STL中std::function()方法的使用
[[maybe_unused]] void BasicReview::reviewTwo() {
    std::cout << "探究STL中 std::find()的使用." << std::endl;
    // 创建一个迭代对象 vector
    std::vector<int> vector = {1, 2, 5, 8, 5, 4, 9};
    // 定义需要查找的数字
    auto search_element = 8;
    // 进行遍历,获取迭代查找的结果.
    auto iterator = std::find(vector.begin(), vector.end(), search_element);
    // 遍历查找
    if (iterator != vector.end()) {
        // 获取相关的位置.
        std::cout << search_element << "在列表中的位置为:" << iterator - vector.begin() << std::endl;
    } else {
        std::cout << search_element << "Not Found" << std::endl;
    }
    std::cout << "探究STL 中 std::binary_search()方法的使用!" << std::endl;
    // std::binary_search() 只进行迭代查找,不返回相关的结果. 只返回一个bool值.
    if (std::binary_search(vector.begin(), vector.end(), search_element)) {
        std::cout << search_element << "在相关的迭代器中!" << std::endl;
    } else {
        std::cout << search_element << "Not Found" << std::endl;
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"

// 对std::string中 rbegin的使用
[[maybe_unused]] std::string BasicReview::reviewThree(const std::string &string) {

    std::string reverseString;
    if (1 >= string.size()) {
        return string;
    }
    for (auto charList = string.rbegin(); charList != string.rend(); charList++) {
        reverseString.push_back(*charList);
    }
    return reverseString;
}

#pragma clang diagnostic pop

[[maybe_unused]] void BasicReview::reviewFour() {

    // 定义一个迭代器 vector
    std::vector<int> vector;
    // 开辟的空间capacity (容器预留空间)为10,但现在不能用[]访问
    vector.reserve(10);
    // 往vector 的 capacity 填充10个元素
    for (int i = 0; i < 10; ++i) {
        vector.push_back(i);
    }
    std::cout << "现在vector中有:" << vector.size() << "元素" << std::endl;
    // 清理vector 空间的所有元素.
    vector.clear();
    std::cout << "现在vector中有:" << vector.size() << "元素" << std::endl;
    // 在空间中占有的空间为 20
    vector.resize(20);
    // 如果是int型未定义赋值默认的值为0,如果是 char型则为定义赋值则默认值为: '/0'
    std::cout << "输出vector[10]的值:" << vector[10] << std::endl;
    vector[10] = 10;
    std::cout << "输出定义后的vector[10]的值:" << vector[10] << std::endl;
}