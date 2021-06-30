#include <iostream>
using namespace std;
int main()
{
    double l, w, c, s;
    cout << "请输入长方形的长：";
    cin >> l;
    cout << "请输入长方形的宽：";
    cin >> w;
    c = 2 * (l + w);
    s = l * w;
    cout << "长方形周长=" << c << endl;
    cout << "长方形面积=" << s << endl;
    system("pause");
    return 0;
}