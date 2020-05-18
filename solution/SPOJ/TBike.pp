const   INPUT = 'TBike.in';
        OUTPUT = 'TBike.out';
        MAX_N = 2010;
        MAX_INT = 1000000000;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of int64;
    b,f:array[0..MAX_N] of longint;
    g:array[0..MAX_N,0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   quick_sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=b[i+random(j-i+1)];
    repeat
        while b[i] < p do inc(i);
        while b[j] > p do dec(j);
        if i <= j then begin
            t:=b[i];    b[i]:=b[j];     b[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

function    check(l,r:longint):boolean;
var i,d:longint;
begin
    if l = r then exit(true);
    for i:=l to r do b[i-l+1]:=a[i];
    quick_sort(1,r-l+1);
    d:=b[2]-b[1];
    if d = 0 then exit(false);
    for i:=3 to r-l+1 do
        if b[i]-b[i-1] <> d then exit(false);
    exit(true);
end;

procedure   cal_g;
var i,j:longint;
    k,s,p1,p2,p3,d,t1,t2:int64;
begin
    a[n+1]:=0;
    for i:=1 to n-1 do begin
        g[i][i]:=true;
        if a[i] <> a[i+1] then g[i][i+1]:=true
        else g[i][i+1]:=false;
        k:=2;
        b[1]:=a[i]; b[2]:=a[i+1];
        s:=a[i]+a[i+1];
        p1:=min(a[i],a[i+1]);
        p2:=max(a[i],a[i+1]);
        p3:=p2;
        for j:=i+2 to n do begin
            inc(k); b[k]:=a[j];
            s:=s+a[j];
            if a[j] < p1 then begin
                p2:=p1;
                p1:=a[j];
            end
            else p2:=min(p2,a[j]);
            p3:=max(p3,a[j]);
            d:=p2-p1;
            t1:=(2*p1+(k-1)*d)*k;
            t2:=(p1+p3)*k;
            g[i][j]:=false;
            if (p3 = p1+(k-1)*d) and (2*s = t1) and (2*s = t2) then
                if (check(i,j) = true) then g[i][j]:=true
        end;
    end;
end;

procedure   solve;
var i,j:longint;
begin
    randomize;
    cal_g;
    f[0]:=0;
    for i:=1 to n do begin
        f[i]:=i;
        for j:=1 to i do
            if g[i-j+1][i] = true then
                f[i]:=min(f[i],f[i-j]+1);
    end;
    writeln(fo,f[n]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.