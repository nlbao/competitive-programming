#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

long long n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    long long y;

    if (n%2==0) {
        cout << "Yes" << endl;
        return 0;
    }
    for (y=1; y<=n/2; ++y) {
        double tmp = sqrt(y*(n-y));
        if (tmp - floor(tmp)<0.01) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
