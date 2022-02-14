/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
// ADDITIONS
int add(int a, int b) { return a + b; }
float add(int a, double b) { return a + b; }
float add(double a, int b) { return a + b; }
float add(double a, double b) { return a + b; }
// AREAS
float area(float r)
{
    return PI * pow(r, 2);
}
float area(float a, float b)
{
    return a * b;
}
float area(float s1, float s2, float s3)
{
    float s = (s1 + s2 + s3) / 2;
    float ans1 = s * (s - s1) * (s - s2) * (s - s3);
    return sqrt(ans1);
}
// VOLUMES
float volume(float r)
{
    return (4 * PI * pow(r, 3)) / 3;
}
float volume(float r, float h)
{
    return (1 * PI * pow(r, 2) * h) / 3;
}
float volume(float l, float b, float h)
{
    return l * b * h;
}
int main()
{
    cout << "Hello World";
    // cout<<add(1,2)<<endl;
    // cout<<add(1,2.2)<<endl;
    // cout<<add(3.2,1)<<endl;
    // cout<<add(2.8,1.2)<<endl;
    // cout<<"Area of circle: "<<area(3.1)<<endl;
    // cout<<"Area of rect: "<<area(1.2,2.2)<<endl;
    // cout<<"Area of traingle: "<<area(2,3,4)<<endl;
    cout << "Volume of sphere: " << volume(3.14) << endl;
    cout << "Volume of cone: " << volume(3.14, 3) << endl;
    cout << "Volume of cuboid: " << volume(1.2, 3.4, 5.6) << endl;
    return 0;
}