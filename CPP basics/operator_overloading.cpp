#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
class complex
{
    int real, img;

public:
    complex()
    {
        real = 0;
        img = 0;
    }
    complex(int a, int b)
    {
        real = a;
        img = b;
        cout << endl;
        display();
    }
    void display()
    {
        cout << real << " + " << img << " i " << endl;
    }
    complex operator+(complex b)
    {
        return complex(real + b.real, img + b.img);
    }
    complex operator*(complex b)
    {
        int val1, val2, val3, val4;
        val1 = real * b.real;
        val2 = real * b.img;
        val3 = img * b.real;
        val4 = -(img * b.img);
        return complex(val1 + val4, val2 + val3);
    }
    friend complex operator-(complex a, complex b);
};
complex operator-(complex a, complex b)
{
    return complex(a.real - b.real, a.img - b.img);
}

int main()
{
    complex a(1, 2);
    complex b(2, 3);
    complex c;
    c = a + b;
    c.display();
    complex d;
    d = a - b;
    d.display();
    d = a * b;
    d.display();
    return 0;
}