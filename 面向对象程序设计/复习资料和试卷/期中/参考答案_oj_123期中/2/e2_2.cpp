#include<iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int a[10], n;
        for (int i = 0;; i++)
        {
            a[i] = num % 10;
            num /= 10;
            if (num == 0)
            {
                n = i;
                break;
            }
        }
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < a[i + 1])
            {
                x = 1;
            }
            if (a[i] > a[i + 1] && x == 1)
            {
                x = 2;
                break;
            }
        }
        if (x == 2)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}