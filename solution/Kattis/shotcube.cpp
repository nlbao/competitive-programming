#include <bits/stdc++.h>

using namespace std;

map<long long, int> T;
set<int> arc, vis;

long long Q[1000000];

const int N = 7;

int A[8][8], B[8][8], C[8][8];

void nhap()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            char c = getchar();
            A[i][j]=(c=='X');
        }
        scanf("\n");
    }
    scanf("\n");
}

inline long long getmask(int A[8][8])
{
    long long s = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            s<<=1;
            s+=A[i][j];
        }
    }
    return s;
}

#define getbit(s, j) (((s)>>(j))&1)

inline void reload(long long s)
{
    memset(B,0,sizeof(B));
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            B[i][j]=getbit(s,(i-1)*7+j-1);
        }
    }
}

inline void asgn()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
            C[i][j]=B[i][j];
    }
}

#define valid(s) (arc.find(s)!=arc.end())


void tinh()
{
    while (!T.empty()) T.erase(T.begin());
    long long s = getmask(A);
    if (vis.find(s)!=vis.end())
    {
        printf("-1\n");
        return;
    }
    T.insert(make_pair(s,0));
    int l = 0, r = 0; Q[0]=s;
    while (l<=r)
    {
        long long mask = Q[l++];
        int dis = T.find(mask)->second;
        reload(mask);
        for(int i=1; i<=N; i++)
        {
            // tren
            if (B[1][i]==1)
            {
                int j=1, k;
                while (B[j+1][i]==1) j++;
                for(k=j+1; k<=N; k++)
                if (B[k][i]==1) break;
                if (k<=N)
                {
                    asgn();
                    int d = k-j-1;
                    for(int k=1; k<=j; k++)
                    if (B[k][i]==1)
                    {
                        C[k][i]=0;
                        C[k+d][i]=1;
                    }
                    long long tmp = getmask(C);
                    if (valid(tmp))
                    {
                        printf("%d\n",dis+1);
                        return;
                    }
                    if (T.find(tmp)==T.end()&&vis.find(tmp)==vis.end())
                    {
                        T.insert(make_pair(tmp,dis+1));
                        Q[++r]=tmp;
                    }
                }
            }
            // trai
            if (B[i][1]==1)
            {
                int j=1, k;
                while (B[i][j+1]==1) j++;
                for(k=j+1; k<=N; k++)
                if (B[i][k]==1) break;
                if (k<=N)
                {
                    asgn();
                    int d = k-j-1;
                    for(int k=1; k<=j; k++)
                    if (B[i][k]==1)
                    {
                        C[i][k+d]=1;
                        C[i][k]=0;
                    }
                    long long tmp = getmask(C);
                    if (valid(tmp))
                    {
                        printf("%d\n",dis+1);
                        return;
                    }
                    if (T.find(tmp)==T.end()&&vis.find(tmp)==vis.end())
                    {
                        T.insert(make_pair(tmp,dis+1));
                        Q[++r]=tmp;
                    }
                }
            }
            // duoi
            if (B[N][i]==1)
            {
                int j=N, k;
                while (B[j-1][i]==1) j--;
                for(k=j-1; k>=1; k--)
                if (B[k][i]==1) break;
                if (k>=1)
                {
                    asgn();
                    int d = j-k-1;
                    for(int k=N; k>=j; k--)
                    if (B[k][i]==1)
                    {
                        C[k][i]=0;
                        C[k-d][i]=1;
                    }
                    long long tmp = getmask(C);
                    if (valid(tmp))
                    {
                        printf("%d\n",dis+1);
                        return;
                    }
                    if (T.find(tmp)==T.end()&&vis.find(tmp)==vis.end())
                    {
                        T.insert(make_pair(tmp,dis+1));
                        Q[++r]=tmp;
                    }
                }
            }
            // phai
            if (B[i][N]==1)
            {
                int j=N, k;
                while (B[i][j-1]==1) j--;
                for(k=j-1; k>=1; k--)
                if (B[i][k]==1) break;
                if (k>=1)
                {
                    asgn();
                    int d = j-k-1;
                    for(int k=N; k>=j; k--)
                    if (B[i][k]==1)
                    {
                        C[i][k-d]=1;
                        C[i][k]=0;
                    }
                    long long tmp = getmask(C);
                    if (valid(tmp))
                    {
                        printf("%d\n",dis+1);
                        return;
                    }
                    if (T.find(tmp)==T.end()&&vis.find(tmp)==vis.end())
                    {
                        T.insert(make_pair(tmp,dis+1));
                        Q[++r]=tmp;
                    }
                }
            }
        }
    }
    while (!T.empty())
    {
        vis.insert(T.begin()->first);
        T.erase(T.begin());
    }
    printf("-1\n");
}

void prep()
{
    for(int i=1; i<=N-3+1; i++)
    {
        for(int j=1; j<=N-3+1; j++)
        {
            memset(A,0,sizeof(A));
            for(int ii=0; ii<3; ii++)
            {
                for(int jj=0; jj<3; jj++)
                    A[i+ii][j+jj]=1;
            }
            long long s = getmask(A);
            arc.insert(s);
        }
    }
}

int main()
{
    freopen("shotcube.in","r",stdin);
    freopen("shotcube.out", "w", stdout);
    int T; scanf("%d\n",&T);
    prep();
    while (T--)
    {
        nhap();
        tinh();
    }
	return 0;
}
