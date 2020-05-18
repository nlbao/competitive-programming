/*
    ID: storm59061
    LANG: C++
    TASK: sprime
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

int nP = 0;
bool is_prime[MAX_P];
int p[MAX_P];

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

void tryf(int len, int pos, int num) {
    if (pos > len) {
        printf("%d\n",num);
        return;
    }
    if (pos == 1) tryf(len,2,2);
    for(int i = 1; i < 10; i += 2) {
        int x = num*10 + i;
        if (check_prime(x))
            tryf(len, pos+1, x);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
#endif
    init_prime();
    int n = read();
    tryf(n,1,0);
    return 0;
}
