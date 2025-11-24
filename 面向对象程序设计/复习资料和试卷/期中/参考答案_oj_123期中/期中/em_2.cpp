#include <iostream>
using namespace std;

int main()
{
    int scholarCount, operationCount, giverIndex, receiverIndex, i, halfBeans, temp;
    int beanCounts[100]; // 使用数组存储每个秀才的红豆数量

    cin >> scholarCount; // 输入秀才的总数

    for (i = 0; i < scholarCount; i++)
    {
        cin >> beanCounts[i]; // 输入每个秀才初始的红豆数量
    }

    cin >> operationCount; // 输入赠送操作的次数
    for (i = 0; i < operationCount; i++)
    {
        cin >> giverIndex >> receiverIndex; // 输入赠送者和接收者的索引（0-based）
        halfBeans = beanCounts[giverIndex] / 2; // 计算赠送者赠送红豆的数量（向下取整）
        beanCounts[giverIndex] -= halfBeans; // 赠送者减去赠送的红豆数量
        beanCounts[receiverIndex] += halfBeans; // 接收者增加赠送的红豆数量
    }

    // 冒泡排序，对秀才的红豆数量进行从大到小排序
    for (i = 0; i < scholarCount; i++)
        for (int j = 0; j < scholarCount - i - 1; j++)
        {
            if (beanCounts[j] < beanCounts[j + 1])
            {
                temp = beanCounts[j];
                beanCounts[j] = beanCounts[j + 1];
                beanCounts[j + 1] = temp;
            }
        }

    // 计算拥有最多和最少红豆数量的秀才之间的红豆数量差
    int maxMinDifference = beanCounts[0] - beanCounts[scholarCount - 1];
    cout << maxMinDifference; // 输出红豆数量差的绝对值

    return 0;
}
