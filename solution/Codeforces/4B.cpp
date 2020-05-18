#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 50;

int main()  {
    freopen("4B.in", "r", stdin);
    freopen("4B.out", "w", stdout);

    int n, st, sa = 0, sb = 0;
    int a[MAX_N], b[MAX_N];
    scanf("%d%d",&n,&st);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i],&b[i]);
        sa += a[i];
        sb += b[i];
    }

    if ((sa > st) || (sb < st))
        printf("NO\n");
    else {
        printf("YES\n");
        st -= sa;
        for (int i = 0; i < n; ++i) {
            int j = min(b[i]-a[i], st);
            printf("%d ",a[i]+j);
            st -= j;
        }
    }
    return 0;
}
