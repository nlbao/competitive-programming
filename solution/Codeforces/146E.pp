const   MAX_N = 100010;

type    int = int64;

var fi,fo:text;
    n,k,m,nP,num:longint;
    a,c,p:array[0..MAX_N] of longint;
    b,d:array[0..700] of int;
    is_prime:array[0..MAX_N] of boolean;


procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
end;

function    mmod(x:int):int;    begin   exit(x mod 1000000007); end;

procedure   qsort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=b[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while (b[i] < p) do inc(i);
        while (b[j] > p) do dec(j);
        if i <= j then begin
            t:=b[i];    b[i]:=b[j];     b[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   tryf(i:longint);
begin
    if i > 8 then exit;
    num:=num*10+4;
    inc(m); b[m]:=num;
    tryf(i+1);
    num:=num div 10;

    num:=num*10+7;
    inc(m); b[m]:=num;
    tryf(i+1);
    num:=num div 10;
end;

function    is_lucky(n:longint):boolean;
var i:longint;
begin
    repeat
        i:=n mod 10;
        if (i <> 4) and (i <> 7) then exit(false);
        n:=n div 10;
    until n = 0;
    exit(true);
end;

procedure   Eratosthene;
var i,j:longint;
begin
    nP:=0;
    for i:=2 to MAX_N do is_prime[i]:=true;
    for i:=2 to MAX_N do
        if is_prime[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i+i;
            while j <= MAX_N do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;

procedure   init;
var i,l,r,mid:longint;
begin
    m:=0;   num:=0;
    tryf(1);
    randomize;
    qsort(1,m);
    for i:=1 to n do
        if is_lucky(a[i]) then begin
            l:=1;   r:=m;
            repeat
                mid:=(l+r) shr 1;
                if b[mid] = a[i] then begin
                    a[i]:=mid;
                    break;
                end
                else if b[mid] < a[i] then l:=mid+1
                else r:=mid-1;
            until l > r;
        end;
    Eratosthene;
end;

procedure   pt(n,v:longint);
var i,j:longint;
begin
    for i:=1 to nP do
        if p[i] > n then break
        else begin
            j:=0;
            while n mod p[i] = 0 do begin
                inc(j);
                n:=n div p[i];
            end;
            c[i]:=c[i]+j*v;
        end;
end;

function    cal_c(k,n:longint):int;
var i,j:longint;
    res:int;
begin
    if (k = 0) or (k = n) then exit(1);
    if k > n then exit(0);
    res:=1;
    for i:=1 to nP do c[i]:=0;
    for i:=n-k+1 to n do pt(i,1);
    for i:=1 to k do pt(i,-1);
    for i:=1 to nP do
        for j:=1 to c[i] do
            res:=mmod(res*p[i]);

    writeln(k,' ',n,'     ',res);
    exit(res);
end;

procedure   solve;
var i,j:longint;
    res:int;
begin
    for i:=1 to m do d[i]:=0;
    j:=0;
    for i:=1 to n do
        if a[i] < 1 then inc(j)
        else inc(d[a[i]]);
    res:=cal_c(k,j);
    for i:=1 to m do
        if d[i] > 0 then
            res:=mmod(res+mmod(d[i]*cal_c(k-1,n-d[i])));
    writeln(fo,res);
end;

begin
    assign(fi,'146E.in');   reset(fi);
    assign(fo,'146E.out');  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.