const
    INPUT = 'MBlast.inp';
    OUTPUT = 'MBlast.out';
    MAX_N = 2001;
    MAX_M = MAX_N;

var
    fi,fo:text;
    N,M,K:longint;
    a,b:ansiString;
    f:array[0..MAX_N,0..MAX_M] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,a);
    readln(fi,b);
    readln(fi,K);
    N:=length(a);   M:=length(b);
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
begin
    f[0,0]:=0;
    for i:=1 to N do f[i,0]:=K*i;
    for j:=1 to M do f[0,j]:=K*j;
    for i:=1 to N do
        for j:=1 to M do begin
            f[i,j]:=f[i-1,j-1]+min(2*K,abs(ord(a[i])-ord(b[j])));
            f[i,j]:=min(f[i,j],min(f[i,j-1]+K,f[i-1,j]+K));
        end;
    writeln(fo,f[N,M]);
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