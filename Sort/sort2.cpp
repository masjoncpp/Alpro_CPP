//Title : bermain dua bilangan
//Made by : A11.2024.16048
//Modify : 12 March 2025
#include<iostream>
using namespace std;
//declare(Kamus)
int a,b,tmpt;
//describ
main()
{
    cout<<"Program 2 Bilangan"<<endl;
    cout<<"Masukkan A : "; cin>>a;
    cout<<"Masukkan B : "; cin>>b;

    cout<<"bilangan A adalah :" << a << endl;
    cout<<"bilangan B adalah :" << b <<endl;

//proses komparasi
if(a>b){
    cout<<"Bilangan A lebih besar daripada Bilangan B";
}
    else if(a<b)
        cout<<"Bilangan B lebih besar daripada A";
    else{
        cout<<"Kedua Bilangan adalah SAMA!";
    }
}
