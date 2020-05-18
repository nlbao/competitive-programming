const
    INPUT = 'Crate.inp';
    OUTPUT = 'Crate.out';
    MAX_N = 300000;
    MAX_F = 100000;

var
    fi,fo:text;
    N:longint;
    a,h,id,res:array[1..MAX_N+1] of longint;
    F:array[0..MAX_F] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do begin
        readln(fi,a[i],h[i]);
        id[i]:=i;
    end;
end;
{---------------------------------------------------------------------------}
procedure   swap(var x,y:longint);   inline;
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   quick_sortH(l,r:longint);
var
    i,j,p:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=h[(i+j) shr 1];
    repeat
        while h[i] < p do i:=i+1;
        while h[j] > p do j:=j-1;
        if i <= j then begin
            swap(h[i],h[j]);
            swap(a[i],a[j]);
            swap(id[i],id[j]);
            i:=i+1; j:=j-1;
        end;
    until i >= j;
    quick_sortH(l,j);    quick_sortH(i,r);
end;
{---------------------------------------------------------------------------}
procedure   quick_sortA(l,r:longint);
var
    i,j,p:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[(i+j) shr 1];
    repeat
        while a[i] < p do i:=i+1;
        while a[j] > p do j:=j-1;
        if i <= j then begin
            swap(h[i],h[j]);
            swap(a[i],a[j]);
            swap(id[i],id[j]);
            i:=i+1; j:=j-1;
        end;
    until i >= j;
    quick_sortA(l,j);    quick_sortA(i,r);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    h[N+1]:=-1;
    quick_sortH(1,N);
    i:=1;
    while i < N do begin
        j:=i;
        while h[j+1] = h[i] do inc(j);
        quick_sortA(i,j);
        i:=j+1;
    end;
    fillchar(F,sizeof(F),0);
end;
{---------------------------------------------------------------------------}
procedure   updateF(i:longint);
begin
    if i > MAX_F then exit;
    F[i]:=F[i]+1;
    updateF(i+i and (-i));
end;
{---------------------------------------------------------------------------}
function    getF(i:longint):longint;
begin
    if i < 1 then exit(0);
    exit(F[i]+getF(i-i and (-i)));
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    updateF(a[1]);
    res[id[1]]:=0;
    for i:=2 to N do begin
        updateF(a[i]);
        if (h[i] = h[i-1]) and (a[i] = a[i-1]) then
            res[id[i]]:=res[id[i-1]]
        else
            res[id[i]]:=getF(a[i])-1;
    end;

    for i:=1 to N do writeln(fo,res[i]);
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
