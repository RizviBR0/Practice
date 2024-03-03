#include <iostream>
#include <stdlib.h>
using namespace std;

class student
{
    public:
    int id;
    double gpa;

    void display()
    {
        cout << id << " " << gpa << endl;
    }

    student(int x, double y)
    {
        id = x;
        gpa = y;
    }
};

int main()
{
    student alim(101, 3.45);
    student jalim(101, 3.45);
    alim.display();
    jalim.display();
}