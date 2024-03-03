#include <iostream>
using namespace std;

// Base
class father
{
    // Access Specifier
protected:
    string surname = "Ambani";
};

// Inheritence
class son1 : father
{
    // Access Specifier
public:
    string name = "Anant ";
    // Method Overriding
    void display()
    {
        cout << name << surname << endl;
    }
};

// Inheritence
class son2 : father
{
    // Access Specifier
public:
    string name = "Mukesh ";
    // Method Overriding
    void display()
    {
        cout << name << surname << endl;
    }
};

int main()
{
    son1 s;
    son2 s2;
    s.display();
    s2.display();
}