{$M+ 2000000}
uses    math;

const   MAX_N = 1003;
        oo = 1000000000;

type    ll = int64;
        recPoint = record
            x,y:ll;
        end;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of recPoint;
    d:array[0..MAX_N] of ll;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i].x,a[i].y);
end;


procedure   sort(l,r:longint);
var i,j:longint;
    p,t:ll;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=d[i];
    i:=l;   j:=r;
    repeat
        while d[i] < p do inc(i);
        while d[j] > p do dec(j);
        if i <= j then begin
            t:=d[i];
            d[i]:=d[j];
            d[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


procedure   solve_1();
var i,j,k,l,res:longint;
begin
    res:=0;
    randomize;
    for i:=1 to n do begin
        for j:=1 to n do
            d[j]:=sqr(a[i].x-a[j].x) + sqr(a[i].y-a[j].y);
        sort(1,n);
        l:=1;
        while l <= n do begin
            j:=l;
            while (j < n) and (d[j+1] = d[l]) do inc(j);
            k:=l-j;
            res:=res + (k*(k-1)) shr 1;
            l:=j+1;
        end;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'triland.inp');  reset(fi);
    assign(fo,'triland.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve_1();
    close(fi);
    close(fo);
end.