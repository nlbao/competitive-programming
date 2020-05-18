/*
    ID: storm59061
    LANG: C++
    TASK: preface
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

char s[10]=" IVXLCDM";
int n, c[10] = {0} ,delta[10][5] = {{},{-1,-10},{-1,-1,-10},{-1,-1,-1,-10},{0,-1,-10}, {0, -10},{0,-1,-10},{0,-1,-1,-10},{0,-1,-1,-1,-10},{1,-1,-10} };

int main() {
#ifndef ONLINE_JUDGE
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
#endif
    scanf("%d", &n);
    foru(p,1,n)
        foru(e,1,4) {
            int d = int(p/(round(pow(10, e-1))))%10;
            if(!d) continue;
            for(int i=0; delta[d][i]!=-10; i++)
                c[2*e +delta[d][i]]++;
        }
    for(int i=1; i<=7 && c[i]; i++)
        cout << s[i] << " " << c[i]<<endl;
    return 0;
}
