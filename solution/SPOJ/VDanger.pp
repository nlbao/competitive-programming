const
    INPUT = 'VDanger.inp';
    OUTPUT = 'VDanger.out';
    MAX_N = 100;
    MAX_M = 10000;

var
    N,M,S:longint;
    A:array[1..MAX_M] of longint;
    F:array[1..MAX_N,1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    for i:=1 to M do read(fi,A[i]);
    for i:=1 to N do
        for j:=1 to N do
            read(fi,F[i,j]);
    close(fi);
end;

procedure   Floyd;
var
    u,v,k:longint;
begin
    for k:=1 to N do
        for u:=1 to N do
            for v:=1 to N do
                if F[u,k]+F[k,v] < F[u,v] then
                    F[u,v]:=F[u,k]+F[k,v];
end;

procedure   Find;
var
    i:longint;
begin
    for i:=2 to M do
        S:=S+F[A[i-1],A[i]];
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,S);
    close(fo);
end;

begin
    Enter;
    Floyd;
    Find;
    Print_result;
end.