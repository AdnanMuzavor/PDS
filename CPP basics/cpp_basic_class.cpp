#include <iostream>
#include <string>
#define PI 3.1415
#define e 8.8542
#define INT_MAX 10000000
#define INT_MIN -1000000
using namespace std;
// EMPLOYEE CLASS
class Employee
{
    int basicsalary;
    int bonus;

public:
    Employee(int b1, int b2)
    {
        basicsalary = b1;
        bonus = b2;
    }
    int calculatepay()
    {
        return basicsalary + bonus;
    }
    void addmore()
    {
        int hra, da;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "\nEnter DA: ";
        cin >> da;
        int total = hra + da + (basicsalary + bonus);
        cout << "Total pay : " << total << endl;
    }
};
// CLASS BANK
class bank
{
    char name[30];
    int accno;
    string acctype;
    int balamt;

public:
    bank()
    {
        cout << "\nEnter account holder's name: ";
        cin.getline(name, 30);
        cout << "\n Enter account no: ";
        cin >> accno;
        cout << "\nEnter acc type: ";
        cin >> acctype;
        cout << "Enter bal amount: ";
        cin >> balamt;
        cout << endl;
        display();
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account number: " << accno << "\t Account type: " << acctype << endl;
        cout << "Balance amount: " << balamt << endl;
    }
    void deposit()
    {
        int amt;
        cout << "Enter amt you want to deposit: ";
        cin >> amt;
        balamt = balamt + amt;
        display();
    }
    void withdraw()
    {
        cout << "\nAvailable balance: " << balamt << endl;
        int withdr;
        cout << "\nEnter amount you want to withdraw: ";
        cin >> withdr;
        if (withdr > balamt)
            cout << "Invalid amount\n"
                 << endl;
        else
        {
            balamt = balamt - withdr;
            display();
        }
    }
};
int main()
{
    // EXP2PROG1
    //  Employee e1(10,20);
    //  cout<<e1.calculatepay()<<endl;
    //  e1.addmore();

    // EXP2PROG4
    bank b1;
    b1.deposit();
    b1.withdraw();
    return 0;
}