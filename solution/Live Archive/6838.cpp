#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define endl '\n'


const int MAX_N = 3e5+5;
const int MAX_F = 4*MAX_N;
const int oo = MAX_F+100;


int n, nQ, u, v, value;
char s[MAX_N];
int c[MAX_F], minC[MAX_F], add[MAX_F];
set<int> heap;


inline void push_down(int k) {
    if (add[k] == 0) return;
    int kl=k<<1, kr=kl+1;
    add[kl] += add[k];   minC[kl] += add[k];
    add[kr] += add[k];   minC[kr] += add[k];
    add[k] = 0;
}


void build(int k, int l, int r) {
    if (l>r) return;
    add[k] = 0;
    if (l==r) {
        minC[k]=c[l];
        return;
    }
    int mid=(l+r)>>1;
    int kl=k<<1, kr=kl+1;
    build(kl, l, mid);
    build(kr, mid+1, r);
    minC[k] = min(minC[kr], minC[kl]);
}


void update(int k, int l, int r) {
    if (l<r) push_down(k);
    if (l>v || r<u) return;
    if (u <= l && r <= v) {
        add[k] += value;
        minC[k] += value;
        return;
    }
    int mid=(l+r)>>1;
    int kl=k<<1, kr=kl+1;
    update(kl, l, mid);
    update(kr, mid+1, r);
    minC[k] = min(minC[kr], minC[kl]);
}


inline void treeUpdate(int p, int val) {
    u = p, v = n;
    value = val;
    update(1, 1, n);
}


int findBestMinC(int k, int l, int r) {
    if (l<r) push_down(k);
    if (l==r) {
        c[l] += add[k];
        add[k] = 0;
        if (c[l] >= 2) return l;
        return oo;
    }
    int mid=(l+r)>>1;
    int kl=k<<1, kr=kl+1;
    if (minC[kr] >= 2)
        return min(mid+1, findBestMinC(kl, l, mid));
    return findBestMinC(kr, mid+1, r);
}


inline int findBestG() {
    int i = *heap.begin();
    heap.erase(heap.begin());
    return i;
}


inline void stringUpdate(int i, char x) {
    s[i-1]=x;
    if (x=='(') {
        set<int>::iterator it = heap.find(i);
        if (it != heap.end())
            heap.erase(it);
    }
    else {
        heap.insert(i);
    }
}


int main() {
#ifdef DEBUG
    freopen("6838.in", "r", stdin);
    freopen("6838.out", "w", stdout);
#endif
    while (scanf("%d%d", &n, &nQ) > 0) {
        scanf("%s", s);

        c[0]=0;
        fori(i,1,n) {
            c[i]=c[i-1];
            if (s[i-1]=='(') ++c[i];
            else --c[i];
        }
        build(1, 1, n);

        heap.clear();
        fori(i,1,n) if (s[i-1]==')') {
            heap.insert(i);
        }

        int q, i;
        while (nQ--) {
            scanf("%d", &q);
            if (s[q-1] == '(') {
                treeUpdate(q, -2);
                stringUpdate(q, ')');
                i = findBestG();
                printf("%d\n", i);
                treeUpdate(i, +2);
                stringUpdate(i, '(');
            }
            else {
                treeUpdate(q, +2);
                stringUpdate(q, '(');
                i = findBestMinC(1, 1, n);
                printf("%d\n", i);
                treeUpdate(i, -2);
                stringUpdate(i, ')');
            }
        }
    }

    return 0;
}

