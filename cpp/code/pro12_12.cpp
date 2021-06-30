#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void area()
    {
    }
};
class Circle : public Shape
{
public:
    Circle(int r) : r(r)
    {
    }
    void area()
    {
        s = 3.14 * r * r;
        cout << "圆半径：" << r << "    圆面积：" << s << endl;
    }

private:
    float r, s;
};
class Triangle : public Shape
{
public:
    Triangle(int w, int h) : w(w), h(h)
    {
    }
    void area()
    {
        s = 0.5 * w * h;
        cout << "三角形底边：" << w << "    三角形高：" << h << "    三角形面积：" << s << endl;
    }

private:
    float w, h, s;
};
int main()
{
    Circle c(5);
    Triangle t(3, 4);
    c.area();
    t.area();
    system("pause");
    return 0;
}
