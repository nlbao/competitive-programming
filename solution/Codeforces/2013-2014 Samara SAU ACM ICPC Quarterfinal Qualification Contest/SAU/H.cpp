//#include <cstdio>
//#include <cmath>
//#include <cstring>
//#include <iostream>
//#include <sstream>
//#include <algorithm>
//#include <utility>
//#include <vector>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//
//#pragma comment(linker, "/STACK:16777216")
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vecint;
//typedef pair<int, int> ppi;
//typedef vector< pair<int, int> > vecppi;
//
//#define fill(a,x) memset(a, (x), sizeof(a))
//#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define sz(a) (int)a.size()
//#define pb push_back
//#define sqr(x) (x)*(x)
//
//int read() {   int x;   scanf("%d",&x);   return x;   }
//int read(int &x) {  scanf("%d",&x);     return x;   }
//
//int n, res;
//string s, t;
//
//int main() {
//#define DEBUG
//#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//    cin >> n >> s >> t;
//    for (int i = 0; i < n; ) {
//        if (s[i] == t[i]) { i++; continue; }
//        int j;
//        for (j = i+1; j < n && s[j] != t[j]; j++);
//        res++;
//        i = j;
//    }
//    cout << res << endl;
//
//	return 0;
//}
//
