const
    INPUT = 'MStick.inp';
    OUTPUT = 'MStick.out';
    MAX_N = 20010;

var
    fi,fo:text;
    nTest,N:longint;
    w,h,f:array[0..MAX_N] of longint;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,w[i],h[i]);
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
procedure   quick_sortW(l,r:longint);
var
    i,j,p:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=w[(i+j) shr 1];
    repeat
        while w[i] > p do inc(i);
        while w[j] < p do dec(j);
        if i <= j then begin
            swap(w[i],w[j]);
            swap(h[i],h[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sortW(l,j);    quick_sortW(i,r);
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
        while h[i] > p do inc(i);
        while h[j] < p do dec(j);
        if i <= j then begin
            swap(h[i],h[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sortH(l,j);    quick_sortH(i,r);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    quick_sortW(1,N);
    h[N+1]:=-maxLONGINT;
    i:=1;
    repeat
        j:=i;
        while w[j+1] = w[i] do inc(j);
        quick_sortH(i,j);
        i:=j+1;
    until i > N;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,k,l,r,mid:longint;
begin
    F[1]:=1;
    k:=1;
    for i:=2 to N do
        if h[i] < h[F[1]] then
            F[1]:=i
        else
            if h[i] > h[F[k]] then begin
                inc(k);
                F[k]:=i;
            end
            else begin
                l:=1;   r:=k;
                while l < r do begin
                    mid:=(l+r) div 2;
                    if h[i] > h[F[mid]] then l:=mid+1
                    else r:=mid;
                end;
                mid:=(l+r) div 2;
                F[mid]:=i;
            end;
    writeln(fo,k);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        init;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
