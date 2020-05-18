const   MAX_N = 510;
        MODUN = 1000000007;

type    ll = int64;

var fi,fo:text;
    s:ansiString;
    nTest:longint;
    f,inv:array[0..MAX_N] of ll;

function    mmod(x:ll):ll;  begin   exit(x mod MODUN); end;

function    pow(a,b:ll):ll;
var t:ll;
begin
    if b = 0 then exit(1);
    if b = 1 then exit(mmod(a));
    t:=mmod(sqr(pow(a,b shr 1)));
    if b mod 2 = 0 then exit(t)
    else exit(mmod(a*t));
end;

procedure   init;
var i:longint;
begin
    f[0]:=1;
    for i:=1 to MAX_N do begin
        f[i]:=mmod(f[i-1]*i);
        inv[i]:=pow(f[i],MODUN-2);
    end;
end;

procedure   sort(l,r:longint);
var p,t:char;
    i,j:longint;
begin
    if l >= r then exit;
    p:=s[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while s[i] < p do inc(i);
        while s[j] > p do dec(j);
        if i <= j then begin
            t:=s[i];    s[i]:=s[j];     s[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);  sort(i,r);
end;

procedure   solve;
var n,i,j:longint;
    res:ll;
begin
    n:=length(s);
    res:=f[n];
    randomize;
    sort(1,n);
    i:=1;
    while (i <= n) do begin
        j:=i;
        while (j < n) and (s[j+1] = s[i]) do inc(j);
        res:=mmod(res*inv[j-i+1]);
        i:=j+1;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'WCOUNT.in');     reset(fi);
    assign(fo,'WCOUNT.out');    rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,s);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
