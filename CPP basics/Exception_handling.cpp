/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;
// TYPE-I
int divide(int a, int b)
{
    if (b == 0)
    {
        throw b;
    }
    else
        return a / b;
}
// TYPE-II
int display(int *arr, int len, int index)
{
    if (index >= len)
    {
        throw "Out of bound";
    }
    else
    {
        return arr[index];
    }
}
// TYPE-III
class telephone
{
    char number[10];
    int fixlen;

public:
    telephone()
    {
        fixlen = 6;
        int flag = 1;
        while (flag == 1)
        {
            cout << "Enter 6 chars long telephone number: ";
            cin >> number;
            try
            {
                validate(number, fixlen);
                flag = 0;
            }
            catch (const char *m)
            {
                cout << m << endl;
                flag = 1;
            }
        }
    }
    void validate(char *str, int len)
    {
        if (len < strlen(str) || len > strlen(str))
        {
            throw "Invalid length";
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] - '0' < 0 || str[i] - '0' > 9)
            {
                throw "Invalid characters entered";
            }
        }
    }
};
class marks
{
    int subs[6];

public:
    void validate(int marks)
    {
        if (marks < 0)
        {
            throw "Invalid marks";
        }
    }
    marks()
    {
        int flag = 0, i = 0;

        while (i < 6)
        {
            cout << "Enetr marks for subject no: " << i + 1 << endl;
            cin >> subs[i];
            try
            {
                validate(subs[i]);
                i++;
            }
            catch (const char *m)
            {
                cout << m << endl;
            }
        }
    }
};
int main()
{
    // TYPE-1
    try
    {
        cout << divide(12, 0);
    }
    catch (int d)
    {
        cout << d << "  is equal to 0 so error!!" << endl;
    }
    cout << divide(12, 3);
    // TYPE-2
    int arr[5] = {1, 2, 3, 4, 5};
    try
    {
        cout << display(arr, 5, 4) << endl;
        cout << display(arr, 5, 5) << endl;
    }
    catch (const char *err)
    {
        cout << err << endl;
    }
    // TYPE-3
    telephone t1;
    marks m1;
    return 0;
}