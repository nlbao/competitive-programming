const   INPUT = '14E.in';
        OUTPUT = '14E.out';
        MAX_N = 30;
        MAX_M = 20;

var fi,fo:text;
    n,m:longint;
    f,g:array[0..MAX_N,0..4,-1..MAX_M,-1..MAX_M] of int64;

procedure   solve;
var i,j,k,t,jj:longint;
    res:int64;
begin
    fillchar(f,sizeof(f),0);
    fillchar(g,sizeof(g),0);
    for j:=1 to 4 do begin
        f[2][j][0][0]:=j-1;
        g[2][j][0][0]:=4-j;
    end;
    for i:=3 to n do
        for j:=1 to 4 do
            for k:=0 to m do
                for t:=0 to m-1 do begin
                    for jj:=1 to j-1 do
                        f[i][j][k][t]:=f[i][j][k][t]+f[i-1][jj][k][t]+g[i-1][jj][k][t-1];
                    for jj:=j+1 to 4 do
                        g[i][j][k][t]:=g[i][j][k][t]+g[i-1][jj][k][t]+f[i-1][jj][k-1][t];
                end;
    res:=0;
    for j:=1 to 4 do
        res:=res+f[n][j][m][m-1]+g[n][j][m][m-1];
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n,m);
    solve;
    close(fo);
    close(fi);
end.
