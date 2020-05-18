const   INPUT = 'NKLineUp.inp';
        OUTPUT = 'NKLineUp.out';
        MAX_N = 50010;
        MAX_Q = 200010;
        MAX_LOG = 20;

var fi,fo:text;
    n,q:longint;
    a:array[0..MAX_N] of longint;
    Rmax,Rmin:array[0..MAX_N,0..MAX_LOG] of longint;

{--------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{--------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{--------------------------------------------------------------------------}
function    log(n,k:longint):double;
begin
    exit(ln(n)/ln(k));
end;
{--------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    readln(fi,n,q);
    for i:=1 to n do readln(fi,a[i]);
end;
{--------------------------------------------------------------------------}
procedure   init_RMQ;
var i,j:longint;
begin
    for i:=1 to n do begin
        Rmax[i][0]:=a[i];
        Rmin[i][0]:=a[i];
    end;
    for j:=1 to trunc(log(n,2)) do
        for i:=1 to n-(1 shl j)+1 do begin
            Rmax[i][j]:=max( Rmax[i][j-1], Rmax[i+(1 shl (j-1))][j-1] );
            Rmin[i][j]:=min( Rmin[i][j-1], Rmin[i+(1 shl (j-1))][j-1] );
        end;
end;
{--------------------------------------------------------------------------}
function    find(i,j:longint):longint;
var k:longint;
begin
    k:=trunc(log(j-i+1,2));
    exit( max( Rmax[i][k], Rmax[j-(1 shl k)+1][k] ) - min( Rmin[i][k], Rmin[j-(1 shl k)+1][k] ) );
end;
{--------------------------------------------------------------------------}
procedure   solve;
var i,j:longint;
begin
    while q > 0 do begin
        readln(fi,i,j);
        writeln(fo,find(i,j));
        dec(q);
    end;
end;
{--------------------------------------------------------------------------}
begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init_RMQ;
    solve;
    close(fo);
    close(fi);
end.