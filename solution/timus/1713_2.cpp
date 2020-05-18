#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

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

const int MAX_N = 1007;
const int MAX_LEN = 107;
const int MAX_A = 27;
const ll BASE = 10007;

struct node {
   int turn, cnt;
   node *link[MAX_A];
   node() {
      turn = -1;
      cnt = 0;
      rep(i,MAX_A) link[i] = NULL;
   }
};

int n, nQ = 0;
char s[MAX_N][MAX_LEN];
int len[MAX_N];
node *root;

int num(char x) { return x-'a';  }

void add(int id) {
   node *p;
   rep(i, len[id]) {
      p = root;
      foru(j, i, len[id]-1) {
         int x = num(s[id][j]);
         if (p->link[x] == NULL) p->link[x] = new node();
         p = p->link[x];
         if (p->turn != id) {
            p->turn = id;
            ++p->cnt;
         }
      }
   }
}

void solve(int id) {
   int res = len[id], pos = 0;
   node *p;
   rep(i, len[id]) {
      p = root;
      foru(j, i, len[id]-1) {
         p = p->link[num(s[id][j])];
         if (p->cnt < 2) {
            res = j-i+1;
            pos = i;
         }
         if (j-i+1 >= res) break;
      }
   }
   foru(i, pos, pos+res-1) printf("%c", s[id][i]);
   if (id < n-1) printf("\n");
}


int main() {
   freopen("1713.in", "r", stdin);
   freopen("1713.out", "w", stdout);
   root = new node();
   cin >> n;
   rep(i, n) {
      scanf("%s", s[i]);
      len[i] = strlen(s[i]);
      add(i);
   }
   rep(i, n) solve(i);
   return 0;
}
