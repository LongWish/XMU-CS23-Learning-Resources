
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

string decryptText(const string& encrypted_text, const string& encryption_rule) {
    string original_text = "";
    unordered_map<char, char> decryption_map;

    for (int i = 0; i < 26; ++i) {
        decryption_map[encryption_rule[i]] = 'A' + i;
    }

    for (char encrypted_char : encrypted_text) {
        if (encrypted_char == ' ') {
            original_text += ' ';
        } else {
            original_text += decryption_map[encrypted_char];
        }
    }

    return original_text;
}

int main() {
    string encryption_rule, encrypted_text;
    getline(cin, encryption_rule);
    getline(cin, encrypted_text);

    // 处理多个空格分隔的单词
    //istringstream iss(encrypted_text);创建了一个名为iss的istringstream对象，
    // 并将encrypted_text作为参数传递给它，从而将encrypted_text的内容加载到iss对象中。接下来，你可以使用iss对象像处理输入流一样从字符串中读取数据。可以使用>>操作符从iss中提取数据，并将其存储到其他变量中
    istringstream iss(encrypted_text);
    string word;
    string original_text = "";

    while (iss >> word) {
        original_text += decryptText(word, encryption_rule) + " ";
    }

    // 去除最后一个空格
    original_text.pop_back();

    cout << original_text << endl;

    return 0;
}