{
    PROB: umbrella
    LANG: PASCAL
    ID: storm59061
}

const   INPUT = 'umbrella.in';
        OUTPUT = 'umbrella.out';
        MAX_N = 5010;
        MAX_M = 100010;
        MAX_C = 1000010;
        MAX_INT = 1000000000000000000;

type    int = int64;

var fi,fo:text;
    n,m:longint;
    x:array[0..MAX_N] of longint;
    c,r:array[0..MAX_M] of int;
    f:array[0..MAX_N] of int;

function    min(x,y:int):int;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do read(fi,x[i]);
    for i:=1 to m do read(fi,c[i]);
end;

procedure   quick_sort(l,r:longint);
var i,j:longint;
    p,t:int;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[(i+j) shr 1];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            t:=x[i];    x[i]:=x[j];     x[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;


procedure   solve;
var i,j:longint;
begin
    quick_sort(1,n);
    r[m]:=c[m];
    for i:=m-1 downto 1 do
        r[i]:=min(r[i+1],c[i]);
    f[0]:=0;
    for i:=1 to n do begin
        f[i]:=f[i-1]+r[1];
        for j:=i-1 downto 1 do
            f[i]:=min(f[i],f[j-1]+r[x[i]-x[j]+1]);
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