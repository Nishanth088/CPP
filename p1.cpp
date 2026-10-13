#include<iostream>
using namespace std;
void swapRef(int &a, int &b){
    int t=a;a=b;b=t;
}
void swapPtr(int *a,int *b){
    int t=*a;*a=*b;*b=t;
}
int main(){
    int x=10;int y=20;
    swapRef(x,y);{
        cout << "After SwapRef X= " << x<< " Y= "<< y << endl;
    }
    swapPtr(&x,&y);{
        cout << "After SwapRef X= " << x<< " Y= "<< y << endl;
    }
    int &alias=x;
    alias=99;
    cout << "X via alias =" << x << endl;


}