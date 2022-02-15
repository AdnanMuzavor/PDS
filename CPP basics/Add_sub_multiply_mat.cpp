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
class mat
{
    int **m;
    int r, c;

public:
    mat() {}
    mat(int a)
    {
        cout << "\n Enter number of rows: ";
        cin >> r;
        cout << "\n Enter number of columns: ";
        cin >> c;
        m = new int *[r];
        for (int i = 0; i < r; i++)
        {
            m[i] = new int[c];
        }
        cout << "Enter matrix elements: \n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << "m[" << i << "][" << j << "] : ";
                cin >> m[i][j];
                cout << " ";
            }
            cout << endl;
        }
        display();
    }
    mat(int rs, int cs, int **arr)
    {
        r = rs;
        c = cs;
        m = new int *[rs];
        for (int i = 0; i < rs; i++)
        {
            m[i] = new int[cs];
        }
        for (int i = 0; i < rs; i++)
        {
            for (int j = 0; j < cs; j++)
            {
                m[i][j] = arr[i][j];
            }
        }
        display();
    }
    void display()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << m[i][j] << "\t";
            }
            cout << endl;
        }
    }

    mat operator+(mat b)
    {
        int **arr;
        arr = new int *[r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new int[c];
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                arr[i][j] = m[i][j] + b.m[i][j];
            }
        }

        return mat(r, c, arr);
    }
    mat operator-(mat b)
    {
        int **arr;
        arr = new int *[r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new int[c];
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                arr[i][j] = m[i][j] - b.m[i][j];
            }
        }

        return mat(r, c, arr);
    }
    mat operator*(mat b)
    {
        int **arr;
        if (c != b.r)
        {
            cout << "Multiplication not possible\n";
        }
        else
        {
            cout << "Multiplying" << endl;
            arr = new int *[r];
            for (int i = 0; i < r; i++)
            {
                arr[i] = new int[b.c];
            }
            // number of rows of first matrix
            for (int i = 0; i < r; i++)
            {
                // no of cols of second matrix
                for (int j = 0; j < b.c; j++)
                {
                    arr[i][j] = 0;
                    // or it can be cols of a as well
                    for (int n = 0; n < b.r; n++)
                    {
                        arr[i][j] += m[i][n] * b.m[n][j];
                    }
                }
            }
        }
        return mat(r, b.c, arr);
    }
};

int main()
{
    mat m(0);
    mat m2(0);
    mat m3;
    // m3=m+m2;
    m3 = m * m2;

    return 0;
}