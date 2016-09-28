#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > ii;

const int inf = 1000000000;

vector< ii > a[1503];

int d[1503], n, m, u, v, c;

void Dijtrka()
{
    priority_queue< ii, vector<ii>, greater< ii > > q;
    for(int i = 1; i<=n; i++) d[i] = inf;
    d[1] = 0;
    q.push(ii(0,1));
    while(!q.empty()){
        int u = q.top().second;
        int d_u = q.top().first;
        q.pop();
        if (d[u]!=d_u) continue;
        for(int i = 0; i< a[u].size(); i++){
            int v = a[u][i].first;
            int c = a[u][i].second;
            if (d[v]> d[u] + c){
                d[v] = d[u] + c;
                q.push(ii(d[v],v));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 1; i<=m; i++)
    {
        cin>>u>>v>>c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }
    Dijtrka();
    cout<<d[4];
}
