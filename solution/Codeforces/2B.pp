const   INPUT = '2B.in';
        OUTPUT = '2B.out';
        MAX_N = 1010;
        MAX_INT = 2000000000;
        d:array[0..1] of longint = (2,5);
        limit:array[0..1] of longint = (30,13);

var fi,fo:text;
    n,nRes,x0,y0:longint;
    p:array[0..1,0..30] of longint;
    a,f:array[0..MAX_N,0..MAX_N,0..1] of longint;
    res:array[0..sqr(MAX_N)] of char;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   init;
var k,i:longint;
begin
    for k:=0 to 1 do begin
        p[k][0]:=1;
        for i:=1 to limit[k] do p[k][i]:=p[k][i-1]*d[k];
    end;
end;
{---------------------------------------------------------------------------}
function    count(x,k:longint):longint;
var l,r,mid,c:longint;
begin
    l:=1;   r:=limit[k];
    c:=0;
    while (l <= r) do begin
        mid:=(l+r) shr 1;
        if x mod p[k][mid] = 0 then begin
            c:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    exit(c);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j,k,x:longint;
begin
    x0:=-1;
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,x);
            if x = 0 then begin
                x0:=i;  y0:=j;
            end;
            for k:=0 to 1 do a[i][j][k]:=count(x,k);
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k:longint;
begin
    for k:=0 to 1 do begin
        f[1][1][k]:=a[1][1][k];
        for i:=0 to n do begin
            f[0][i][k]:=MAX_INT;
            f[i][0][k]:=MAX_INT;
        end;
        for j:=2 to n do f[1][j][k]:=f[1][j-1][k]+a[1][j][k];
        for i:=2 to n do f[i][1][k]:=f[i-1][1][k]+a[i][1][k];
        for i:=2 to n do
            for j:=2 to n do
                f[i][j][k]:=min(f[i][j-1][k],f[i-1][j][k])+a[i][j][k];
    end;
end;
{---------------------------------------------------------------------------}
procedure   print0;
var i:longint;
begin
    writeln(fo,1);
    for i:=2 to x0 do write(fo,'D');
    for i:=2 to y0 do write(fo,'R');
    for i:=x0+1 to n do write(fo,'D');
    for i:=y0+1 to n do write(fo,'R');
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var i,j,k:longint;
begin
    if f[n][n][0] < f[n][n][1] then k:=0
    else k:=1;
    if (x0 <> -1) and (f[n][n][k] > 1) then begin
        print0;
        exit;
    end;
    i:=n;   j:=n;
    nRes:=0;
    repeat
        inc(nRes);
        if f[i][j-1][k] < f[i-1][j][k] then begin
            res[nRes]:='R';
            dec(j);
        end
        else begin
            res[nRes]:='D';
            dec(i);
        end;
    until (i = 1) and (j = 1);
    writeln(fo,f[n][n][k]);
    for i:=nRes downto 1 do write(fo,res[i]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    enter;
    solve;
    print_result;
    close(fo);
    close(fi);
end.