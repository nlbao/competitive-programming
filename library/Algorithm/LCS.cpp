// Find LCS (d[n][m])
filla(d, 0);
for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j) {
		d[i][j] = max(d[i-1][j], d[i][j-1]);
		if (a[i] == b[j])
			d[i][j] = max(d[i][j], d[i-1][j-1] + 1);
	}

// Count number of embedding / distinct LCS. Defaut = distinct
filla(f, 0);
fori(i,0,n) fori(j,0,m) {
	if (i == 0 || j == 0) {
		f[i][j] = 1;
		continue;
	}
	if (a[i] == b[j]) {
		f[i][j] = f[i-1][j-1];
		continue;	// comment this line to count embedding LCS
	}
	if (d[i-1][j] == d[i][j]) f[i][j] = (f[i][j] + f[i-1][j]) % MODULE;
	if (d[i][j-1] == d[i][j]) f[i][j] = (f[i][j] + f[i][j-1]) % MODULE;
	if (d[i-1][j-1] == d[i][j]) f[i][j] = (f[i][j] - f[i-1][j-1]) % MODULE;
	if (f[i][j] < 0) f[i][j] += MODULE;
}