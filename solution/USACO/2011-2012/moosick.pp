{
    PROB: moosick
    LANG: PASCAL
    ID: storm59061
}

const   INPUT = 'moosick.in';
        OUTPUT = 'moosick.out';
        MAX_N = 20010;
        MAX_C = 20;

type    arrX = array[0..MAX_C] of longint;

var fi,fo:text;
    n,c:longint;
    a:array[0..MAX_N] of longint;
    b:arrX;

procedure   enter;
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);
    read(fi,c);
    for i:=1 to c do read(fi,b[i]);
end;

procedure   quick_sort(var x:arrX;  l,r:longint);
var i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[(i+j) shr 1];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            tmp:=x[i]; x[i]:=x[j];  x[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,l,j);  quick_sort(x,i,r);
end;

function    check(var x:arrX):boolean;
var i,t:longint;
begin
    quick_sort(x,1,c);
    t:=x[1]-b[1];
    for i:=2 to c do
        if x[i]-b[i] <> t then exit(false);
    exit(true);
end;

procedure   solve;
var i,j,nRes:longint;
    x:arrX;
    res:array[0..MAX_N] of longint;
begin
    nRes:=0;
    quick_sort(b,1,c);
    for i:=1 to n-c+1 do begin
        for j:=1 to c do x[j]:=a[i+j-1];
        if check(x) = true then begin
            inc(nRes);  res[nRes]:=i;
        end;
    end;
    writeln(fo,nRes);
    for i:=1 to nRes do writeln(fo,res[i]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
