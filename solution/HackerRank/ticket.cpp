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
#define size(a) int(a.size())
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

const int MAX_N = 502;
const int MAX_M = 11;
const int MAX_K = 102;
const int MAX_S = 55;
const double oo = 5000000;
const ll BASE = 10007LL;

int n, m, k;
char place[MAX_K][MAX_S];
int des[MAX_N], price[MAX_K];
int id[MAX_M], w[MAX_N], window[MAX_N];
int count_des[MAX_N][MAX_K];
double sum, res;
double minS[MAX_N];
map<ll,double> f[MAX_N];
ll pre;


void enter() {
    scanf("%d%d%d",&n,&m,&k);
    foru(i,1,k) scanf("%s%d",&place[i],&price[i]);
    foru(i,1,n) {
        char s[MAX_S];
        scanf("%s",&s);
        foru(j,1,k)
            if (strcmp(s, place[j]) == 0) {
                des[i] = j;
                break;
            }
    }
}

ll h() {
    ll x = 0;
    foru(i,1,m) x = BASE*x + ll(id[i]);
    return x;
}

bool cmpf(int i, ll x, double value) {
    return f[i].find(x) == f[i].end() || value < f[i][x];
}

void tryf(int i) {
    if (sum >= res) return;
    if (sum+minS[i] >= res) return;
    if (i > n) {
        res = sum;
        foru(j,1,n) window[j] = w[j];
        return;
    }
//1
    foru(j,1,min(i-1,m))
        if (id[j] == des[i]) {
            w[i] = j;
            double cost = price[des[i]]*0.8;
            sum += cost;
            ll x = pre;
            if (cmpf(i, x, sum)) {
                f[i][x] = sum;
                tryf(i+1);
            }
            sum -= cost;
            return;
        }
//2
    foru(j,1,min(i,m))
        if (count_des[i][id[j]] == 0) {
            w[i] = j;
            int tmp = id[j];
            double cost = price[des[i]];
            id[j] = des[i];
            sum += cost;
            ll x = h();
            if (cmpf(i, x, sum)) {
                f[i][x] = sum;
                tryf(i+1);
            }
            sum -= cost;
            id[j] = tmp;
            return;
        }
//3
    foru(j,1,min(i,m)) {
        w[i] = j;
        int tmp = id[j];
        double cost = price[des[i]];
        if (id[j] == des[i]) cost *= 0.8;

        id[j] = des[i];
        sum += cost;

        ll x = h();
        if (cmpf(i, x, sum)) {
            f[i][x] = sum;
            pre = x;
            tryf(i+1);
        }

        sum -= cost;
        id[j] = tmp;
    }
}


void solve_2() {
    res = oo;
    sum = 0;
    fill(id,0);
    tryf(1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("ticket.in", "r", stdin);
    freopen("ticket.out", "w", stdout);
#endif
    enter();
    fill(count_des, 0);
    minS[n+1] = 0;
    ford(i,n,1) {
        minS[i] = minS[i+1] + 0.8*price[des[i]];
        foru(j,1,k)
            count_des[i][j] = count_des[i+1][j] + int(des[i] == j);
    }

    solve_2();
    printf("%.3f\n",res);
    foru(i,1,n) printf("%d\n",window[i]);
    return 0;
}
