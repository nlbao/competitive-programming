const
    INPUT = 'LNACS.inp';
    OUTPUT = 'LNACS.out';
    MAX_N = 1000;
    MAX_M = 1000;

var
    M,N,maxF:longint;
    A:array[1..MAX_M] of longint;
    B:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,M,N);
    for i:=1 to M do
        read(fi,A[i]);
    for i:=1 to N do
        read(fi,B[i]);
    close(fi);
end;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   Find;
var
    i,j:longint;
    F:array[-1..MAX_M,-1..MAX_N] of longint;
begin
    F[-1,-1]:=0;
    F[0,0]:=0;
    F[0,1]:=0;
    F[1,0]:=0;
    maxF:=0;
    for i:=1 to M do
        for j:=1 to N do
            begin
                if A[i] = B[j] then
                    F[i,j]:=F[i-2,j-2]+1
                else
                    F[i,j]:=max(F[i-1,j],F[i,j-1]);
                if F[i,j] > maxF then maxF:=F[i,j];
            end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,maxF);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.