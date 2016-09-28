#include <bits/stdc++.h>
#define  FORI(i, v)     for(typeof(v.begin()) i = v.begin(); i!=v.end(); i++)

using namespace std;
string s, w;
int T[1000010];
void make_KMP_table()
{
    T[0] = T[1] = 0;

    for(int i = 2; i<= w.length(); i++)
    {
        int j = T[i-1];
        while(1){
            if (w[j]==w[i - 1]){
                T[i] = j+1;
                break;
            }
            if (j==0){
                T[i] = 0;
                break;
            }
            j = T[j];
        }
    }
    for(int i = 0; i<= w.length(); i++)
        cout<<T[i]<<' ';
}
void _find()
{
    int i = 0, j = 0;
    for(;j<s.length();){
        if (s[j]==w[i]){
            i++;
            j++;
            if (i==w.length()){
                cout<<j - i + 1<<' ';
                i = T[i];
                continue;
            }
        }
        else if (i>0) i = T[i];
        else j++;
    }
}
int main()
{
    cin>>s;
    cin>>w;
    make_KMP_table();
    _find();
}
