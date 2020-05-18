const
    INPUT = 'NKGolf.inp';
    OUTPUT = 'NKGolf.out';
    MAX_N = 1010;
    MAX_M = 1010;
    MAX_H = 500;

var
    fi,fo:text;
    N,M,Res:longint;
    H,A:array[0..MAX_M,0..MAX_N] of longint;
    L,R,P:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    for i:=1 to M do
        for j:=1 to N do
            read(fi,H[i,j]);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    for i:=1 to M do H[i,0]:=-MAX_H;
    for j:=1 to N do H[0,j]:=-MAX_H;
    for j:=1 to N do begin
        H[0,j]:=-MAX_H;
        A[0,j]:=0;
        for i:=1 to M do
            if H[i,j] < H[i,j-1] then A[i,j]:=0
            else
                if H[i,j] < H[i-1,j] then A[i,j]:=1
                else A[i,j]:=A[i-1,j]+1;
    end;

    for i:=1 to N do P[j]:=0;
end;
{---------------------------------------------------------------------------}
procedure   dac_biet;
var
    i,j:longint;
begin

end;
{---------------------------------------------------------------------------}
procedure   tinh_P(i:longint);
var
    j:longint;
begin
    for j:=1 to N do
        if H[i,j] < H[i-1,j] then P[j]:=1
        else P[j]:=P[j]+1;
end;
{---------------------------------------------------------------------------}
procedure   tinh_L(i:longint);
var
    j:longint;
begin
    A[i,0]:=-MAX_H;
    L[1]:=1;
    for j:=2 to N do
        if A[i,j] > A[i,j-1] then L[j]:=j
        else begin
            L[j]:=L[j-1];
            while A[i,L[j]-1] >= A[i,j] do L[j]:=L[L[j]-1];
        end;

    for j:=1 to N do
        if (L[j] > 1) and (P[L[j]-1] >= A[i,j]) then
            L[j]:=L[j]-1;
end;
{---------------------------------------------------------------------------}
procedure   tinh_R(i:longint);
var
    j:longint;
begin
    A[i,N+1]:=-MAX_H;
    R[N]:=N;
    for j:=N-1 downto 1 do
        if A[i,j] > A[i,j+1] then R[j]:=j
        else begin
            R[j]:=R[j+1];
            while A[i,R[j]+1] >= A[i,j] do R[j]:=R[R[j]+1];
        end;
end;
{---------------------------------------------------------------------------}
procedure   update(i:longint);
var
    j:longint;
begin
    for j:=1 to N do begin
        Res:=max(Res,A[i,j]*(R[j]-L[j]+1));
        Res:=max(Res,P[j]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    Res:=-1;
    dac_biet;
    for i:=1 to M do begin
        tinh_P(i);
        tinh_L(i);
        tinh_R(i);
        update(i);
    end;
    if Res = -1 then Res:=1;

    writeln(fo,Res);
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