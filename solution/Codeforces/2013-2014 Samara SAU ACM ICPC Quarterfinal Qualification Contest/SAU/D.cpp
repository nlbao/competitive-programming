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
//int n;
//int cnt[30];
//string s[3];
//
//int main() {
//#define DEBUG
//#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//    cin >> n;
//    for (int i = 0; i < 3; i++) cin >> s[i];
//    for (int i = 0; i < n; i++) {
//        char c = s[0][i];
//        memset(cnt, 0, sizeof cnt);
//        cnt[c - 'a']++;
//        for (int j = 1; j < 3; j++) cnt[s[j][i] - 'a']++;
//        char ok;
//        int maxCnt = 0;
//        for (char c = 'a'; c <= 'z'; c++)
//            if (cnt[c - 'a'] > maxCnt) {
//                maxCnt = cnt[c - 'a'];
//                ok = c;
//            }
//        printf("%c", ok);
//    }
//    puts("");
//	return 0;
//}
//
