#include <iostream>
#include<string.h>
using namespace std;
//hierchical
class Person{
    protected:
  char name[30];
  char address[30];
  char date[12];
  public:
  Person(){
      cout<<"Enter your name: ";
      cin.getline(name,30);
      cin.getline(name,30);
      cout<<"Enter your address: ";
      cin.getline(address,30);
      cout<<"Enter date of birth in DD/MM/YYYY format: ";
      cin.getline(date,12);
     // display();
  }
  void display(){
      cout<<"Name of person is: "<<name<<"\nAddress is : "<<address<<" \nDate is: "<<date<<endl;
  }
};
class Student:protected Person{
    int rollno;
    char classt[20];
    char divv;
    public:
    Student(){
        //Automatically call base class constrcutor
        cout<<"Enter Roll no: ";
        cin>>rollno;
        cout<<"Enter class: ";
        cin.getline(classt,20);
        cin.getline(classt,20);
        cout<<"Enter division: ";
        cin>>divv;
        display();
    }
    void display(){
        Person::display();
        cout<<"Roll no is: "<<rollno<<" \nClass type is: "<<classt<<" \nDivision is: "<<divv<<endl;
    }
};
class Employee:protected Person{
    int empid;
    char desig[30];
    int salary;
    char quaf[30];
    public:
    Employee(){
        cout<<"Enter employee id: ";
        cin>>empid;
        cout<<"Enter designation: ";
        cin>>desig;
        cout<<"Enter salary: ";
        cin>>salary;
        cout<<"Enetr qualification: ";
        cin>>quaf;
        display();
    }
    void display(){
        Person::display();
        cout<<"Emp id is: "<<empid<<"\nDesignation: "<<desig<<"\nSalary: "<<salary<<"\nQualification: "<<quaf<<endl;
    }
};

//MULTIPLE INHERITANCE
class Test{
  protected:
  string subjects[3];
  int marks[3];
  string month;
  int Totalmarks;
  public:
  Test(){
      Totalmarks=0;
      cout<<"Enter subject name and corresponding marks: "<<endl;
      for(int i=0;i<3;i++){
          cout<<" Name: ";
          cin>>subjects[i];
          cout<<"Marks: ";
          cin>>marks[i];
          Totalmarks+=marks[i];
      }
      cout<<"Subject\tMarks"<<endl;
      for(int i=0;i<3;i++){
          cout<<subjects[i]<<"\t"<<marks[i]<<endl;
      }
      cout<<"Total\t"<<Totalmarks<<endl;
  }
};
class Sports{
  protected:
  int sportstotal;
  int sportmarks[2];
  string Event[2];
  public:
  Sports(){
      sportstotal=0;
      cout<<"Enter event name and points scored: ";
      for(int i=0;i<2;i++){
          cout<<"Enter event: ";
          cin>>Event[i];
          cout<<"Enter points: ";
          cin>>sportmarks[i];
          sportstotal+=sportmarks[i];
      }
         cout<<"Event\tMarks"<<endl;
      for(int i=0;i<2;i++){
          cout<<Event[i]<<"\t"<<sportmarks[i]<<endl;
      }
      cout<<"Total\t"<<sportstotal<<endl;
  }
};
class Result:public Test,public Sports{
    int Overall;
    public:
    Result(){
        Overall=Totalmarks+sportstotal;
        cout<<"Over all result is: "<<endl;
        cout<<"Subject marks: "<<Totalmarks<<endl;
        cout<<"Sports marks: "<<sportstotal<<endl;
        cout<<"Total marks obtained are: "<<Overall<<endl;
    }
};
//HYBRID INHERITANCE
class cricketor{
    protected:
    char name[30];
    int age;
    int matchcount;
    public:
    cricketor(){
        cout<<"Enter your name: ";
        cin.getline(name,30);
        cout<<"Age: ";
        cin>>age;
        cout<<"matches played: ";
        cin>>matchcount;
    }
    void display(){
            cout<<"Name: "<<name<<"\nAge: "<<age<<"\nmatch count: "<<matchcount<<endl;        
    }
};
class bowler:virtual public cricketor{
    protected:
    int wickets;
    public:
    bowler(){
        cout<<"Enetr number of wickets: ";
        cin>>wickets;
    }
    void display(){
        cricketor::display();
        cout<<"Wickets taken: "<<wickets<<endl;
    }
};
class batsman:virtual public cricketor{
  protected:
  int runs;
  int count_50;
  int count_100;
  public:
  batsman(){
      cout<<"Enter number of runs: ";
      cin>>runs;
      cout<<"Number of 50s: ";
      cin>>count_50;
      cout<<"Number of 100s: ";
      cin>>count_100;
  }
  void display(){
      cout<<"Number of runs: "<<runs;
      cout<<"\nNumber of 50s: "<<count_50;
      cout<<"\nNumber of 100s: "<<count_100;
  }
};
class Allrounder:virtual public bowler,virtual public batsman{
    public:
    Allrounder(){
        bowler::display();
        batsman::display();
    }
};

//MULTILEVEL INHERITANCE
class Animal{
  protected:
  int legs;
  public:
  Animal(int l){
      legs=l;
      cout<<"I am an animal with "<<legs<<" legs."<<endl;
  }
};
class Eat:public Animal{
    protected:
    int eattimes;
    public:
    Eat(int a,int b):Animal(b){
        eattimes=a;
        cout<<"I can eat "<<eattimes<<" times"<<endl;
    }
};
class Sleep:public Eat{
    protected:
    int sleeptimes;
    public:
    Sleep(int s,int a,int b):Eat(a,b){
        sleeptimes=s;
        cout<<"I sleep "<<sleeptimes<<" in a day"<<endl;
    }
};
class Dog:public Sleep{
    protected:
    int walks;
    public:
    Dog(int a,int b,int c,int d):Sleep(a,b,c){
        walks=d;
        cout<<"I am a Dog"<<"I walk "<<walks<<" times a day"<<endl;
    }
};


int main()
{
    // Student s1;
    // cout<<"STUDENT ENTRY DONE: \n";
    // Employee e1;
    // Employee e2;
    //Result r1;
   // Allrounder r1;
   Dog d(2,3,4,5);
    return 0;
}