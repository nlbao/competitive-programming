#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i,a,b) for (int i = (a); i <= (b); ++i)
#define fba(i,b,a) for (int i = (b); i >= (a); --i)
#define fillchar(a, b) memset(a, (b), sizeof(a));

typedef long long ll;

const int MAX_N = 1000010;

int n = 0, m = 0;
bool is_prime[MAX_N];
int p[MAX_N];
ll s[MAX_N];

void Eratosthene() {
   fillchar(is_prime, true);
   fab(i, 2, MAX_N)
      if (is_prime[i]) {
         p[++n] = i;
         for (int j = i+i; j <= MAX_N; j += i)
            is_prime[j] = false;
      }
   cout << p[10001] << endl;
}

int solve() {
   ll rl = 0, rt = 0;
   s[1] = p[1];
   fab(i, 2, n) s[i] = s[i-1]+p[i];
   fab(i, 1, n-1)
      fab(j, i+1, n) {
         ll t = s[j]-s[i];
         if (t > MAX_N) break;
         if ((is_prime[t]) && (j-i+1 > rl)) {
            rl = j-i+1;
            rt = t;
         }
      }
   return rt;
}

int main() {
   Eratosthene();
   cout << solve();
   return 0;
}
