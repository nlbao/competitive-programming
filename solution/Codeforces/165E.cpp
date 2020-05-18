#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1000007;
const int M = 23;

struct node {
   node *link[2];
   int id;
   node(int i) { id = i;  link[0] = link[1] = NULL;  }
};

int n;
node *root = new node(-1);
int t[M];
int a[MAX_N], res[MAX_N];

void new_node(node *&p, int idd) {  p = new node(idd);   }


int find(int c) {
   cout << c << " " << endl;
   cout << "        ";
   node *p = root;
   fab(i, 0, M) {
      cout << t[i] << " " ;
      if (p->link[t[i]] == NULL) return -1;
      p = p->link[t[i]];
      if ((i >= c) && (p->id > -1)) return p->id;
   }

}

void add_node(int c, int idd) {
   node *p = root;
   fab(i, 0, M) {
      if (p->link[t[i]] == NULL)
         new_node(p->link[t[i]], -1);
      p = p->link[t[i]];
      if ((i >= c) && (p->id == -1)) p->id = idd;
   }
}



int main() {
   freopen("165E.in", "r", stdin);
   freopen("165E.out", "w", stdout);
   cin >> n;
   fab(i, 0, n-1) res[i] = -1;
   fab(i, 0, n-1) {
      scanf("%d", &a[i]);
      fill(t, 0);
      int c = -1, x = a[i];
      while (x > 0) {
         t[++c] = x%2;
         x /= 2;
      }
      add_node(c, a[i]);
      cout << endl;
   }

   fab(i, 0, n-1) {
      fill(t, 0);
      int c = -1, x = a[i];
      while (x > 0) {
         t[++c] = x%2;
         if (t[c] == 1) t[c] = 0;
         x /= 2;
         cout << t[c] << " " ;
      }
      cout << endl;
      res[i] = find(c);
      cout << endl;
   }
   fab(i, 0, n-1) cout << res[i] << " ";
   return 0;
}
