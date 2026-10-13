// #include <iostream>
// #include <cctype>
// #include <string>
// using namespace std;
// int main(){
//     string s="verification";
//     cout << "first 4:" <<s.substr(0,4) <<endl;
//     cout << "from 4:" <<s.substr(4)<<endl;

//     int c=s.compare("verify");
//     cout << "compare : verify "<< (c<0 ?"<":c>0 ? ">" : "=") << endl;

//     int freq[26]={0};
//     for(char ch:s)
//     if(isalpha((unsigned char)ch))
//         freq[tolower(ch)-'a']++;

//     cout <<"letter counter ";
//     for(int i=0;i<26;++i){
//         if (freq[i])
//         cout << char('a'+i)<< " : " <<freq[i] << " ";
//     }
//     cout << endl;
// }


#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string s="verification";
    cout << "First 4 :" << s.substr(0,4) << endl;
    cout << "From 4 :" << s.substr(4) << endl;

    int c=s.compare("verify");
    cout << "Comapare vs 'verify' :" << (c<0 ? "<" : c>0? ">" : "=" )<<endl;
int freq[26]={0};
for(char ch:s)
if (isalpha((unsigned char)ch))
freq[tolower(ch)-'a']++;

for(int i=0;i<26;++i)
if(freq[i])
cout<< char('a'+i)<< " : " << freq[i] << " ";
}