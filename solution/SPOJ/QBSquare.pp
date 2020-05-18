const
    INPUT = 'QBSquare.inp';
    OUTPUT = 'QBSquare.out';
    MAX_M = 1000;
    MAX_N = 1000;

var
    M,N,Res:longint;
    A,H:array[0..MAX_M+1,0..MAX_N+1] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,M,N);
    for i:=1 to M do
        for j:=1 to N do
            read(fi,A[i,j]);
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,k:longint;
    L,R:array[1..MAX_N] of longint;
begin
    Res:=0;
    for j:=1 to N do H[0,j]:=0;
    for k:=0 to 1 do
        for i:=1 to M do
            begin
                H[i,0]:=-1; H[i,N+1]:=-1;
                for j:=1 to N do
                    if A[i,j] = k then H[i,j]:=H[i-1,j]+1
                    else H[i,j]:=0;
                L[1]:=1;
                for j:=2 to N do
                    if H[i,j] > H[i,j-1] then L[j]:=j
                    else
                        begin
                            L[j]:=L[j-1];
                            while H[i,L[j]-1] >= H[i,j] do L[j]:=L[L[j]-1];
                        end;
                R[N]:=N;
                for j:=N-1 downto 1 do
                    if H[i,j] > H[i,j+1] then R[j]:=j
                    else
                        begin
                            R[j]:=R[j+1];
                            while H[i,R[j]+1] >= H[i,j] do R[j]:=R[R[j]+1];
                        end;
                for j:=1 to N do
                    if (R[j]-L[j]+1 >= H[i,j]) and (H[i,j] > Res) then Res:=H[i,j];
            end;
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
