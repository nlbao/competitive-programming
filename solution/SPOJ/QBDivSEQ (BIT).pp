const
    INPUT = 'QBDivSEQ.inp';
    OUTPUT = 'QBDivSEQ.out';
    MAX_N = 100010;

var
    fi,fo:text;
    N,maxA,value:longint;
    a,id,f:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,a[i]);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[(i+j) shr 1];
    repeat
        while a[i] > p do inc(i);
        while a[j] < p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
    order:array[0..MAX_N] of longint;
begin
    for i:=1 to N do id[i]:=i;
    quick_sort(1,N);
    j:=1;   order[1]:=1;
    for i:=2 to N do begin
        if a[i] <> a[i-1] then inc(j);
        order[i]:=j;
    end;
    for i:=1 to N do a[id[i]]:=order[i];
    maxA:=j;
end;
{---------------------------------------------------------------------------}
procedure   updateF(i:longint); inline;
begin
    if i > maxA then exit;
    f[i]:=max(f[i],value);
    updateF(i+(i and (-i)));
end;
{---------------------------------------------------------------------------}
function    getF(i:longint):longint;    inline;
begin
    if i < 1 then exit(0);
    getF:=max(f[i],getF(i-(i and (-i))));
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,res:longint;
begin
    for i:=1 to maxA do f[i]:=0;
    res:=0;
    for i:=1 to N do begin
        j:=getF(a[i]-1);
        res:=max(res,j+1);
        value:=j+1;
        updateF(a[i]);
    end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.