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

const int MAX_N = 20010;
const int MAX_A = 26;

struct node {
   int cnt;
   bool is_word;
   node *edge[MAX_A+10];
   node(int cc) {
      cnt = cc;
      is_word = false;
      rep(i, MAX_A+10) edge[i] = NULL;
   }
};

int n;
node *root, *tmp = NULL;
int a[MAX_N][33], len[MAX_N], link[MAX_A+10], is_linked[MAX_A+10];
bool found;
int e[MAX_A+10][MAX_A+10], sz[MAX_A+10];

int num(char x) { return x-'a';  }

void add(char s[], int m) {
   node *p = root;
   rep(i, m) {
      int x = num(s[i]);
      if (p->edge[x] == NULL) p->edge[x] = new node(0);
      p = p->edge[x];
      ++(p->cnt);
   }
   p->is_word = true;
}

void remove(node *&p) {
   if (p == NULL) return;
   rep(i, MAX_A) remove(p->edge[i]);
   p->cnt = 0;
   p->is_word = false;
}

bool test(node *p) { return (p!=NULL); }

void tryf(int id, int pos, node *p) {
   printf("!!!\n");
   if (p == NULL || p->cnt == 0 || id >= n) return;
   if (p != root) --(p->cnt);
   if (pos >= len[id]) {
      if (p->is_word)
         if (id < n-1) tryf(id+1,0,root);
         else found = true;
      ++(p->cnt);
      return;
   }


   int x = a[id][pos];
   if (x < 0 || x >= MAX_A || sz[x] <= 0) {
      cout << id << " " << pos << " " << x << " " << char(a[id][pos]+'a') << endl;
      ++(p->cnt);
      found = true;
      return;
   }

   if (link[x] > -1) {
      int v = link[x];
      cout << id << " " << pos << " " << v << " " << (p->edge[v] != NULL) << " "
<< len[id] << "      ";
      if (p->edge[v] != NULL) cout << p->edge[v]->cnt << " " << p->edge[v]->is_word << " " << test(p->edge[v]);
      cout << endl;
      if (p->edge[v] != NULL) tryf(id,pos+1,p->edge[v]);
      cout << "???" << endl;
   }
   else rep(i, sz[x]) {
      int v = e[x][i];
      if (p->edge[v] != NULL && is_linked[v] == -1) {
         link[x] = v;
         is_linked[v] = x;
         if (p->edge[v] != NULL) tryf(id,pos+1,p->edge[v]);
         if (found) break;
         is_linked[v] = -1;
         link[x] = -1;
      }
   }
   ++(p->cnt);
}

int main() {
    tmp = NULL;
   freopen("q.in", "r", stdin);
   freopen("q.out", "w", stdout);
   int nTest, c1[MAX_A+10], c2[MAX_A+10];
   char s[33];
   cin >> nTest;
   rep(id, nTest) {
      root = new node(1);
      fill(c1,0);
      fill(c2,0);
      scanf("%d",&n);
      rep(i, n) {
         scanf("%s",s);
         len[i] = strlen(s);
         rep(j, len[i]) ++c1[a[i][j] = num(s[j])];
      }
      rep(i, n) {
         scanf("%s",s);
         int m = strlen(s);
         rep(j, m) ++c2[num(s[j])];
         add(s,m);
      }

      rep(i, MAX_A+10) {
         sz[i] = 0;
         link[i] = -1;
         is_linked[i] = -1;
      }
      rep(i, MAX_A)
         rep(j, MAX_A)
            if (c1[i] == c2[j]) e[i][sz[i]++] = j;

      found = false;
      tryf(0,0,root);

      //tryf(7231,8,root);

      printf("DONE!\n");

      if (!found) {
         printf("WRONG!");
         continue;
      }

      int j = 0;
      rep(i, MAX_A) {
         if (link[i] == -1) {
            while (j < MAX_A && is_linked[j] > -1) ++j;
            link[i] = j;
            is_linked[j] = i;
         }
         s[i] = char(link[i]+'a');
      }
      s[MAX_A] = '\0';
      printf("%s",s);

      if (id < nTest-1) {
         printf("\n");
         //remove(root);
      }
   }
   return 0;
}
