#include <iostream>
#define PI 3.1415
#define e 8.8542
#define INT_MAX 10000000
#define INT_MIN -1000000
using namespace std;
int min(int a,int b){
    if(a<b) return a;
    return b;
}
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int main()
{
    cout<<"\nCALCULATIONS: \n";
    int q1,q2,r1,r2;
    cout<<"enter q1 ,q2 ,r1,r2\n"<<endl;
    cin>>q1>>q2>>r1>>r2;
    float result=(float)(q1*q2*r2)/(float)(4*PI*e*r1*r1);
    cout<<"res is: "<<result<<endl;
    cout<<"\n LOOPING\n"<<endl;
    int x,n;
    cin>>x>>n;
    cout<<"Multoiples of "<<x<<" from 0 to "<<n<<" are: "<<endl;
    for(int i=0;i<=n;i++){
        if(i%x==0) cout<<i<<" ";
    }
    cout<<"\nMARKS\n"<<endl;
    cout<<"Enter subjects count: ";
    cin>>n;
    cout<<"Enter max marks : ";
    int maxmarks;
    cin>>maxmarks;
    maxmarks=maxmarks*n;
    int *arr=new int[n];
    int total=0,minm=INT_MAX,maxm=INT_MIN;
    for(int i=0;i<n;i++){
        cout<<"Marks in sub no: "<<i+1<<" : ";
        cin>>arr[i];
       
        minm=min(minm,arr[i]);
        maxm=max(maxm,arr[i]);
        total+=arr[i];
        cout<<endl;
    }
    cout<<"maxmarks: "<<maxmarks<<endl;
    cout<<"\n total: "<<total<<endl;
    cout<<"Max marks: "<<maxm;
    cout<<"\nMin marks: "<<minm;
    cout<<"\nAverage: "<<(float)(total/n)<<endl;
    float percent=(total/(float)maxmarks)*100;
    cout<<"\nPercentage: "<<percent<<" %"<<endl;
    delete [](arr);
    return 0;
}