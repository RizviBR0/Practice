#include<iostream>
using namespace std;

void Line()              //Function[1]
{
    for(int L=1; L<=80; L++) cout<<"-";
    cout<<endl;
}

void Line(int N)         //Function[2]
{
    for(int L=1; L<=N; L++) cout<<"*";
    cout<<endl;
}
                                  
void Line(char C, int N)         //Function[3]
{
    for(int L=1; L<=N; L++) cout<<C;
    cout<<endl;
}

void Line(int M, int N)         //Function[4]
{
    for(int L=1; L<=N; L++) cout<<M*L;
    cout<<endl;
}

int main()
{
    int A=9, B=4, C=3;
    char K='#';
    Line(K, B);
    Line(A, C);
}