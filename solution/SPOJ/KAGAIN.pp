const
    INPUT = '';
    OUTPUT = '';
    MAX_N = 30000;

type
    recRes = record
        S,l,r:longint;
    end;

var
    fi,fo:text;
    T,N,i:longint;
    A:array[0..MAX_N+1] of longint;
    Res:recRes;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    read(fi,N);
    for i:=1 to N do read(fi,A[i]);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,S:longint;
    L,R:array[1..MAX_N] of longint;
begin
    A[0]:=-1;   A[N+1]:=-1;
    L[1]:=1;
    for i:=2 to N do
        if A[i] <= A[i-1] then
            begin
                L[i]:=L[i-1];
                while A[L[i]-1] >= A[i] do L[i]:=L[L[i]-1];
            end
        else L[i]:=i;
    R[N]:=N;
    for i:=N-1 downto 1 do
        if A[i] <= A[i+1] then
            begin
                R[i]:=R[i+1];
                while A[R[i]+1] >= A[i] do R[i]:=R[R[i]+1];
            end
        else R[i]:=i;
    Res.S:=-1;
    for i:=1 to N do
        begin
            S:=A[i]*(R[i]-L[i]+1);
            if S > Res.S then
                begin
                    Res.S:=S;
                    Res.l:=L[i];   Res.r:=R[i];
                end;
        end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,T);
    for i:=1 to T do
        begin
            Enter;
            Solve;
            writeln(fo,Res.S,' ',Res.l,' ',Res.r);
        end;
    close(fo);
    close(fi);
end.
