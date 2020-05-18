const
    INPUT = 'ples.inp';
    OUTPUT = 'ples.out';
    MAX_N = 100010;

type
    arr = array[0..MAX_N] of longint;

var
    fi,fo:text;
    N,nA,nB,nC,nD,res:longint;
    a,b,c,d:arr;

{---------------------------------------------------------------------------}
procedure   add(k:longint;  var x:arr;  var n:longint);
begin
    inc(n);
    x[n]:=k;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,x:longint;
begin
    nA:=0;  nB:=0;  nC:=0;  nD:=0;
    readln(fi,N);
    for i:=1 to N do begin
        read(fi,x);
        if x > 0 then add(x,a,nA)
        else add(-x,d,nD);
    end;
    for i:=1 to N do begin
        read(fi,x);
        if x > 0 then add(x,c,nC)
        else add(-x,b,nB);
    end;
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
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
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
procedure   solve(var x1,x2:arr;    n1,n2:longint);
var
    i,j:longint;
begin
    x2[n2+1]:=-MAXLONGINT;
    j:=1;
    for i:=1 to n1 do
        if x2[j] > x1[i] then begin
            inc(res);
            inc(j);
        end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    quick_sort(a,1,nA);
    quick_sort(b,1,nB);
    quick_sort(c,1,nC);
    quick_sort(d,1,nD);
    res:=0;
    solve(a,b,nA,nB);
    solve(c,d,nC,nD);
    writeln(fo,res);
    close(fo);
    close(fi);
end.