const
    INPUT = 'ChessCBG.inp';
    OUTPUT = 'ChessCBG.out';
    MAX_N = 4;
    MAX_M = sqr(MAX_N);
    MAX = 200000;

type
    arrBoard = array[0..MAX_N+1,0..MAX_N+1] of longint;

var
    fi,fo:text;
    N,M,S,T,Res:longint;
    A,B:arrBoard;
    p2,up,down,left,right:array[0..MAX_M] of longint;

{---------------------------------------------------------------------------}
procedure   Enter(var X:arrBoard);
var
    i,j:longint;
    ch:char;
begin
    N:=MAX_N;
    for i:=1 to N do
        begin
            for j:=1 to N do
                begin
                    read(fi,ch);
                    X[i,j]:=ord(ch)-48;
                end;
            readln(fi);
        end;
end;
{---------------------------------------------------------------------------}
procedure   SetBit(var x:longint;   k,bit:longint);
begin
    if bit = 1 then x:=x or (1 shl (k-1))
    else x:=x and (not (1 shl (k-1)));
end;
{---------------------------------------------------------------------------}
function    GetBit(x,k:longint):longint;
begin
    exit((x shr (k-1)) and 1);
end;
{---------------------------------------------------------------------------}
procedure   SwapBit(var u:longint; i,j:longint);
var
    tmp:longint;
begin
    tmp:=GetBit(u,i);
    SetBit(u,i,GetBit(u,j));
    SetBit(u,j,tmp);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j:longint;
    id:arrBoard;
begin
    p2[0]:=1;
    for i:=1 to MAX_M do p2[i]:=p2[i-1]*2;
    S:=0;   T:=0;
    M:=0;
    for i:=1 to N do
        for j:=1 to N do
            begin
                S:=S+A[i,j]*p2[M];
                T:=T+B[i,j]*p2[M];
                inc(M);
                id[i,j]:=M;
            end;
    for i:=0 to N+1 do
        begin
            id[i,0]:=-1;     id[0,i]:=-1;
            id[i,N+1]:=-1;   id[N+1,i]:=-1;
        end;
    for i:=1 to N do
        for j:=1 to N do
            begin
                up[id[i,j]]:=id[i-1,j];
                down[id[i,j]]:=id[i+1,j];
                left[id[i,j]]:=id[i,j-1];
                right[id[i,j]]:=id[i,j+1];
            end;
end;
{---------------------------------------------------------------------------}
procedure   Solve(S,T:longint);
var
    QSize,i,j,k,u:longint;
    Q,F:array[0..MAX] of longint;
    avail:array[0..MAX] of boolean;

    procedure   Add(u,i:longint; t:char);
    var
        v:longint;
    begin
        v:=u;
        Case t of
            'U': SwapBit(v,i,up[i]);
            'D': SwapBit(v,i,down[i]);
            'L': SwapBit(v,i,left[i]);
            'R': SwapBit(v,i,right[i]);
        end;
        if not avail[v] then exit;
        inc(QSize);
        Q[QSize]:=v;
        F[v]:=F[u]+1;
        avail[v]:=false;
    end;
begin
    for i:=0 to MAX do
        begin
            avail[i]:=true;
            F[i]:=0;
        end;
    QSize:=1;
    Q[1]:=S;
    avail[S]:=false;
    k:=0;
    repeat
        inc(k);
        u:=Q[k];
        for i:=1 to M do
            if GetBit(u,i) = 1 then
                begin
                    if (up[i] <> -1) and (GetBit(u,up[i]) = 0) then Add(u,i,'U');
                    if (down[i] <> -1) and (GetBit(u,down[i]) = 0) then Add(u,i,'D');
                    if (left[i] <> -1) and (GetBit(u,left[i]) = 0) then Add(u,i,'L');
                    if (right[i] <> -1) and (GetBit(u,right[i]) = 0) then Add(u,i,'R');
                end;
    until (QSize = k) or (not avail[T]);
    Res:=F[T];
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter(A);
    Enter(B);
    Init;
    Solve(S,T);
    writeln(fo,Res);
    close(fo);
    close(fi);
end.