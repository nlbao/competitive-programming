#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector< pair<int, int> > vii;
typedef pair< pair<ll,ll>, pair<ll,ll> > segment;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int MAX_N = 100005;


int n;
set<segment> a;
vector<segment> q;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

void get_line(ll x1, ll y1, ll x2, ll y2, double &a, double &b, double &c) {
    a = y1-y2;
    b = x2-x1;
    c = -(a*x1+b*y1);
}

double intersect(segment s, double m) {
    if (m < s.fr.fr || m >= s.sc.fr) return -1;
    double a,b,c;
    get_line(s.fr.fr, s.fr.sc, s.sc.fr, s.sc.sc, a,b,c);
    return -(a*m+c)/b;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("hillwalk.in", "r", stdin);
    freopen("hillwalk.out", "w", stdout);
#endif
    read(n);
    segment p;
    rep(i,n) {
        int x,y,z,t;
        scanf("%d%d%d%d",&x,&y,&z,&t);
        if (i == 0) p = mp(mp(x,y),mp(z,t));
        a.insert(mp(mp(x,y),mp(z,t)));
    }

    int res = 1;
    for(;!a.empty();) {
        double maxY = -1, m = p.sc.fr, limit = p.sc.sc;
        segment tmp;
        bool remove = true;
        q.clear();

        tr(a, it)
            if (*it == p) remove = false;
            else if (it->sc.fr <= m) q.pb(*it);
            else {
                double t = intersect(*it,m);
                if (t >= 0 && t < limit) {
                    if (t > maxY) {
                        maxY = t;
                        tmp = *it;
                    }
                } else if (remove) q.pb(*it);
            }
        if (maxY < 0) break;

        ++res;
        a.erase(p);
        p = tmp;
        tr(q, it) a.erase(*it);
    }
    cout << res;
    return 0;
}
