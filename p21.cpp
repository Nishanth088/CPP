#include<iostream>
using namespace std;
inline int square(int x)
{ 
    return x*x;
}
double area(double r){
    return 3.14159*r*r;
}
int area(int b,int h){
    return b*h;
}
double area(double l,double b){
    return 0.5*l*b;
}
int main(){
    cout << "Square(6) :" << square(6)<<endl;
    cout << "Circle(2)) :" << area(2.0)<<endl;
    cout << "Rectangle(4x5) :" << area(4,5)<<endl;
    cout << "Tringle(3.0,8.0) :" << area(3.0,8.0)<<endl;

}