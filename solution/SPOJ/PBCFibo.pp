const
    INPUT = 'PBCFibo.inp';
    OUTPUT = 'PBCFibo.out';
    MAX_K = 10000;

var
    N,S:int64;
    C,K,R:longint;
    F:array[1..2*MAX_K] of longint;
    T:array[1..2*MAX_K] of int64;
procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,K,S);
    close(fi);
end;

procedure   Swap(var x,y:int64);
var
    tmp:int64;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

procedure   Quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    i:=l;   j:=r;
    p:=F[(i+j) div 2];
    repeat
        while F[i] < p do inc(i);
        while F[j] > p do dec(j);
        if i <= j then
            begin
                tmp:=F[i];
                F[i]:=F[j];
                F[j]:=tmp;
                Swap(T[i],T[j]);
                inc(i);
                dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;

procedure   Find;
var
    i:longint;
    p,q,S0:int64;
    check:boolean;
begin
    R:=0;
    if N = 1 then
        begin
            R:=1;
            exit;
        end;
    if K = 1 then
        begin
            if S = N then R:=2
            else
                if S = N-1 then R:=1;
            exit;
        end;
    if K = 2 then
        begin
            if S = N then R:=2
            else
                if S = N-1 then R:=1
                else
                    if S <= ((N-2) div 3) then R:=0
                    else R:=1;
            exit;
        end;
    C:=0;
    F[1]:=1;    F[2]:=2;
    i:=2;
    repeat
        check:=false;
        inc(i);
        F[i]:=(F[i-1]+F[i-2]) mod K;
        if (F[i-1] = 1) and (F[i] = 2) then
            check:=true;
    until check = true;
    if check = true then C:=i-2;
    p:=N div C;
    q:=N mod C;
    for i:=1 to C do T[i]:=p;
    for i:=1 to q do inc(T[i]);
    Quick_sort(1,C);
    S0:=0;
    for i:=1 to C do
        if (S0+T[i]) >= S then
            begin
                R:=F[i];
                break;
            end
        else
            S0:=S0+T[i];  end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,R);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.