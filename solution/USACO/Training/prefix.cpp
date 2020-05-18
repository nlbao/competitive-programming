/*
    ID: storm59061
    LANG: C++
    TASK: prefix
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

const int MAX_N = 200005;

struct node {
    node *link[26];
    bool is_word;
    node() {
        rep(i,26) link[i] = NULL;
        is_word = false;
    }
};

char s[MAX_N], tmp[80];
node* root;
int f[MAX_N];

int num(char x) {
    return x-'A';
}

void add_string(char* s) {
    int n = strlen(s);
    node* p = root;
    rep(i,n) {
        int x = num(s[i]);
        if (!p->link[x]) p->link[x] = new node();
        p = p->link[x];
    }
    p->is_word = true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
#endif
    root = new node();
    for(;;) {
        scanf("%s",&s);
        if (s[0] == '.') break;
        add_string(s);
    }

    scanf("%s",&s);
    while (scanf("%s",&tmp) != EOF) strcat(s, tmp);
    int n = strlen(s), res = 0;
    fill(f,false);

    node* p = root;
    rep(i,n) {
        p = p->link[num(s[i])];
        if (!p) break;
        f[i] = p->is_word;
    }
    foru(i,1,n-1) {
        if (f[i-1]) res = i;
        else continue;
        p = root;
        foru(j,i,n-1) {
            p = p->link[num(s[j])];
            if (!p) break;
            if (p->is_word) f[j] = true;
        }
    }
    if (f[n-1]) res = n;
    printf("%d\n",res);
    return 0;
}
