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
const int MAX_Q = 1007;
const int MAX_A = 30;
const int MIN_INT = -2000000000;

struct node {
   int f, maxf, maxp;
   node* link[MAX_A];
   node (int ff) {
      f = maxf = ff;
      maxp = -1;
      fill(link, NULL);
   }
} *root = new node(MIN_INT);

int m;
int a[MAX_N];
string res;

int mInt(char a) {
   if (a == '-') return 27;
   return int(a)-int('a');
}

char mChar(int x) {
   if (x == 27) return '-';
   return char(x+int('a'));
}

void add(node *&p, int i, int v) {
   if (i > m) {
      p->f = p->maxf = v;
      return;
   }
   if (p->link[a[i]] == NULL) p->link[a[i]] = new node(MIN_INT);
   add(p->link[a[i]], i+1, v);
   if (p->link[a[i]]->maxf > p->maxf) {
      p->maxf = p->link[a[i]]->maxf;
      p->maxp = a[i];
   }
}

void find(node *p, int i) {
   if (i > m) {
      if (p->maxp > -1) {
         res += mChar(p->maxp);
         find(p->link[p->maxp], i+1);
      }
      return;
   }
   if (p->link[a[i]] == NULL) {
      res = "NO";
      return;
   }
   res += mChar(a[i]);
   find(p->link[a[i]], i+1);
}


int main() {
   freopen("TWSTR.in", "r", stdin);
   freopen("TWSTR.out", "w", stdout);
   int n;
   string s, t;
   scanf("%d", &n);
   getline(cin, s);
   rep(i, n) {
      m = 0;
      int v = 0;
      getline(cin, s);
      rep(j, size(s))
         if (s[j] != ' ') a[++m] = mInt(s[j]);
         else {
            int k = j+1, d = 1;
            if (s[k] == '-') {
               d = -1;
               ++k;
            }
            while (k < size(s)) v = v*10+int(s[k++])-int('0');
            v = v*d;
            break;
         }
      add(root, 1, v);
   }

   scanf("%d", &n);
   getline(cin, s);
   rep(i, n) {
      getline(cin, s);
      m = size(s);
      rep(j, m) a[j+1] = mInt(s[j]);
      res.clear();
      find(root, 1);
      rep(i, size(res)) printf("%c", res[i]);
      printf("\n");
      //cout << res << endl;
   }
   return 0;
}
