const   INPUT = 'LJUTNJA.in';
        OUTPUT = 'LJUTNJA.out';
        MAX_N = 100010;
        MAX_M = 2000000010;

var fi,fo:text;
    n:longint;
    m:int64;
    a:array[0..MAX_N] of int64;

{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    readln(fi,m,n);
    for i:=1 to n do read(fi,a[i]);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var i,j:longint;
    p,tmp:int64;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[(i+j) shr 1];
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            tmp:=a[i]; a[i]:=a[j];  a[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
    sum:int64;
    w,res:int64;
begin
    res:=0; sum:=-m;
    for i:=1 to n do sum:=sum+a[i];
    for i:=1 to n do begin
        w:=n-i+1;
        w:=sum div w;
        if a[i] < w then w:=a[i];
        writeln(sum,' ',w,' ',w*w,' ',res);
        sum:=sum-w;
        res:=res+w*w;
    end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    quick_sort(1,n);
    solve;
    close(fo);
    close(fi);
end.
