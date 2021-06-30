#include <iostream>
#include <iomanip>
using namespace std;
class Building //基类Buildinging声明
{
public:
    Building(int f, int r, double ft)
    {                 //构造函数
        floors = f;   //层数
        rooms = r;    //房间数
        footage = ft; //总平方英尺数
    }
    void show() //基类成员函数：输出建筑物的层数、房间数和总平方英尺数
    {
        cout << " floors: " << floors << endl;
        cout << " rooms: " << rooms << endl;
        cout << " total area: " << footage << endl;
    }

protected: //基类私有数据成员：层数、房间数和总平方英尺数
    int floors;
    int rooms;
    double footage;
};
class Housing : public Building //派生类Housing声明，公共继承Buinding类
{
public:
    //在两条星线间填入代码，完成派生类Housing的带参构造函数定义, 实现数据
    //成员的初始化,参数名称可自定
    /*********************************************************************/
    Housing(int f, int r, double ft, int bd, int bt) : Building(f, r, ft), bedrooms(bd), bathrooms(bt)
    {
    }
    /*********************************************************************/
    void show() //派生类成员函数：输出建筑物的层数、房间数和总平方英尺数
    {
        cout << "\nHOUSING:\n";
        //在两星线间填入代码，完成成员函数show定义，屏幕输出Housing对象的值
        /*******************************************************************/
        Building::show();
        cout << " bedrooms: " << bedrooms << endl;
        cout << " bathrooms: " << bathrooms << endl;
        /******************************************************************/
    }

private:
    //在两条星线间填入代码，完成私有数据成员bedrooms和bathrooms定义，它们
    //分别用于表示卧室和浴室的数量, 它们都是int型的数据。
    /*********************************************************************/
    int bedrooms, bathrooms;
    /*********************************************************************/
};
int main() //主函数
{
    //在两条星线间填入代码，创建Housing对象hob，并初始化数据成员为(5,7,140,2,2)
    /************************************************************************/
    Housing hob(5, 7, 140, 2, 2);
    /************************************************************************/
    hob.show(); //向hob对象发消息
    return 0;
}
