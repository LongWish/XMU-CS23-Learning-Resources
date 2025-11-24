#include <iostream>
using namespace std;
int main()
{
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int d = 0;
        for (int i = 1; i < month; i++)
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                d = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                d = 30;
                break;
            case 2:
                d = 29;
                break;
            }
            day += d;
        }
        cout << day << endl;
    }
    return 0;
}