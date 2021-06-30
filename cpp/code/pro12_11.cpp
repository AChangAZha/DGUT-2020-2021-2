#include <iostream>
using namespace std;
class Shape
{
public:
    Shape(int x, int y)
    {
        length = x;
        breadth = y;
    }
    virtual void area()
    {
    }

protected:
    int length;
    int breadth;
};
class Rectangle : public Shape
{
public:
    Rectangle(int x, int y) : Shape(x, y)
    {
    }
    void area()
    {
        cout << "Rectangle:" << endl;
        cout << " length: " << length << endl;
        cout << " breadth: " << breadth << endl;
        cout << " area: " << (length * breadth) << endl;
    }
};
int main()
{
    Rectangle r(3, 5);
    r.area();
    system("pause");
    return 0;
}