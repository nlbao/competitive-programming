const
    INPUT = 'MCityHAL.inp';
    OUTPUT = 'MCityHAL.out';
    MAX_M = 200;
    MAX_N = 200;

var
    fi,fo:text;
    M,N:longint;
    A:array[1..MAX_M,1..MAX_N] of char;
    F:array[1..MAX_M] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    for i:=1 to M do begin
        for j:=1 to N do read(fi,A[i,j]);
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,k:longint;
begin
    for i:=1 to M do F[i]:=0;
    for j:=1 to N do begin
        i:=1;
        repeat
            while (i <= M) and (A[i,j] <> '0') do inc(i);
            if i > M then break;
            k:=i;
            while (k+1 <= M) and (A[k+1,j] = A[i,j]) do inc(k);
            inc(F[k-i+1]);
            i:=k+1;
        until i > M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i:longint;
begin
    for i:=1 to MAX_M do
        if F[i] > 0 then
            writeln(fo,i,' ',F[i]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    Print_result;
    close(fo);
    close(fi);
end.