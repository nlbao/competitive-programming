#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)
#define ll long long

const int MAX_N = 3010;

class marble {
    public:
        ll x, c;
        marble(ll xx, ll cc) { x = xx; c = cc; }
        bool operator<(const marble &a) const {
            return ((x < a.x) || ((x == a.x) && (c < a.c)));
        }
};

int main() {
    freopen("38E.in", "r", stdin);
    freopen("38E.out", "w", stdout);
    int n;
    vector<marble> a;
    scanf("%d", &n);
    forI(i, 0, n-1) {
        ll x, y;
        cin >> x >> y;
        a.push_back(marble(x,y));
    }
    sort(a.begin(), a.end());

    ll f[MAX_N];
    f[n-1] = a[n-1].c;
    forD(i, n-2, 0) {
        f[i] = f[i+1];
        ll s = 0;
        forI(j, i+1, n-1) {
            s += (a[j-1].x-a[i].x);
            f[i] = min(f[i], f[j]+s);
        }
        f[i] = min(f[i], s+a[n-1].x-a[i].x);
        f[i] += a[i].c;
    }
    cout << f[0] << "\n";
    return 0;
}
