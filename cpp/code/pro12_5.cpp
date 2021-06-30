#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    vector<double> b;
    int Min(vector<int> a);
    double Min(vector<double> b);

    cout << "请输入一组整数：";
    int temp_1;
    while (cin >> temp_1)
    {
        a.push_back(temp_1);
        if (cin.get() == '\n')
            break;
    }

    cout << "请输入一组实数：";
    double temp_2;
    while (cin >> temp_2)
    {
        b.push_back(temp_2);
        if (cin.get() == '\n')
            break;
    }

    cout << "一组整数中的最小实数：" << Min(a) << endl;
    cout << "一组实数中的最小整数：" << Min(b) << endl;
    system("pause");
    return 0;
}

int Min(vector<int> a)
{
    int min = a[0];
    for (unsigned int i = 1; i < a.size(); i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min; //返回最小值
}
double Min(vector<double> b)
{
    double min = b[0];
    for (unsigned int i = 1; i < b.size(); i++)
    {
        if (b[i] < min)
            min = b[i];
    }
    return min; //返回最小值
}