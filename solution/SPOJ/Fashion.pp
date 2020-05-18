const
    INPUT = 'Fashion.inp';
    OUTPUT = 'Fashion.out';
    MAX_N = 1010;

type
    arr = array[0..MAX_N] of longint;

var
    fi,fo:text;
    nTest,N:longint;
    a,b:arr;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,a[i]);
    for i:=1 to N do read(fi,b[i]);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(var x:arr;   l,r:longint);
var
    i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[(i+j) div 2];
    repeat
        while x[i] > p do inc(i);
        while x[j] < p do dec(j);
        if i <= j then begin
            tmp:=x[i];
            x[i]:=x[j];
            x[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,l,j);    quick_sort(x,i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,res:longint;
begin
    res:=0;
    for i:=1 to N do
        res:=res+a[i]*b[i];
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        quick_sort(a,1,N);
        quick_sort(b,1,N);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.