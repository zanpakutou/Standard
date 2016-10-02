#include <bits/stdc++.h>

using namespace std;

#define long long long

typedef pair<long, long> ii;
typedef pair<long, ii> triple;
#define X first
#define Y second

ii extended_gcd(long a, long b){
    ii trans;
    if (b==0) return ii(1, 0);
    else {
        trans =  extended_gcd(b, a%b);
        return ii(trans.Y, trans.X  -  a / b * trans.Y);
    }
}

long gcd(long a, long b){
    if ( a==0 ) return b;
        else return gcd(b%a, a);
}

main(){
    long a, b;
    ii tulos;
    srand(time(0));
    while(1){
        cin>>a >> b;
        tulos = extended_gcd(a, b);
        printf("a * %lld   +  b * %lld  =  %lld\n", tulos.X, tulos.Y, gcd(a, b));
    }
}
