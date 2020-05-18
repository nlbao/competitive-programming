const   INPUT = 'C11BC1.in';
        OUTPUT = 'C11BC1.out';
        MAX_N = 100010;
        MAX_P = 60;
        MODUN = 790972;

type    int = qword;

var fi,fo:text;
    n,p,m:longint;
    a,b:array[0..MAX_N] of int;
    f:array[0..1,0..MAX_P] of int;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,p);
    for i:=1 to n do read(fi,a[i],b[i]);
end;

procedure   swap(var x,y:int);
var t:int;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   quick_sort(l,r:longint);
var i,j:longint;
    p:int;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=b[i+random(j-i+1)];
    repeat
        while b[i] < p do inc(i);
        while b[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

function    cal_f(l,r:longint):int;
var i,j,t,tt:longint;
begin
    t:=1;
    f[1][0]:=1; f[1][1]:=a[l];
    for j:=2 to p do f[1][j]:=0;
    for i:=l+1 to r do begin
        tt:=t;
        t:=(t+1) mod 2;
        f[t][0]:=1;
        for j:=i-l+2 to p do f[t][j]:=0;
        for j:=1 to min(i-l+1,p) do
            f[t][j]:=(f[tt][j]+(f[tt][j-1]*a[i]) mod MODUN) mod MODUN;
    end;
    exit(f[t][p]);
end;

function    solve:longint;
var i,j:longint;
    res:int;
begin
    if n < p then exit(0);
    randomize;
    quick_sort(1,n);
    res:=0;
    i:=1;
    while i <= n do begin
        j:=i;
        while (j < n) and (b[j+1] = b[i]) do inc(j);
        if j-i+1 >= p then res:=(res+cal_f(i,j)) mod MODUN;
        i:=j+1;
    end;
    res:=cal_f(1,n)-res;
    while res < 0 do res:=res+MODUN;
    exit(res mod MODUN);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.