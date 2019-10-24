// CODE BY TDQ A2K44 PBC
#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
const int oo = 1e9+7;

int n, m, Num[N], Low[N], cnt=0;
int fr[N]={0};
bool mark[N]={0};
vector<int> a[N];
stack<int> st;
int Count=0;

void visit(int u) {
    Low[u]=Num[u]=++cnt;
    st.push(u);

    for (int i=0; int v=a[u][i]; i++)
    if (Num[v])
        Low[u]=min(Low[u], Num[v]);
    else {
        visit(v);
        Low[u]=min(Low[u], Low[v]);
    }
    if (Num[u]==Low[u]) {
        Count++;
        int v;
        do {
            v=st.top(); st.pop();
            fr[v]=Count;
            Num[v]=Low[v]=oo;
        } while (v!=u);
    }
}
void pro()
{
     for (int i=1; i<=n; i++) if (!Num[i]) visit(i);
     for(int u=1;u<=n;u++)
        for(int j=0; int v=a[u][j]; j++)
            if (fr[u]!=fr[v]) mark[fr[v]]=1;
    int res=0;
    for(int i=1;i<=Count;i++) if (!mark[i]) res++;
    cout<<res;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    for (int i=1; i<=n; i++)
    a[i].push_back(0);
    pro();
    return 0;
}

