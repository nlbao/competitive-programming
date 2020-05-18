/*
    ID: storm59061
    LANG: C++
    TASK: pprime
*/
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

const int MAX_P = 10004;
const int MAX_N = 100000008;

int a, b, nP = 0;
bool is_prime[MAX_P];
int p[MAX_P], res[10];


int num_len(int n) {
    stringstream convert;
    convert << n;
    string s = convert.str();
    return size(s);
}

void init_prime() {
    fill(is_prime,true);
    is_prime[0] = is_prime[1] = false;
    foru(i,2,MAX_P-1) if (is_prime[i]) {
        p[nP++] = i;
        int j = i*i;
        while (j < MAX_P) {
            is_prime[j] = false;
            j += i;
        }
    }
}

bool check_prime(int n) {
    if (n < MAX_P) return is_prime[n];
    if (n%2 == 0 || n%3 == 0) return false;
    rep(i,nP) {
        int x = p[i];
        if (x*x > n) break;
        if (n%x == 0) {
            return false;
        }
    }
    return true;
}

void tryf(int len, int l) {
    int r = len-l+1;
    if (l > r) {
        int n = 0;
        foru(i,1,len) n = 10*n + res[i];
        if (a <= n && n <= b && check_prime(n))
            printf("%d\n", n);
        return;
    }
    rep(x,10) {
        if (l == 1 && x%2 == 0) continue;
        res[l] = res[r] = x;
        tryf(len, l+1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
#endif
    init_prime();
    scanf("%d%d",&a,&b);
    int l1 = num_len(a), l2 = num_len(b);
    foru(len,l1,l2)
        tryf(len,1);
    return 0;
}
