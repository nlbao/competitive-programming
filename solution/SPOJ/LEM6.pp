const
    INPUT = 'LEM6.inp';
    OUTPUT = 'LEM6.out';
    MAX_N = 1001;
    MAX_M = MAX_N div 2;

var
    fi,fo:text;
    N,M:longint;
    a,minP:array[0..MAX_M] of longint;
    f:array[0..MAX_N,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to M do
        read(fi,a[i]);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    minP[1]:=1;
    for i:=1 to M do
        minP[i]:=minP[i-1]+a[i-1]+1;

    for i:=0 to N do
        for j:=0 to N do f[i,j]:=0;
    for j:=1 to N-a[1]+1 do f[1,j]:=1;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,k:longint;
    res:longint;
begin
    for i:=2 to M do begin
        for j:=minP[i] to (N-a[i]+1) do
            for k:=minP[i-1] to (j-a[i-1]-1) do
                inc(f[i,j],f[i-1,k]);
    end;

    res:=0;
    for j:=minP[M] to (N-a[M]+1) do
        inc(res,f[M,j]);
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