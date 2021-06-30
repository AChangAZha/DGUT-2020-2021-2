#include <iostream>
using namespace std;
class Square
{
public:
    Square(float d = 0)
    {
        r = d;
    }
    void perimeter()
    {
        p = 4 * r;
    }
    void area()
    {
        s = r * r;
    }
    void print();

private:
    float r, p, s;
};
void Square::print()
{
    cout << "边长：" << r << endl;
    cout << "周长：" << p << endl;
    cout << "面积：" << s << endl;
}
int main() //主函数
{
    Square square(4.0);
    square.perimeter();
    square.area();
    square.print();
    system("pause");
    return 0;
}