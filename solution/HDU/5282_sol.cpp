/*
学姐姐非常喜欢字符串，所以学弟送给了她两个字符串作为礼物。

两个字符串分别为X，Y。她非常开心，但在开心之余她还想考考学弟。

她定义L为X与Y的最长公共子序列的长度（子序列在字符串内不一定连续，一个长度为L的字符串有2L个子序列，包括空子序列）。

现在学姐姐取出了X的所有长度为L的子序列，并要求学弟回答在这些子序列中，有多少个是Y的子序列。

因为答案可能很大，所以学弟只需要回答最终答案模109+7。
*/


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX_N 1100//再大dp数组会爆的   O(n*m)
char a[MAX_N],b[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int dd[MAX_N+1][MAX_N+1];//b前j个字母中  最后一个 与x[i]
int wei[MAX_N+1][26];//Y前i个字母中 最后一个j字母在的位置
__int64 f[MAX_N+1][MAX_N+1];

int mod=1e9+7;
int main()
{
	#ifdef DEBUG
	freopen("5282.in", "r", stdin);
	freopen("5282.out", "w", stdout);
#endif
	int n,m,tem,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		memset(dp,0,sizeof(dp));
		n=strlen(a);
		m=strlen(b);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i]==b[j])
			    	dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i+1][j],dp[i][j+1]));
				else
					dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		}
		memset(wei,0,sizeof wei);
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<26;j++)
				wei[i][j]=wei[i-1][j];
			wei[i][b[i-1]-'a']=i;
		}
		memset(f,0,sizeof f);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(dp[i][j]==0)
				{
					f[i][j]=1;
					continue;
				}
				if(dp[i-1][j]==dp[i][j])
					f[i][j]=(f[i][j]+f[i-1][j])%mod;
				int p=wei[j][a[i-1]-'a'];
				if(p)
				{
					if(dp[i-1][p-1]+1==dp[i][j])
						f[i][j]=(f[i][j]+f[i-1][p-1])%mod;
				}
			}
		}

		printf("%I64d\n",f[n][m]%mod);
	}
	return 0;
}