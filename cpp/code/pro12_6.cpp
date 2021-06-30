#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    vector<double> b;
    int count(vector<int> a, double aAvg);
    int count(vector<double> b, double bAvg);
    cout << "请输入一组整数：";
    int temp_1;
    int asum = 0;
    while (cin >> temp_1)
    {
        a.push_back(temp_1);
        asum = asum + temp_1;
        if (cin.get() == '\n')
            break;
    }
    double aAvg = asum * 1.0 / a.size();
    cout << "请输入一组实数：";
    double temp_2;
    double bsum = 0;
    while (cin >> temp_2)
    {
        b.push_back(temp_2);
        bsum = bsum + temp_2;
        if (cin.get() == '\n')
            break;
    }
    double bAvg = bsum * 1.0 / b.size();
    cout << "一组整数中超过平均值的数据个数：" << count(a, aAvg) << endl;
    cout << "一组实数中超过平均值的数据个数：" << count(b, bAvg) << endl;
    system("pause");
    return 0;
}

int count(vector<int> a, double aAvg)
{
    int count = 0;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        if (a[i] > aAvg)
            count++;
    }
    return count;
}
int count(vector<double> b, double bAvg)
{
    int count = 0;
    for (unsigned int i = 0; i < b.size(); i++)
    {
        if (b[i] > bAvg)
            count++;
    }
    return count;
}