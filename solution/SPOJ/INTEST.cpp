#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


// inline int readInt() {
//     register int c = getchar();
//     int x = 0;
//     for(; (c<48 || c>57); c = getchar());
//     for(; c>47 && c<58; c = getchar())
//     	x = (x<<1) + (x<<3) + c - 48;
//     return x;
// }

// inline void readInt(int &x) {
//     register int c = getchar();
//     x = 0;
//     for(; (c<48 || c>57); c = getchar());
//     for(; c>47 && c<58; c = getchar())
//     	x = (x<<1) + (x<<3) + c - 48;
// }


namespace fastIO {
	const size_t amount = 16;
	static char buffer[1<<16];
	static char* dataEnd = buffer + sizeof(buffer);
	static const char* pos = dataEnd;

	inline void readAhead() {
	    size_t remaining = dataEnd - pos;
	    if (remaining < amount) {
			memmove(buffer, pos, remaining);
			size_t sz = fread(buffer + remaining, 1, sizeof(buffer) - remaining, stdin);
			pos = buffer;
			dataEnd = buffer + remaining + sz;
			if (dataEnd != buffer + sizeof(buffer))
				*dataEnd = 0;
	    }
	}

	inline int readInt() {
		readAhead();
		int x = 0;
		bool neg = false;
		if (*pos == '-') {
			++pos;
			neg = true;
		}
	    while (*pos < '0' || *pos > '9') ++pos;
	    while (*pos >= '0' && *pos <= '9') {
			x *= 10;
			x += *pos - '0';
			++pos;
	    }
	    return neg ? -x : x;
	}
};

void solve_1() {
	int n, k, ans = 0;
	n = fastIO::readInt();
	k = fastIO::readInt();
	for (int i = 0; i < n; ++i) {
		int x = fastIO::readInt();
		if (x%k == 0) ++ans;
	}
	printf("%d\n", ans);
}


void solve_2() {
	const int size = 65536;
	char b[size];
    int t=0,n,k,cnt=0;
    int c,j;
    scanf("%d %d\n",&n,&k);
    while((c = fread(b,1,size,stdin))>0) {
		for(j=0;j<c;j++)
			if(b[j]=='\n') {
				if(t%k==0)cnt++;
				t = 0;
			}
			else t = (t*10) + (b[j]-'0');
	}
    printf("%d\n",cnt);
}


int main() {
#ifdef DEBUG
	freopen("INTEST.in", "r", stdin);
	freopen("INTEST.out", "w", stdout);
#endif
	solve_1();
	// solve_2();
	return 0;
}