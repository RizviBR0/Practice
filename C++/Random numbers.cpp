#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
    for(int i = 1; i<= 10; i++) {
        cout << rand() % 10 + 1 << endl;
    }
}