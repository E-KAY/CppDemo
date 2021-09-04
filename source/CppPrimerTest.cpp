//
// Created by HuangYiKai on 2021/8/30.
//

#include "CppPrimerTest.h"
#include "Sales_item.h"

using namespace std;

void CppPrimerTest::testPage20$$1_5_2_sample() {
    cout << "输入两本书的销售记录进行比较[书名 销售量 单价]：" << endl;

    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        cout << item1 + item2 << endl;
        return;
    }

    cerr << "Data must refer to same ISBN" << endl;
}

void CppPrimerTest::testPage20$$1_20_practice() {
    Sales_item book;
    cout << "请输入销售记录[书名 销售量 单价]：" << endl;

    while (cin >> book) {
        cout << "ISBN、售出本数、销售额和平均售价为 " << book << endl;
    }
}

void CppPrimerTest::testPage21$$1_23_practice() {
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (compareIsbn(item1, item2)) { // Sales_item 内部分装的方法，相当于 item1.isbn() == item2.isbn();
        cout << item1 + item2 << endl;
        return;
    }

    cerr << "Data must refer to same ISBN" << endl;
}


string CppPrimerTest::getInputTips() {
    return "1000: C++ Primer, Page 20, 1.5.2 Source Demo\n"
           "1001: C++ Primer, Page 20, 1.20 Practice";
}


void CppPrimerTest::runSourceDemo(const int &pValue) {
    switch (pValue) {
        case 1000:
            testPage20$$1_5_2_sample();
            break;
        case 1001:
            testPage20$$1_20_practice();
            break;
    }

}
