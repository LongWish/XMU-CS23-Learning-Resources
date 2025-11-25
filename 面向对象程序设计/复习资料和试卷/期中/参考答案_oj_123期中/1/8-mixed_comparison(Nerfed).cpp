#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm> // 引入算法库
#include <vector>
using namespace std;

int convertToDecimal(const string& num, int base) {
    int result = 0;
    for (char c : num) {
        int value;
        if (isdigit(c)) value = c - '0'; // 数字字符 0-9
        else value = 10 + c - 'a';  // 字母 a-f
        result = result * base + value;
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> numbers;
    int i = 0, n = s.length();
    while (i < n) {
        int base = 10; // 先判断是几进制，默认十进制
        if (s[i] == '0') {
            if (i + 1 < n && s[i + 1] == 'b') {
                base = 2; // 二进制
                i += 2;
            }
            else if (i + 1 < n && s[i + 1] == 'x') {
                base = 16; // 十六进制
                i += 2;
            }
            else {
                base = 8; // 八进制
                i += 1;
            }
        }
        string num = "";
        while (i < n && s[i] != ',') {
            num += s[i];
            i++;
        }
        numbers.push_back(convertToDecimal(num, base)); // 计算数值
        i++; // 跳过逗号
    }

    sort(numbers.begin(), numbers.end()); // 使用sort进行排序

    for (int i = 0; i < numbers.size(); i++) {
        if (i > 0) cout << ",";
        cout << numbers[i];
    }

    return 0;
}