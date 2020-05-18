#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
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

const int MAX_N = 25;

string s;
string name[MAX_N], party[MAX_N];
int c[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("L.in", "r", stdin);
    freopen("L.out", "w", stdout);
#endif
    int n = read();
    getline(cin, s);
    rep(i, n) {
    	getline(cin, name[i]);
    	getline(cin, party[i]);
    	c[i] = 0;
    	//cout << name[i] << "        " << party[i] << endl;
    }

    int m = read();
    getline(cin, s);
    rep(i, m) {
    	getline(cin, s);
    	rep(i, n)
    		if (s == name[i]) {
    			++c[i];
    			break;
    		}
    }

    int maxC = 0, cc = 0, id;
    rep(i, n)
    	if (c[i] > maxC) {
    		maxC = c[i];
    		cc = 1;
    		id = i;
    	}
    	else if (c[i] == maxC) ++cc;

    if (maxC && cc < 2) cout << party[id] << endl;//printf("%s",party[id]);
    else printf("tie");
    return 0;
}