const
    INPUT = 'QBRECT.inp';
    OUTPUT = 'QBRECT.out';
    MAX_M = 1000;
    MAX_N = 1000;

var
    M,N,Res:longint;
    H:array[0..MAX_M+1,0..MAX_N+1] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,M,N);
    for j:=1 to N do H[0,j]:=0;
    for i:=1 to M do
        for j:=1 to N do
            begin
                read(fi,H[i,j]);
                if H[i,j] = 1 then H[i,j]:=H[i-1,j]+1;
            end;
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,S:longint;
    L,R:array[1..MAX_N] of longint;
begin
    Res:=0;
    for i:=1 to M do
        begin
            H[i,0]:=-1; H[i,N+1]:=-1;
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
                begin
                    S:=H[i,j]*(R[j]-L[j]+1);
                    if S > Res then Res:=S;
                end;
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
