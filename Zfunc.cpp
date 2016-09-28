#include <bits/stdc++.h>

using namespace std;

string s;

vector< int > z_function(string s) {
    int n = (int) s.length();
    vector< int > z(n);
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if ((i + z[i] - 1) > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main()
{
    cin>>s;
    vector< int > z;
    z = z_function( s );
    for(int i = 0; i< z.size(); i++)
        cout<<z[i]<<' ';
    return 0;
}

