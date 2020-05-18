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
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int MAX_N = 100005;
const int BASE = 10007LL;

int n, pos, len, u, v;
char s[MAX_N];
int a[MAX_N];
ll f[4*MAX_N], g[4*MAX_N], p[MAX_N];
ll resf, resg, value;

int num(char x) {
    return x-'a'+1;
}

void init(int k, int l, int r) {
    if (l > r) return;
    if (l == r) {
        f[k] = g[k] = a[l];
        //cout << "      " << k << "      " << l << " " << r << "          " << f[k] << endl;
        return;
    }
    int mid = (l+r)>>1;
    int left = k<<1, right = left+1;
    init(left, l, mid);
    init(right, mid+1, r);
    f[k] = f[left] + f[right]*p[mid-l+1];
    g[k] = g[left]*p[r-mid] + g[right];
    //cout << "      " << k << "      " << l << " " << r << "          " << f[k] << " " << g[k] << endl;
}



void update(int k, int l, int r) {
    if (l > r || l > pos || r < pos) return;
    if (l == r) {
        f[k] = g[k] = value;

        return;
    }
    int mid = (l+r)>>1;
    int left = k<<1, right = left+1;
    update(left, l, mid);
    update(right, mid+1, r);
    f[k] = f[left] + f[right]*p[mid-l+1];
    g[k] = g[left]*p[r-mid] + g[right];
}



void get(int k, int l, int r) {
    if (l > r || l > v || r < u) return;
    if (u <= l && r <= v) {
        resf = resf + f[k]*p[len];
        resg = resg*p[r-l+1] + g[k];
        len += r-l+1;
        //cout << k << "    " << l << " " << r <<"        " << len << endl;
        return;
    }
    int mid = (l+r)>>1;
    int left = k<<1, right = left+1;
    get(left, l, mid);
    get(right, mid+1, r);

    //cout << k << "    " << l << " " << r <<"        " << len << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("I.in", "r", stdin);
    freopen("I.out", "w", stdout);
#endif
    scanf("%s", &s);
    n = strlen(s);
    p[0] = 1;
    foru(i, 1, n) {
        a[i] = num(s[i-1]);
        p[i] = p[i-1]*BASE;
    }

    init(1, 1, n);

    int nQ = read();
    rep(q_id, nQ) {
        scanf("%s", &s);
        //cout << s << endl;
        if (s[0] == 'p') {
            u = read();
            v = read();
            len = resf = resg = 0;
            get(1, 1, n);

            //cout << "     " << resf << " " << resg << endl;

            if (resf == resg) printf("Yes\n");
            else printf("No\n");
            //cout << i << " " << j << endl;
        }
        else {
            scanf("%d", &pos);
            char ch;
            scanf("%c", &ch);
            scanf("%c", &ch);
            value = num(ch);
            update(1, 1, n);
            //cout << pos << " " << ch << endl;
        }
    }
    return 0;
}
