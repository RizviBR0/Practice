#include <iostream>
using namespace std;

class myclass
{
public:
    int x;
    int y;

    myclass(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void display()
    {
        cout << "a: " << x << " b: " << y << endl;
    }
};

int main()
{
    myclass *obj = new myclass(10, 20);
    obj->display();

    return 0;
}