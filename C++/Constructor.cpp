#include <iostream>
#include <stdlib.h>
using namespace std;

// Class definition
class student
{
    public:
    int id;
    double gpa;

    // Member function
    void display()
    {
        cout << id << " " << gpa << endl;
    }

    // Parameterized constructor
    student(int x, double y)
    {
        id = x;
        gpa = y;
    }

    // Default constructor
    student()
    {
        cout << "Default constructor" << endl;
    }
};

int main()
{
    student dcon;
    student alim(101, 3.45);
    student jalim(101, 3.45);
    alim.display();
    jalim.display();
}