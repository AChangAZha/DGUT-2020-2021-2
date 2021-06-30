#include <iostream>
using namespace std;
class Date
{
public:
    Date()
    {
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void print();

private:
    int year, month, day;
};
void Date::print()
{
    cout << year << "年" << month << "月" << day << "日" << endl;
}
int main()
{
    Date national_day(1949, 10, 1);
    national_day.print();
    system("pause");
    return 0;
}