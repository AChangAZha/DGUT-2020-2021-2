#include <iostream>
using namespace std;
int main()
{
    int r, c, j;
    cout << "请输入图形和行数和列数：";
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (j = 1; j <= i - 1; j++)
            cout << " ";
        for (j = 1; j <= c; j++)
            cout << "*";
        cout << endl;
    }
    system("pause");
}