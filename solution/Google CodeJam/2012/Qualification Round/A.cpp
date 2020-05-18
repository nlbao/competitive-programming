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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

char link[222];

int main() {
   freopen("A.in", "r", stdin);
   freopen("A.out", "w", stdout);
   string s = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
   string t = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
   fill(link, 0);
   rep(i, s.size()) link[int(s[i])] = t[i];
   link[int('z')] = 'q';
   link[int('q')] = 'z';
   //foru(i, int('a'), int('z')) if (link[i] == 0) cout << char(i) << endl;
   int nTest;
   cin >> nTest;
   getline(cin, s);
   foru(testid, 1, nTest) {
      getline(cin, s);
      t = "";
      int n = s.size(), i = 0;
      while (i < n) {
         while ((i < n) && (s[i] != ' ')) {
            t += link[s[i]];
            ++i;
         }
         ++i;
         if (i < n) t += ' ';
      }
      cout << "Case #" << testid << ": " << t << endl;
   }
   return 0;
}

