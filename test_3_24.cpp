#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while(cin >> s){
        int flag=1;
        int letter[26]={0};
        for(int i = 0; i < s.size(); i++)
            letter[s[i]-'a']++;//对输入的字符串的字母计数
        for(int i = 0; i < s.size(); i++)
            if(letter[s[i]-'a']==1){
                cout << s[i] << endl;
                flag = 0;
                break;
            }
        if(flag == 1)
            cout << -1 << endl;
    }
    return 0;
}