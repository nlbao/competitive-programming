const
    INPUT = 'Meo.inp';
    OUTPUT = 'Meo.out';
    MAX_N = 1000;
    MAX_K = 3000;

var
    fi,fo:text;
    N,K:longint;
    A:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    S:ansiString;
begin
    readln(fi,N,K);
    readln(fi,S);
    for i:=1 to N do
        case S[i] of
            'R': A[i]:=1;
            'G': A[i]:=2;
            'W': A[i]:=3;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,pre:longint;
    next:array[1..MAX_N] of longint;
    C:array[1..3,1..3] of longint;
begin
    C[1,1]:=1;  C[1,2]:=3;  C[1,3]:=2;
    C[2,1]:=3;  C[2,2]:=2;  C[2,3]:=1;
    C[3,1]:=2;  C[3,2]:=1;  C[3,3]:=3;
    for i:=1 to N-1 do next[i]:=i+1;
    next[N]:=1;
    for j:=1 to K do
        for i:=1 to N do begin
            pre:=A[i];
            A[i]:=C[pre,A[next[i]]];
            A[next[i]]:=C[pre,A[next[i]]];
        end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i:longint;
begin
    for i:=1 to N do
        case A[i] of
            1: write(fo,'R');
            2: write(fo,'G');
            3: write(fo,'W');
        end;
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