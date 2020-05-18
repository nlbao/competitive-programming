{$M+ 2000000}
uses    math;

const   MAX_N = 502;
        MAX_M = sqr(MAX_N);
        oo = 1000000000000000000;

type    ll = int64;

var fi,fo:text;
    n,m,k:longint;
    a,g:array[0..MAX_N,0..MAX_N] of ll;
    f:array[0..1,0..MAX_N] of ll;


procedure   enter();
var i,j,v:longint;
begin
    m:=0;
    read(fi,n,k);
    fillchar(a,sizeof(a),0);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,v);
            if i < j then a[i][j]:=a[i][j]+v
            else a[j][i]:=a[j][i]+v;
        end;
end;



procedure   cal_g();
var i,j:longint;
begin
    fillchar(g,sizeof(g),0);
    for i:=1 to n do
        for j:=1 to i-1 do
            g[i][j]:=g[i][j-1] + a[j][i];
    for i:=1 to n do
        for j:=i+1 to n do
            g[i][j]:=g[i][j-1] + (g[j][j-1]-g[j][i-1]);
end;


procedure   solve();
var i,j,x,t,tt,turn:longint;
    res:ll;
begin
    cal_g();

    t:=0;
    for i:=0 to n do begin
        f[0][i]:=oo;
        f[1][i]:=oo;
    end;
    f[t][0]:=0;

    for turn:=1 to k do begin
        tt:=t;
        t:=1-t;
        for i:=turn to n-1 do begin
            f[t][i]:=oo;
            for x:=turn-1 to i-1 do
                f[t][i]:=min(f[t][i], f[tt][x] + g[x+1][i]);
        end;
    end;

    res:=oo;
    for i:=k to n-1 do
        res:=min(res, f[t][i] + g[i+1][n]);
    writeln(fo,g[1][n]-res);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'nsrail.inp');   reset(fi);
    assign(fo,'nsrail.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    if k = 0 then writeln(fo,0)
    else solve();
    close(fi);
    close(fo);
end.