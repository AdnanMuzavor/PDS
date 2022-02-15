#include <iostream>
#include<string.h>
using namespace std;
class STRING{
    char str[50];
    int len;
    public:
    STRING(){
        cout<<"Enter the string: ";
        cin.getline(str,50);
        len=strlen(str);
        display();
    }
    void display(){
        cout<<"String is: "<<str<<" with length: "<<len<<endl;
    }
    STRING(char* s){
        strcpy(str,s);
        len=strlen(str);
        display();
    }
    STRING operator+(STRING s){
        int l=len+strlen(s.str);
        char newstr[l+1];
        strcpy(newstr,str);
        strcat(newstr,s.str);
        return STRING(newstr);
        
    }
    void operator <<(int a){
        int n=a;
        while(a--){
            char fchar=str[0];
            for(int i=1;i<len;i++){
                str[i-1]=str[i];
            }
            str[len-1]=fchar;
        }
        cout<<"String after shifting to left: "<<n<<" times is: "<<endl;
        cout<<str<<endl;
    }
       void operator >>(int a){
        int n=a;
        while(a--){
            char lchar=str[len-1];
            for(int i=len-1;i>=1;i--){
                str[i]=str[i-1];
            }
            str[0]=lchar;
        }
        cout<<"String after shifting to right: "<<n<<" times is: "<<endl;
        cout<<str<<endl;
    }
};
int main()
{
    cout<<"Hello World";
    STRING s1;
    STRING s2;
    STRING s3;
    s3=s1+s2;
    s1<<2;
    s1>>2;
    return 0;
}