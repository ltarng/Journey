#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    bool alp=0;
    while( getline(cin, s) )
    {
        int count=0;
        for( int i=0 ; i<s.length() ;i++ )
        {
            if(isalpha(s[i]) && !alp)
            {
                alp = true;
                count++;
            }
            else if(!isalpha(s[i]) && alp) alp = false;
        }
        cout << count << endl ;
    }
    return 0;
}
