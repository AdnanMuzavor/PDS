/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
#define PI 3.1415
#define e 8.8542
#define INT_MAX 10000000
#define INT_MIN -1000000
using namespace std;
class Rect
{
    int l, b;

public:
    Rect()
    {
        l = 1;
        b = 1;
    }
    Rect(int a, int b)
    {
        l = a;
        this->b = b;
    }
    Rect(Rect &r1)
    {
        l = r1.l;
        b = r1.b;
    }
    void display()
    {
        cout << "l is: " << l << "  b is : " << b << endl;
    }
    ~Rect()
    {
        cout << "D called\n"
             << endl;
    }
};
class Vector
{
    int x;
    int y;

public:
    Vector()
    {
        x = 0;
        y = 0;
        display();
    }
    void display()
    {
        cout << x << " + " << y << " i " << endl;
    }
    Vector(int a, int b)
    {
        x = a;
        y = b;
    }
    // Vector(Vector &v){
    //     x=v.x;
    //     y=v.y;
    // }
    Vector operator*(Vector v)
    {
        int val1 = x * v.x;
        int val2 = x * v.y;
        int val3 = y * v.x;
        int val4 = -(y * v.y);
        int newx = val1 + val4;
        int newy = val2 + val3;
        return Vector(newx, newy);
    }
    friend Vector operator+(Vector a, Vector b);
    ~Vector()
    {
        cout << "Vector work done\n"
             << endl;
    }
};
Vector operator+(Vector a, Vector b)
{
    return Vector(a.x + b.x, a.y + b.y);
}
class Library
{
    char author[30];
    string title;
    int price;
    int stock;

public:
    static int count;
    Library() {}
    Library(char name[30], string title1, int price, int stock)
    {
        cout << "Initialised using parameterised: " << endl;
        cout << "Entry number: " << count + 1 << endl;
        strcpy(author, name);
        title = title1;
        this->price = price;
        this->stock = stock;
        display();
        count++;
    }
    void getdata()
    {
        cout << "Entry number: " << count + 1 << endl;
        cout << "\nEnter title: ";
        cin >> title;
        cout << "Enter author: ";
        cin.getline(author, 30);
        cin.getline(author, 30);
        cout << "\nEnter price: ";
        cin >> price;
        cout << "\n Enter stock: ";
        cin >> stock;
        count++;
        display();
    }
    void display()
    {
        cout << "\n\nAuthor: " << author << " Title: " << title << " Price: " << price << " Stock: " << stock << endl;
    }
};
int Library::count = 0;
int main()
{
    // PROG-1
    //  Rect r1;
    //  r1.display();
    //  Rect r2(12,13);
    //  r2.display();
    //  Rect r3(r2);
    //  r3.display();
    // Rect r4=Rect(10,12);
    // r4.display();

    // PROG-2
    //  Vector v1;
    //  v1.display();
    //  Vector v2(7,2);
    //  v2.display();
    //  Vector v3(3,4);
    //  v3.display();
    //  Vector v5;
    //  v5=v2+v3;
    //  v5.display();
    //  Vector v6;
    //  v6=v2*v3;
    //  v6.display();
    int n = 0, stock = 0, price = 0, ch;
    string title = "";
    char name[30];
    Library l1[10];
    cout << "Enter books in library: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "1->To init via fn\n2->To init via parameterised\nYour choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            l1[i].getdata();
            break;
        case 2:

            cout << "Enter author: ";
            cin.getline(name, 30);
            cout << "\nEnter title: ";
            cin >> title;
            cout << "\nEnter price: ";
            cin >> price;
            cout << "\n Enter stock: ";
            cin >> stock;

            Library lbook(name, title, price, stock);
            l1[i] = lbook;
            break;
            //  default:
            //  cout<<"\nInvalid input\n";
        }
    }
    return 0;
}