const
    INPUT = 'QBSTR.inp';
    OUTPUT = 'QBSTR.out';
    MAX_N = 1000;
    MAX_M = 1000;

var
    fi,fo:text;
    A,B:ansiString;
    N,M,i,j:longint;
    F:array[0..MAX_M,0..MAX_N] of longint;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,A);   readln(fi,B);
    M:=length(A);   N:=length(B);
    for i:=0 to M do F[i,0]:=0;
    for j:=0 to N do F[0,j]:=0;
    for i:=1 to M do
        for j:=1 to N do begin
            if A[i] = B[j] then F[i,j]:=F[i-1,j-1]+1
            else F[i,j]:=0;
            F[i,j]:=max(max(F[i,j],F[i-1,j]),F[i,j-1]);
        end;
    writeln(fo,F[M,N]);
    close(fo);
    close(fi);
end.