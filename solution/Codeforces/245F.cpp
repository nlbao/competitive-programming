#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <ctype.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 5*int(1e6)+6;
const int nDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


char s[MAX_N];
deque<int> q;


int parseInt(int &p) {
	int ans = 0;
	for (; p < MAX_N && isdigit(s[p]); ++p)
		ans = ans*10 + (s[p] - '0');
	++p;
	return ans;
}


int calTime(int month, int day, int hour, int minute, int second) {
	int ans = 0;
	for (int i = 0; i < month-1; ++i)
		ans += nDays[i]*86400;
	ans += (day-1)*86400;
	ans += 3600*hour;
	ans += 60*minute;
	ans += second;
	return ans;
}


string fs(int x) {
	string s = "";
	while (x%10 > 0) {
		s = char(x%10 + '0') + s;
		x /= 10;
	}
	while (s.length() < 2) s = "0" + s;
	return s;
}


int main() {
#ifdef DEBUG
	freopen("245F.in", "r", stdin);
	freopen("245F.out", "w", stdout);
#endif
	int n, m, c = 0;
	scanf("%d%d\n", &n, &m);
	while (scanf("%[0-9A-Za-z!.,?:- ]\n", s) != EOF) {
		// 2012-03-16 16:15:25: Disk size is
		// int year, month, day, hour, minute, second;
		int p = 0;
		int year = parseInt(p);
		int month = parseInt(p);
		int day = parseInt(p);
		int hour = parseInt(p);
		int minute = parseInt(p);
		int second = parseInt(p);
		// cout << year << " " << month << " " << day << endl;
		// cout << hour << " " << minute << " " << second << endl;
		int value = calTime(month, day, hour, minute, second);
		while (!q.empty() && q.front()+n <= value) {
			q.pop_front();
			--c;
		}
		q.push_back(value);
		++c;
		if (c >= m) {
			cout << "2012-" << fs(month) << "-" << fs(day) << " " << fs(hour) << ":" << fs(minute) << ":" << fs(second) << endl;
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}