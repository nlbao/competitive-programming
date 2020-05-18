const
    INPUT = 'KPLANK.inp';
    OUTPUT = 'KPLANK.out';
    MAX_N = 1000000;

var
    N,Res:longint;
    A:array[0..MAX_N+1] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i:longint;
    L,R:array[1..MAX_N] of longint;
begin
    A[0]:=-1;   A[N+1]:=-1;
    L[1]:=1;
    for i:=2 to N do
        if A[i] > A[i-1] then L[i]:=i
        else
            begin
                L[i]:=L[i-1];
                while A[L[i]-1] >= A[i] do L[i]:=L[i]-1;
            end;
    R[N]:=N;
    for i:=N-1 downto 1 do
        if A[i] > A[i+1] then R[i]:=i
        else
            begin
                R[i]:=R[i+1];
                while A[R[i]+1] >= A[i] do R[i]:=R[i]+1;
            end;
    Res:=0;
    for i:=1 to N do
        if (R[i]-L[i]+1 >= A[i]) and (A[i] > Res) then Res:=A[i];
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Solve;
    Print_result;
end.
