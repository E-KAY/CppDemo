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

int main() {
    cout << "Enter the corresponding number to run the test:\n"
         << "1: Prient \"Hello, World!\" \n"
         << "2: Loop input through \"While\" \n"
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


    if (value >= 1000 && value <= 1999) {
        CppPrimerTest::runSourceDemo(value);
        return 0;
    }

    return 0;
}
