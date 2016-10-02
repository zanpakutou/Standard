https://vi.wikipedia.org/wiki/Phi_h%C3%A0m_Euler
#include <bits/stdc++.h>

using namespace std;

int T, n;

int Euler(int n)
{
    int tulos  =  n;
    for(int i = 2; i <= sqrt(n); i++)
        if (n%i==0){
            while( n%i == 0 ) n /= i;
            tulos -= tulos / i;
        }
    if (n>1) tulos -= tulos / n;
    return tulos;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<Euler(n)<<'\n';
    }
    return 0;
}
