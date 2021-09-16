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

void CppPrimerTest::testPage35$$2_3_practice() {
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl;

    int i = 10, i2 = 42;
    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;
}


string global_str;
int global_int;

void CppPrimerTest::testPage40$$2_10_practice() {
    cout << "global_str default value is: " << global_str << endl;
    cout << "global_int default is: " << global_int << endl;

    int local_int;
    string local_str;

    cout << "local_int default value is: " << local_int << endl;
    cout << "local_str default is: " << local_str << endl;
}


void CppPrimerTest::testPage45$$2_14_practice() {
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i) {
        sum += i;
    }
    cout << "i = " << i << ", sum = " << sum << endl;
}

void CppPrimerTest::testPage81$$3_2_2practice() {
    // ===== 3.2 =====
    string input;
    while (getline(cin, input)) {
        cout << "the input string are: " << input << endl;
        if (input == "exit") {
            break;
        }
    }

    // ===== 3.4 =====
    string word;
    while (getline(cin, word, ' ')) {
        if (word == "exit\n" || word == "exit") {
            break;
        }

        cout << "the input word are: " << word << endl;
    }

    // ===== 3.5 =====
    string line, result;
    while (getline(cin, line)) {
        if (line == "exit") {
            break;
        }
        if (!result.empty()) {
            result += " ";
        }
        result += line;
    }
    cout << "the splice string are: " << result << endl;
}

void CppPrimerTest::testPage81$$3_3_practice() {

}


void CppPrimerTest::testPage86$$3_6_practice() {
    string str("This is a test string");
    cout << "str: " << str << endl;

    for (char &item: str) {
        item = 'x';
    }

    cout << "after change 1, str: " << str << endl;

    for (auto &item: str) {
        item = 'X';
    }

    cout << "after change 2, str: " << str << endl;

    string s;
    cout << s[0] << endl;
}


// 这个是在验证 map 操作可行性时写的 测试代码，增加了传递三个参数的构造函数
void testMap() {
    map<Sales_item, int> itemMap;

    Sales_item item1 = Sales_item("book1", 2, 2);
    Sales_item item2 = Sales_item("book2", 3, 5.5);
    Sales_item item3 = Sales_item("book3", 2, 6.66);

    itemMap.insert(pair<Sales_item, int>(item1, 2));
    itemMap.insert(pair<Sales_item, int>(item2, 4));
    itemMap.insert(pair<Sales_item, int>(item3, 6));

    cout << "itemMap size = " << itemMap.size() << endl;

    Sales_item book2 = Sales_item("book2", 1, 1);
    map<Sales_item, int>::iterator iter;
    iter = itemMap.find(book2);

    cout << "item == book2? result = " << (item1 == book2) << endl;

    if (iter != itemMap.end()) {
        cout << "itemMap find book2, sales : " << iter->second << endl;
    } else {
        cout << "itemMap do not find book2" << endl;
    }
}


string CppPrimerTest::getInputTips() {
    return "[   1000: C++ Primer, Page 20, 1.5.2 Source Demo ],"
           "[   1001: C++ Primer, Page 20, 1.20 Practice     ]\n"
           "[   1002: C++ Primer, Page 20, 1.21 Practice     ],"
           "[   1003: C++ Primer, Page 20, 1.22 Practice     ]\n"
           "[   1004: C++ Primer, Page 21, 1.23 Practice     ],"
           "[   1005: C++ Primer, Page 35, 2.3 Practice      ]\n"
           "[   1006: C++ Primer, Page 40, 2.10 Practice     ],"
           "[   1007: C++ Primer, Page 45, 2.14 Practice     ]\n"
           "[   1008: C++ Primer, Page 81, 3.2.2 Practice    ],"
           "[   1009: C++ Primer, Page 86, 3.2.3 Practice    ]\n"
           "";
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
        case 1005:
            testPage35$$2_3_practice();
            break;
        case 1006:
            testPage40$$2_10_practice();
            break;
        case 1007:
            testPage45$$2_14_practice();
            break;
        case 1008:
            testPage81$$3_2_2practice();
            break;
        case 1009:
            testPage86$$3_6_practice();
            break;
        default:
            cout << "没有与数值[" << &pValue << "]对应的测试函数" << endl;
            break;
    }

}

