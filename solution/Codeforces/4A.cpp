#include <cstdio>

int main() {
    freopen("4A.in", "r", stdin);
    freopen("4A.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if ((n%2 == 0) && (n > 2)) printf("YES\n");
    else printf("NO\n");
    return 0;
}