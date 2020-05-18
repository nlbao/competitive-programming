#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forI(i,a,b) for (int i = (a); i <= (b); ++i)
#define forD(i,a,b) for (int i = (a); i >= (b); --i)

const int MAX_N = 5010;

class envelope {
    public:
            int w, h, id, f, trace;
            envelope(int ww, int hh, int idd)   {w = ww; h = hh; id = idd;}
            bool operator<(const envelope &a) const {
                return ((w < a.w) || ((w == a.w) && (h < a.h)));
            }
};

int main()  {
    freopen("4D.in", "r", stdin);
    freopen("4D.out", "w", stdout);

    int n, w0, h0;
    vector <envelope> a;

    scanf("%d%d%d", &n, &w0, &h0);
    forI(i, 0, n-1) {
        int x, y;
        scanf("%d%d", &x, &y);
        if ((x > w0) && (y > h0))
            a.push_back(envelope(x, y, i+1));
    }

    sort(a.begin(), a.end());
    n = a.size();
    int res = 0, p = -1;
    forD(i, n-1, 0) {
        a[i].f = 1;   a[i].trace = -1;
        forI(j, i+1, n-1)
            if ((a[j].w > a[i].w) && (a[j].h > a[i].h) && (a[j].f+1 > a[i].f))  {
                a[i].f = a[j].f+1;
                a[i].trace = j;
            }
        if ((a[i].w > w0) && (a[i].h > h0) && (a[i].f > res)) {
            res = a[i].f;
            p = i;
        }
    }

    printf("%d\n", res);
    while (p > -1) {
        printf("%d ", a[p].id);
        p = a[p].trace;
    }
    return 0;

}
