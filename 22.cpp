#include <iostream>
using namespace std;

void logmsg(const string &msg,int level=1){
    const string tag[]={"","Info","Warn","Error"};
    cout << "[" << tag[level] << "]" << msg << endl;
}
double interest(double principal,double year,double rate=7.5)
{
    return(principal*year*rate)/100.0;
}

int main(){
    logmsg("System started");
    logmsg("low memory",2);

    cout << "Interest " << interest(10000,2)<< endl;
    cout << "Interest "<< interest(10000,2,9.0)<<endl;
}