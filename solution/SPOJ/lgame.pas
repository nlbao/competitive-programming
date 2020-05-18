uses    math;

const   MAX_N = 1003;
        MAX_M = 10004;
        oo = 1000000000;
        MODULE = 1000000007;

type    ll = int64;

var fi,fo:text;
    n,m,i,j,k:longint;
    a:array[0..MAX_N] of longint;
    f,g:array[0..MAX_N,0..MAX_M] of longint;
    res:ll;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'LGAME.inp');    reset(fi);
    assign(fo,'LGAME.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n,m);
    for i:=1 to n do read(fi,a[i]);

//cal f: 1 --> n
    for i:=1 to m do f[0][i]:=0;
    f[0][0]:=1;
    for i:=1 to n do begin
        for j:=m downto 0 do f[i][j]:=f[i-1][j];
        for j:=m downto a[i] do
            f[i][j]:=(f[i][j]+f[i-1][j-a[i]]) mod MODULE;
    end;

//cal g: n --> 1
    for i:=1 to m do g[n+1][i]:=0;
    g[n+1][0]:=1;
    for i:=n downto 1 do begin
        for j:=m downto 0 do g[i][j]:=g[i+1][j];
        for j:=m downto a[i] do
            g[i][j]:=(g[i][j]+g[i+1][j-a[i]]) mod MODULE;
    end;

//cal res: 1 --> i <-- n
    for i:=1 to n do begin
        res:=0;
        for j:=0 to m do begin
            k:=m-a[i]-j;
            if k < 0 then continue;
            res:=(res+(int64(f[i-1][j])*int64(g[i+1][k])) mod MODULE) mod MODULE;
        end;
        write(fo,res,' ');
    end;
    close(fi);
    close(fo);
end.
