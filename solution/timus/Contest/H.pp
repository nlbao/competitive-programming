const
    INPUT = 'H.inp';
    OUTPUT = 'H.out';
    MAX_N = 4010;

type
    arr = array[0..MAX_N] of longint;

var
    fi,fo:text;
    nA,nB,nC:longint;
    a,b,c:arr;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,nA);
    for i:=1 to nA do read(fi,a[i]);
    readln(fi,nB);
    for i:=1 to nB do read(fi,b[i]);
    readln(fi,nC);
    for i:=1 to nC do read(fi,c[i]);
end;
{---------------------------------------------------------------------------}
function    find(k:longint; var x:arr;  n:longint):boolean;
var
    l,r,mid:longint;
begin
    l:=1;   r:=n;
    while l <= r do begin
        mid:=(l+r) div 2;
        if x[mid] = k then exit(true)
        else
            if x[mid] > k then r:=mid-1
            else l:=mid+1;
    end;
    exit(false);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,res:longint;
begin
    res:=0;
    for i:=1 to nA do
        if (find(a[i],b,nB) = true) and (find(a[i],c,nC) = true) then
            inc(res);
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.