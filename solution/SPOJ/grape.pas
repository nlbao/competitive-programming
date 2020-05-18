{$M+ 2000000}
uses    math;

const   MAX_N = 503;
        MAX_Q = 10004;
        MAX_B = 2*MAX_N;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,m,nB,nQ:longint;
    a,f:array[0..MAX_N,0..MAX_N] of longint;
    l,r:array[0..MAX_Q] of longint;
    len:array[0..MAX_B] of longint;
    b:array[0..MAX_B,0..MAX_B] of longint;


procedure   enter();
var i,j:longint;
begin
    read(fi,m,n,nQ);
    for i:=1 to m do
        for j:=1 to n do
            read(fi,a[i][j]);
    for i:=1 to nQ do read(fi,l[i],r[i]);
end;


procedure   init();
var i,j:longint;
begin
    nB:=0;
    for i:=2 to n+m+1 do begin
        inc(nB);
        len[nB]:=0;
        for j:=min(i-1,n) downto 1 do begin
            if i-j > m then break;
            inc(len[nB]);
            b[nB][len[nB]]:=a[i-j][j];
        end;
    end;
end;


procedure   solve();
var i,k,x,y,u,v,res:longint;
begin
    for k:=1 to nQ do begin
        res:=0;
        u:=l[k];    v:=r[k];
        x:=1;   y:=oo;
        for i:=1 to nB do begin
            x:=max(x,1);
            y:=min(y,len[i]);
            while (x <= len[i]) and (b[i][x] < u) do inc(x);
            while (x > 1) and (b[i][x-1] >= u) do dec(x);
            while (y >= 1) and (b[i][y] > v) do dec(y);
            while (y < len[i]) and (b[i][y+1] <= v) do inc(y);
            res:=max(res,y-x+1);
        end;
        writeln(fo,res*res);
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'grape.inp');  reset(fi);
    assign(fo,'grape.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fi);
    close(fo);
end.