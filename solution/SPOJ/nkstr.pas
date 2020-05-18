{$R+, $I+, $Q+}
{$M+ 16777216}

uses    math;

const   MAX_N = 300010;
        MAX_M = 5005;
        MAX_L = 5005;
        BASE = 10007;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nA,i,j,k:longint;
    s,t:ansiString;
    h:array[0..MAX_M] of ll;
    p,g:array[0..MAX_N] of ll;
    a:array[0..MAX_M] of longint;
    ok:array[0..MAX_N] of boolean;


procedure   sort(l,r:longint);
var i,j,p,t:longint;
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


function    getG(i,j:longint):longint;
begin   exit(longint(g[j]-g[i-1]*p[j-i+1]));    end;


function    check(x:longint):boolean;
var l,r,mid:longint;
begin
    l:=1;   r:=m;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if h[mid] = x then exit(true)
        else if h[mid] < x then l:=mid+1
        else r:=mid-1;
    end;
    exit(false);
end;


function    find(i:longint):longint;
var l,r,mid,j,res:longint;
begin
    res:=-1;
    {l:=1;   r:=nA;
    while l <= r do begin
        mid:=(l+r) shr 1;
        j:=i+a[mid]-1;
        if (j <= n) and (check(getG(i,j))) then begin
            res:=j;
            l:=mid+1;
        end
        else r:=mid-1;
    end;}
    for l:=nA downto 1 do begin
        j:=i+a[l]-1;
        if j > n then continue;
        if check(getG(i,j)) then exit(j);
    end;
    exit(res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKSTR.in');    reset(fi);
    assign(fo,'NKSTR.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,n);
    readln(fi,s);
    p[0]:=1;
    g[0]:=0;
    for i:=1 to n do begin
        p[i]:=longint(p[i-1]*BASE);
        g[i]:=longint(g[i-1]*BASE+ord(s[i]));
    end;

    nA:=0;
    readln(fi,m);
    for i:=1 to m do begin
        h[0]:=0;
        readln(fi,t);
        k:=length(t);
        for j:=1 to k do
            h[j]:=longint(h[j]*BASE+ord(t[j]));
    end;
    randomize;
    sort(1,m);

    nA:=0;
    for i:=1 to MAX_L do
        if ok[i] then begin
            inc(nA);
            a[nA]:=i;
        end;

    k:=0;
    for i:=1 to n do ok[i]:=false;
    for i:=1 to n do begin
        j:=find(i);
        if j < i then continue;
        k:=max(k,i-1);
        while k < j do begin
            k:=k+1;
            ok[k]:=true;
        end;
    end;

    k:=0;
    for i:=1 to n do k:=k+longint(not ok[i]);
    writeln(fo,k);
    close(fi);
    close(fo);
end.

