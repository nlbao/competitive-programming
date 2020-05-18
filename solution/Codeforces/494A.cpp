//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//#include <cstring>
//#include <ctime>
//#include <cctype>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <algorithm>
//#include <utility>
//#include <vector>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <functional>
//#include <bitset>
//
//// #pragma comment(linker, "/STACK:16777216")
//
//using namespace std;
//
//typedef long long ll;
//typedef long double ld;
//typedef pair<int, int> pii;
//
//#define filla(a, x) memset(a, x, sizeof(a))
//#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
//#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
//#define sqr(x) ((x)*(x))
//
//int read() {   int x;   scanf("%d",&x);   return x;   }
//int readln() {   int x;   scanf("%d\n",&x);   return x;   }
//
//
//const int MAX_N = int(1e5) + 5;
//
//int n, last, cntlast;
//char s[MAX_N];
//std::vector<int> ans;
//
//
//bool solve() {
//    if (cntlast < 0) return false;
//	int c = 0;
//	ans.clear();
//	for (int i = 0; i < n; ++i) {
//		if (s[i] == '(') ++c;
//		else if (s[i] == ')') {
//			--c;
//			if (c < 0) return false;
//		}
//		else {
//			--c;
//			if (c < 0) return false;
//			int t = 1;
//			if (i == last) {
//                t += c;
//                t -= cntlast;
//			}
//			if (t <= 0) return false;
//			ans.push_back(t);
//		}
//	}
//	return true;
//}
//
//
//int main() {
//#ifdef DEBUG
//	freopen("494A.in", "r", stdin);
////	freopen("494A.out", "w", stdout);
//#endif
//	scanf("%s", &s);
//	n = strlen(s);
//	last = -1;
//	cntlast = 0;
//	for (int i = n-1; i >= 0; --i)
//		if (s[i] == '#') {
//			last = i;
//			break;
//		}
//		else if (s[i] == ')') ++cntlast;
//		else if (s[i] == '(') --cntlast;
//	if (!solve()) printf("-1\n");
//	else {
//        foreach(it, ans)
//            printf("%d\n", *it);
//	}
//	return 0;
//}
