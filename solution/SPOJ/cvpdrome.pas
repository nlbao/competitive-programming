{$M 16777216}
uses    math;

const   MAX_N = 3*100005;
        MAX_M = 53;
        oo = 1000000000;
        BASE = 10007;

type    ll = int64;

var fi,fo:text;
    n,m:longint;
    s:ansiString;
    h,f:array[0..MAX_N] of ll;


procedure   enter();
var i:longint;
begin
    readln(fi,n);
    readln(fi,s);
end;


function    num(x:char):longint;
begin
    if ('a' <= x) and (x <= 'z') then exit(ord(x)-ord('a'));
    exit(ord(x)-ord('A')+26);
end;


procedure   sort(l,r:longint);
var i,j:longint;
    p,t:ll;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=h[i];
    i:=l;   j:=r;
    repeat
        while h[i] < p do inc(i);
        while h[j] > p do dec(j);
        if i <= j then begin
            t:=h[i];
            h[i]:=h[j];
            h[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


procedure   solve();
var i,j,k:longint;
    d,x,res,tmp:ll;
begin
    res:=0;
    d:=1;
    h[1]:=0;
    for i:=1 to n do
        h[i+1]:=h[i] xor (d shl num(s[i]));

    randomize;
    sort(1,n+1);

    i:=1;   k:=0;
    while i <= n+1 do begin
        j:=i;
        while (j <= n+1) and (h[j] = h[i]) do inc(j);
        x:=j-i;
        res:=res + (x*(x-1)) div 2;
        h[i-k]:=h[i];
        f[i-k]:=x;
        k:=k+x-1;
        i:=j;
    end;
    m:=n+1-k;

    for k:=0 to 51 do begin
        x:=d shl k;
        j:=0;
        for i:=1 to m do begin
            while (j <= m) and (h[j]-x < h[i]) do inc(j);
            if j > m then break;
            if (h[j] xor h[i]) = x then
                res:=res + f[i]*f[j];
        end;
    end;
    writeln(fo,res);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'CVPDROME.in');    reset(fi);
    assign(fo,'CVPDROME.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.