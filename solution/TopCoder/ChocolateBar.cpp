#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

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

const int MAX_N = 100;

class ChocolateBar {
    public:
    int maxLength(string s) {
        int n = size(s);
        int a[MAX_N];
        bool ok[MAX_N];
        rep(i,n) a[i] = s[i]-'0';
        fill(ok,true);
        int j = -1, res = 0;
        rep(i,n) {
            while (j < n-1 && ok[a[j+1]]) {
                ++j;
                ok[a[j]] = false;
            }
            res = max(res,j-i+1);
            ok[a[i]] = true;
        }
        return res;
    }


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
