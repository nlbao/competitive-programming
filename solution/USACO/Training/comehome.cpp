/*
    ID: storm59061
    LANG: C++
    TASK: comehome
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct N{
    int n, d;
};
bool operator<(const N& a, const N& b){
    return a.d<b.d;
}
int main() {

    freopen("comehome.in", "r", stdin), freopen("comehome.out", "w", stdout);
    char c1, c2;
    int n, di, g[300][300] ={{0}}, d[300]={0}, INF=1<<30;
    fill(d, d+299, INF);
    priority_queue<N> q;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++, getchar()) {
        scanf("%c %c %d", &c1, &c2 , &di);
        g[c1][c2] = g[c2][c1] = min(di, g[c1][c2]?g[c1][c2]:INF);
    }
    N best{'Z', INF};
    q.push(N{'Z', d['Z']=0});
    while(q.size()){
        N n = q.top();  q.pop();
        if(n.n>='A' && n.n<'Z' && n.d<best.d) best =  n;
        for(int b='A'; b<'Z'; b++)
            if(g[n.n][b] && d[b] >d[n.n]+g[n.n][b])  q.push(N{b, d[b]=d[n.n]+g[n.n][b]});
        for(int b='a'; b<='z'; b++)
            if(g[n.n][b] && d[b] >d[n.n]+g[n.n][b])  q.push(N{b, d[b]=d[n.n]+g[n.n][b]});
    }

    printf("%c %d\n", char(best.n), best.d);
    return 0;
}
