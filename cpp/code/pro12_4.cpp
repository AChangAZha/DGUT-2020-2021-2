#include <iostream>
using namespace std;
int main()
{
    double x, y, z;
    int a, b;
    int Min(int x, int y);                    //函数声明
    double Min(double x, double y, double z); //函数声明

    cout << "请输入三个实数：";
    cin >> x >> y >> z;
    cout << "请输入两个整数：";
    cin >> a >> b;

    cout << "三个实数中的最小实数：" << Min(x, y, z) << endl;
    //请在两条星线间填入代码，调用min函数求两个整数的最小数
    /*****************************************************/
    cout << "两个整数中的最小整数：" << Min(a, b) << endl;
    /*****************************************************/
    return 0;
}
//定义求2个整数x、y的最小值函数min
//请在两条星线间填入代码，定义min函数的函数首部
/**********************************************/
int Min(int x, int y)
/**********************************************/
{
    int min;

    if (x < y)
        min = x;
    else
        min = y;
    return min; //返回最小值
}
double Min(double x, double y, double z) //定义求3个实数x、y、z的最小值函数
{
    double min;
    //请在两条星线间填入代码，求x、y、z的最小数
    /*****************************************/
    if (x < y)
        min = x;
    else
        min = y;
    if (min > z)
        min = z;
    /*****************************************/
    return min; //返回最小值
}
