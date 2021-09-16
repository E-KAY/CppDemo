#include <iostream>
#include "source/CppPrimerTest.h"

using namespace std;

/**
 * 打印 "Hello, World!"
 */
void printHelloWorld() {
    cout << "Hello, World!" << endl;
}

/*
 * while 循环输入 测试
 */
void testWhileCin() {
    int sum = 0, value = 0;

    // 在 Mac 环境下，如果遇到 Command+D 结束 cin 的输入无效，可以通过该设置设置解决：
    // Find action->Registry->run.processes.with.pty disable
    while (cin >> value) {
        sum += value;
    }

    cout << "Sum is: " << sum << endl;
}

void testPoint() {
    // 正确用法：
    const int a = 1;
    const int *p_a = &a;
    cout << "const int a = 1;" << endl;
    cout << "const int *p_a = &a;" << endl;
    cout << "*p_a = " << *p_a << ", p_a = " << p_a << "\n" << endl;;
    // 错误用法：
//    int *p_a = &a;
//    int *p_a = a;
//    const int *p_a = a;

    // 正确用法：
    int aa = 1;
    int *p_aa = &aa;
    const int *c_p_aa = p_aa;
    cout << "int aa = 1;" << endl;
    cout << "int *p_aa = &aa;" << endl;
    cout << "const int *c_p_aa = p_aa;" << endl;
    cout << "*c_p_aa = " << *c_p_aa << ", c_p_aa = " << c_p_aa << "\n" << endl;

    int b = 2;
    int *p_b;
    cout << "int b = 2;" << endl;
    cout << "int *p_b;" << endl;
    cout << "*p_b = " << *p_b << ", p_b = " << p_b << "\n" << endl;

    p_b = &b;
    cout << "p_b = &b;" << endl;
    cout << "*p_b = " << *p_b << ", p_b = " << p_b << "\n" << endl;

    *p_b = b;
    cout << "*p_b = b;" << endl;
    cout << "*p_b = " << *p_b << ", p_b = " << p_b << "\n" << endl;

    b = 3;
    cout << "b = 3;" << endl;
    cout << "*p_b = " << *p_b << ", p_b = " << p_b << "\n" << endl;

    *p_b = 4;
    cout << "*p_b = 4;" << endl;
    cout << "*p_b = " << *p_b << ", p_b = " << p_b << "\n" << endl;

    int **pp_c = &p_b;
    cout << "int **pp_c = &p_b;" << endl;
    cout << "**pp_c = " << **pp_c << ", pp_c = " << pp_c << "\n" << endl;
}

int main() {
    cout << "Enter the corresponding number to run the test:\n"
         << "1: Prient \"Hello, World!\" \n"
         << "2: Loop input through \"While\" \n"
         << "3: Point Test \n"
         << CppPrimerTest::getInputTips()
         << endl;

    int value = 0;
    cin >> value;
    if (1 == value) {
        printHelloWorld();
        return 0;
    }
    if (2 == value) {
        testWhileCin();
        return 0;
    }
    if (3 == value) {
        testPoint();
        return 0;
    }


    if (value >= 1000 && value <= 1999) {
        CppPrimerTest::runSourceDemo(value);
        return 0;
    }

    return 0;
}
