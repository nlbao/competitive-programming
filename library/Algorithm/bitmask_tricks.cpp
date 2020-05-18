// f[i] number of j such as j|i == i.
// f[i] initially contain the frequency of each i (from input).
// ref: https://www.hackerrank.com/contests/w16/challenges/vim-war/editorial
for(int i = 0; i < 20; i++)
	for(int j = 0; j <= (1<<20); ++j)
		if(j&(1<<i))
			f[j] += f[j^(1<<i)];
