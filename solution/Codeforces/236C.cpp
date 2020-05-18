/*#include <sstream>
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
#pragma comment(linker, "/STACK:16777216")

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

int read() {   int x;   scanf("%d",&x);   return x;   }

ll gcd(ll x, ll y) {
   if (x == 0 || y == 0) return x+y;
   return gcd(y,x%y);
}

ll lcm(ll x, ll y) { return (x*y)/gcd(x,y);  }

int main() {
#ifndef ONLINE_JUDGE
   freopen("236C.in", "r", stdin);
   freopen("236C.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   ll res = 1;
   foru(i,max(n-100,1),n)
      foru(j,max(n-100,1),n)
         if (gcd(i,j) == 1)
            foru(k,max(n-100,1),n)
               if (gcd(i,k) == 1 && gcd(j,k) == 1)
                  res = max(res,ll(i)*ll(j)*ll(k));
   cout << res;
   return 0;
}*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    if(a<1) a=1; if(b<1) b=1;
    return a*b/gcd(a,b);
}

int main(){
    ll n;
    cin>>n;
    ll res=lcm(n-1,lcm(n-2,n-3));
    ll t=n*max(1ll,n-1);
    FOR(i,1,n) res=max(res,lcm(t,i));
    cout<<res<<endl;
    return 0;

}
