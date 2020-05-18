#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


// map<int, bool> q;
set<int> q;



int main() {
#ifndef ONLINE_JUDGE
    freopen("CPPSET.in", "r", stdin);
    freopen("CPPSET.out", "w", stdout);
#endif
    //1 ADD x: thêm số x vào tập S
    //2 DELETE x: xóa số x khỏi tập S
    //3 MININUM: tìm số nhỏ nhất trong tập S
    //4 MAXIMUM: tìm số lớn nhất trong tập S
    //5 SUCC x: tìm số nhỏ nhất lớn hơn x trong tập S
    //6 SUCC_2 x: tìm số nhỏ nhất và không nhỏ hơn x trong tập S
    //7 PRED x: tìm số lớn nhất nhỏ hơn x trong tập S
    //8 PRED_2 x: tìm số lớn nhất không vượt quá x trong tập S

    q.clear();
    int n = 0;
    for(;;) {
    	int cmd = read(), x, first, last;
    	if (cmd < 1) break;
    	if (cmd != 3 && cmd != 4) read(x);
        set<int>::iterator it = q.end();
        if (!q.empty()) {
            --it;
            first = *q.begin();
            last = *it;
        }

    	switch (cmd) {
    		case 1:	if (q.find(x) == q.end())
    					q.insert(x);
    				break;

			case 2:	if (q.find(x) != q.end())
						q.erase(x);
    				break;

    		case 3:	if (q.empty()) printf("empty\n");
    				else printf("%d\n", *q.begin());
    				break;

    		case 4:	if (q.empty()) printf("empty\n");
    				else {
    					it = q.end();
    					--it;
    					printf("%d\n", *it);
    				}
    				break;

    		case 5:	if (q.empty()) printf("empty\n");
    				else {
                        it = q.lower_bound(x+1);
                        if (it != q.end()) printf("%d\n", *it);
                        else printf("no\n");
                    }
    				break;

			case 6:	if (q.empty()) printf("empty\n");
    				else {
                        it = q.lower_bound(x);
                        if (it != q.end()) printf("%d\n", *it);
                        else printf("no\n");
                    }
    				break;

    		case 7:	if (q.empty()) printf("empty\n");
        			else {
                        it = q.upper_bound(x-1);
                        if (it == q.end()) --it;
                        if (*it >= x)
                            if (it == q.begin()) {
                                printf("no\n");
                                continue;
                            }
                            else --it;
                        printf("%d\n", *it);
                    }
    				break;

    		case 8:	if (q.empty()) printf("empty\n");
        			else {
                        it = q.upper_bound(x);
                        if (it == q.end()) --it;
                        if (*it > x)
                            if (it == q.begin()) {
                                printf("no\n");
                                continue;
                            }
                            else --it;
                        printf("%d\n", *it);
                    }
    				break;
    	}
    }
    return 0;
}