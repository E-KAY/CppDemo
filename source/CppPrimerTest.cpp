//
// Created by HuangYiKai on 2021/8/30.
//

#include <map>
#include <list>

#include "CppPrimerTest.h"
#include "Sales_item.h"

using namespace std;

void CppPrimerTest::testPage20$$1_5_2_sample() {
    cout << "输入两条书本销售记录进行比较 [书名 销售量 单价]：" << endl;

    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (compareIsbn(item1, item2)) { // compareIsbn 是 Sales_item 类中提供的方法，相当于 item1.isbn() == item2.isbn()
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

void CppPrimerTest::testPage20$$1_21_practice() {
    cout << "输入两条书本销售记录 [书名 销售量 单价]：" << endl;
    Sales_item item1, item2;

    cin >> item1 >> item2;

    if (compareIsbn(item1, item2)) {
        cout << "记录总和：ISBN、售出本数、销售额和平均售价为 " << item1 + item2 << endl;
    } else {
        cout << "两条记录的 ISBN 不相同";
    }
    cout << endl;
}

void CppPrimerTest::testPage20$$1_22_practice() {
    cout << "输入书本销售记录 [书名 销售量 单价]：" << endl;
    Sales_item total, item;

    // total 需要先有一条数据
    cin >> total;

    while (cin >> item) {
        if (compareIsbn(total, item)) {
            total += item;
        } else {
            cout << "请输入 ISBN 相同的数据" << endl;
        }
    }

    cout << "记录总和：ISBN、售出本数、销售额和平均售价为 " << total << endl;
}

// 这里和书上的答案不太一样。如果刚入门编程，建议根据书上编写方式先简单进行尝试，便于理解
// 此处为了能够在完全输入后进行统计，提前尝试用 map、iterator ，
// 同时，根据书本的指导下载的 Sales_item.h 文件内部可能还没有实现 operator< ，此时进行 map 的 find 操作会出异常。
// 参考本工程中的 Sales_item.h 实现
void CppPrimerTest::testPage21$$1_23_practice() {
    cout << "输入书本销售记录 [书名 销售量 单价]：" << endl;

    map<Sales_item, int> itemMap;

    Sales_item item;
    map<Sales_item, int>::iterator iter;

    while (cin >> item) {
        iter = itemMap.find(item);
        if (iter != itemMap.end()) {
            // 把已经存在记录的书，计数 +1
            itemMap.insert(pair<Sales_item, int>(iter->first, ++iter->second));
        } else {
            // 如果书还没有记录，那就直接插入一条新的数据
            itemMap.insert(pair<Sales_item, int>(item, 1));
        }
    }

    // 结束输入后，这里打印记录
    for (iter = itemMap.begin(); iter != itemMap.end(); ++iter) {
        cout << iter->first.isbn() << "共有" << iter->second << "条销售记录" << endl;
    }
}

string CppPrimerTest::getInputTips() {
    return "1000: C++ Primer, Page 20, 1.5.2 Source Demo\n"
           "1001: C++ Primer, Page 20, 1.20 Practice\n"
           "1002: C++ Primer, Page 20, 1.21 Practice\n"
           "1003: C++ Primer, Page 20, 1.22 Practice\n"
           "1004: C++ Primer, Page 21, 1.23 Practice\n";
}


void CppPrimerTest::runSourceDemo(const int &pValue) {
    switch (pValue) {
        case 1000:
            testPage20$$1_5_2_sample();
            break;
        case 1001:
            testPage20$$1_20_practice();
            break;
        case 1002:
            testPage20$$1_21_practice();
            break;
        case 1003:
            testPage20$$1_22_practice();
            break;
        case 1004:
            testPage21$$1_23_practice();
            break;
        default:
            cout << "没有与数值[" << &pValue << "]对应的测试函数" << endl;
            break;
    }

}
