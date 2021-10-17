#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define lint long long

using namespace std;

typedef complex< long double  > point;

const int MAXN  =   100000 + 10;
const int LOG   =   19;
const long double PI = acos(-1);

namespace fft{
	typedef complex<double> base;
	void fft(vector<base> &v, bool inv){
		int n = v.size();
		vector<base> w(n/2), aux(n);
		for(int i=0; i<n/2; i++){
			int k = i&-i;
			if(i == k){
				double ang = 2 * PI * i / n;
				if(inv) ang *= -1;
				w[i] = base(cos(ang), sin(ang));
			}
			else w[i] = w[i-k] * w[k];
		}
		for(int i=n/2; i; i>>=1){
			aux = v;
			for(int k=0; 2*k<n; k+=i){
				for(int j=0; j<i; j++){
					base a = aux[2*k + j], b = aux[2*k + j + i] * w[k];
					v[k + j] = a + b;
					v[k + j + n/2] = a - b;
				}
			}
		}
		if(inv){
			for(int i=0; i<n; i++){
				v[i] /= n;
			}
		}
	}
	vector<lint> multiply(vector<lint> &v, vector<lint> &w){
		vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
		int n = 1;
		while(n < max(v.size(), w.size())) n <<= 1;
       // DEBUG(n);
		n <<= 1;
		fv.resize(n);
		fw.resize(n);
		fft(fv, 0);
		fft(fw, 0);
		for(int i=0; i<n; i++) fv[i] *= fw[i];
		fft(fv, 1);
		vector<lint> ret(n);
		for(int i=0; i<n; i++) ret[i] = round(fv[i].real());
		return ret;
	}
}

vector< lint > a, b, c;
int n;
void Read()
{
    cin>> n;
    n++;
    int x;
    REP(i, n) cin>> x, a.push_back(x);
    REP(i, n) cin>> x, b.push_back(x);
    //PR0(a, n);
    c = fft::multiply(a, b);

    REP(i, 2 *n - 1) cout<< c[i] <<' ';
    cout<<'\n';
    a.clear();
    b.clear();
}
int main()
{
   // freopen(".inp","r",stdin);

    int T;
    cin>> T;
    //cout<< 1 <<'\n';
    while(T--) Read();
}
