#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;

int n;
double G[MAXN][MAXN];

void Input()
{
    cin>>  n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<= (n+1); j++)
            cin>> G[i][j];
}
void print()
{

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= (n+1); j++)
            cout<< G[i][j]<<' ',cout<<setw(7);
        cout<<'\n';
    }
    for(int i = 1; i<=20; i++) cout<<'*';
    cout<<'\n';
}
void Gauss() {
	for (int i = 1; i <= n; ++i) {
		double temp = 0;
		int pos = -1;
		for (int j = i; j <= n; ++j) {
			if (fabs(G[j][i]) > temp) temp = fabs(G[j][i]), pos = j;
		}
		if (pos == -1) continue;
		for (int k = 1; k <= n + 1; ++k) swap(G[pos][k], G[i][k]);
		temp = G[i][i];
		for (int k = 1; k <= n + 1; ++k) G[i][k] /= temp;
		for (int j = i + 1; j <= n; ++j) {
			temp = G[j][i];
			for (int k = 1; k <= n + 1; ++k) G[j][k] -= temp * G[i][k];
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j < i; ++j) {
			G[j][n + 1] -= G[i][n + 1] * G[j][i];
			G[j][i] = 0;
		}
	}
}
void Output()
{
    for(int i = 1; i<=n; i++)
        cout<<" X_"<<i<<"  =  "<<G[i][n+1]<<"\n\n";
}
int main()
{
    Input();
    Gauss();
    Output();
    return 0;
}
/*
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
*/
