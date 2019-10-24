/**     A2K44 - PBC     **/
#include <bits/stdc++.h>

using namespace std;

const int MAXL  =   1501 ;
const int MAXC  =   128  ;

int n, to[MAXL][MAXC], link[MAXL], word[MAXL], __size = 1;
bool leaf[MAXL];
string t;

///Built searching machine

void init_tree()
{
    memset(to, 0, sizeof(to));
    memset(link, 0, sizeof(link));
    memset(word, 0, sizeof(word));
    memset(leaf, 0, sizeof(leaf));
}

void add_str(string s, int id)
{
    int cur = 0;
    int c;
    for(int i = 0; i < s.length(); i++){
        c = (int)s[i];
        if (to[cur][c] == 0)    to[cur][c] = __size++;
        cur = to[cur][c];
        //cerr<< cur << ' ' << char(c) <<'\n';
    };
    leaf[cur] = 1;
    word[cur] = id;
}
void push_link()
{
    queue< int > q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();     q.pop();
        int v = link[cur];
        leaf[cur]|= leaf[v];
        for(int i = 1; i <= 127; i++)
            if (to[cur][i]){
                link[to[cur][i]] = ((cur!=0) ? to[v][i] : 0);
                q.push(to[cur][i]);
            }   else    to[cur][i] = to[v][i];
    }
}
int search_str(string s)
{
    int cnt = 0, cur = 0, c;
    for(int i = 0; i < s.length(); i++){
        c = (int)s[i];
        cur = to[cur][c];
        int v = cur;
        while(leaf[v]){
            cerr<< v <<'\n';
            if (word[v]) cnt++;
            v = link[v];
        }
    }
    return cnt;
}

///

int main()
{
     #ifdef _ONLINE_JUDGE_
        freopen("find_pattern.inp","r",stdin);
        freopen("find_pattern.out","w",stdout);
    #endif // _ONLINE_JUDGE_
    init_tree();
    getline(cin, t);
    scanf("%d", &n);
    string s;
    for(int i = 1; i <= n; i++){
        cin>> s;
        add_str(s, i);
    }
    push_link();
    cout<< search_str(t);
}
