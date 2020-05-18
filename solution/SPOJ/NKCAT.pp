const
    INPUT = 'NKCAT.inp';
    OUTPUT = 'NKCAT.out';
    MAX_N = 16;
    MAX_M = 33;

var
    N,M,K,C:longint;
    A,X:array[1..MAX_M] of longint;
    avail:array[-1..MAX_M,-1..MAX_N] of boolean;
    T:array[-1..MAX_M,-1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    M:=2*N+1;
    for i:=1 to M do read(fi,A[i]);
    readln(fi);
    read(fi,K);
    close(fi);
end;

procedure   Init;
var
    i,j:longint;
begin
    for i:=-1 to MAX_N do
        begin
            avail[1,i]:=false;
            avail[2,i]:=false;
        end;
    avail[1,0]:=true;   avail[2,1]:=true;
    for i:=3 to M do
        begin
            for j:=0 to N do
                if (avail[i-1,j-1]) or (avail[i-1,j+1]) then
                    avail[i,j]:=true
                else
                    avail[i,j]:=false;
        end;
    T[M,0]:=1;
    for i:=M-1 downto 1 do
        for j:=0 to N do
            if avail[i,j] then T[i,j]:=T[i+1,j-1]+T[i+1,j+1]
            else T[i,j]:=0;
end;

procedure   Find_C;
var
    i,l,r:longint;
begin
    l:=1;   r:=T[1,0];
    for i:=3 to M do
        begin
            if l = r then break;
            if A[i] = A[i-1]-1 then r:=r-T[i,A[i]+2]
            else l:=l+T[i,A[i]-2];
        end;
    C:=l;
end;

procedure   Find_X(K:longint);
var
    i:longint;
begin
    if K > T[1,0] then exit;
    X[1]:=0;    X[2]:=1;
    for i:=3 to M do
        begin
            if K = 0 then break;
            if K <= T[i,X[i-1]-1] then
                X[i]:=X[i-1]-1
            else
                begin
                    K:=K-T[i,X[i-1]-1];
                    X[i]:=X[i-1]+1;
                end;
        end;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,C);
    for i:=1 to M do
        write(fo,X[i],' ');
    close(fo);
end;

begin
    Enter;
    Init;
    Find_C;
    Find_X(K);
    Print_result;
end.