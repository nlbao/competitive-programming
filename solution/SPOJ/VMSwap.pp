uses    math;

const   MAX_N = 1010;

var fi,fo:text;
    n,i,j,s,res:longint;
    a:array[0..MAX_N] of longint;
    f,g:array[0..MAX_N,0..MAX_N] of longint;

begin
    assign(fi,'VMSwap.in');     reset(fi);
    assign(fo,'VMSwap.out');    rewrite(fo);
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);

    s:=0;
    for i:=1 to n do begin
        f[i][0]:=0;
        g[i][0]:=0;
        for j:=1 to n do begin
            f[i][j]:=f[i][j-1]+longint(a[j] > a[i]);
            g[i][j]:=g[i][j-1]+longint(a[j] < a[i]);
        end;
        s:=s+f[i][i-1];
    end;

    res:=s;
    for i:=1 to n do
        for j:=i+1 to n do
            res:=min(res,s - (g[i][j]-g[i][i-1]) - (f[j][j]-f[j][i]) + (f[i][j]-f[i][i-1]) + (g[j][j]-g[j][i]));
    writeln(fo,res);
    close(fo);
    close(fi);
end.