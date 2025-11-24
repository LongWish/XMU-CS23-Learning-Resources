#include<iostream>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
class MyComp
{//让map按照绩点降序排序
public:
    bool operator()(float v1, float v2)
    {
        return v1 > v2;
    }
};
float getGPA(int score)
{
    // 绩点与分数的对应关系
    if (score >= 90) return 4.0;
    else if (score >= 85) return 3.7;
    else if (score >= 81) return 3.3;
    else if (score >= 78) return 3.0;
    else if (score >= 75) return 2.7;
    else if (score >= 72) return 2.3;
    else if (score >= 68) return 2.0;
    else if (score >= 64) return 1.7;
    else if (score >= 60) return 1.0;
    else return 0.0;
}
map<float, int, MyComp> m;
int line[10] = { 90,85,81,78,75,72,68,64,60,0 };
void make_table()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int d = 0; d < 10; d++)
                {
                    int total = line[i] + line[j] + line[k] + line[d];
                    float gpa = getGPA(line[i]) + getGPA(line[j]) + getGPA(line[k]) + getGPA(line[d]);
                    map<float, int, MyComp>::iterator it = m.find(gpa);
                    if (it == m.end())
                    {
                        m.insert(make_pair(gpa, total));
                    }
                    else
                    {
                        if (it->second > total)it->second = total;
                    }
                }
            }
        }
    }
}
float Get_MAX(int score);
int main()
{
    make_table();
    int total;
    while (cin >> total)
    {
        float res = Get_MAX(total);
        cout << fixed << setprecision(1) << res << endl;
    }
    return 0;
}
float Get_MAX(int score)
{
    map<float, int, MyComp>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->second <= score)return it->first;
    }
    return 0;
}