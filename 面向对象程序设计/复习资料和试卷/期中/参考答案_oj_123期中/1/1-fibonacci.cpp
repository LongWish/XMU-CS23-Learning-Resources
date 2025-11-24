#include <iostream>
using namespace std;

int main() {
    int n; // 表示有n组数据输入
    cin >> n; // 读入数据组数n
    int total[n]; // 用来存储每组数据的斐波那契数列和

    for (int i = 0; i < n; i++) {
        int a, b, l, r;
        cin >> a >> b >> l >> r; // 读入每组数据的斐波那契数列的前两个数a和b，以及求和的区间[l, r]

        int arr[r + 1]; // 创建一个数组来存储斐波那契数列，大小为r+1
        arr[0] = a; // 初始化第一个元素为a
        arr[1] = b; // 初始化第二个元素为b
        for (int j = 2; j <= r; j++) {
            arr[j] = (arr[j - 1] + arr[j - 2]) % 1000; // 计算从第3个到第r个斐波那契数的值，并取1000的模
        }

        total[i] = 0; // 初始化第i组数据的斐波那契数列和为0
        for (int j = l; j <= r; j++) {
            total[i] += arr[j]; // 计算第i组数据在区间[l, r]的斐波那契数列和
        }
    }

    for (int i = 0; i < n; i++) {
        cout << total[i] % 1000 << endl; // 输出每组数据的斐波那契数列和的1000模
    }

    return 0;
}
