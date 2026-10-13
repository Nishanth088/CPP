#include <iostream>
using namespace std;
int main(){
    string s;
    cout << "Enter a Word :";
    cin >> s;

    cout << "Length :" <<s.length() << endl;
    cout << "upper :";
    for(char c:s) cout << (char)toupper(c);
    cout << endl;

    for(size_t i=0,j=s.size()-1;i<j;++i,--j)
    if (s[i]!=s[j]){
        cout << s <<" is not a palindrome "<<endl;
        break;
        }
    else{
         cout << s << " is a palindrome" << endl;
         break;
        }
    size_t pos=s.find("an");
    if(pos!=string::npos){
        cout << "'an' found at possition "<< pos << endl;
    }       
    else{
        cout << " 'an' not found" << endl;
    }
}