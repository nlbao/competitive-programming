const
    INPUT = 'Coin34.inp';
    OUTPUT = 'Coin34.out';
    MAX_A = 34;
    MAX_X = 2000000000;
    MAX_M = 1050000;
    MAX_L = 400000;

type
    recF = record
        s,c:longint;
    end;
    arrF = array[0..MAX_M+1] of recF;

var
    fi,fo:text;
    T,X,M2,P1,P2,C,Res,i:longint;
    S:int64;
    A:array[1..MAX_A] of longint;
    F2:arrF;
    L:array[0..MAX_L] of longint;


procedure   A_Init;
var
    i:longint;
begin
    A[1]:=2;    A[2]:=3;    A[3]:=5;
    for i:=4 to MAX_A do
        A[i]:=A[i-1]+A[i-2]+A[i-3];
end;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   Swap(var x,y:recF);
var
    tmp:recF;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

procedure   Quick_sort(var F:arrF;  l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=F[(i+j) div 2].s;
    repeat
        while F[i].s < p do inc(i);
        while F[j].s > p do dec(j);
        if i <= j then
            begin
                Swap(F[i],F[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(F,l,j);
    if i < r then Quick_sort(F,i,r);
end;

procedure   TryF1(i:longint);
var
    j:longint;
begin
    if i > P1 then
        begin
            if S > MAX_L then exit;
            L[S]:=C;
        end
    else
        for j:=0 to 1 do
            begin
                S:=S+j*A[i];
                C:=C+j;
                TryF1(i+1);
                C:=C-j;
                S:=S-j*A[i];
            end;
end;

procedure   TryF2(i:longint);
var
    j,t:longint;
begin
    if i > P2 then
        begin
            if S > MAX_X then exit;
            inc(M2);
            F2[M2].s:=S;
            F2[M2].c:=C;
        end
    else
        for j:=0 to 1 do
            begin
                t:=i+P1;
                S:=S+j*A[t];
                C:=C+j;
                TryF2(i+1);
                C:=C-j;
                S:=S-j*A[t];
            end;
end;

procedure   F_Init;
begin
    P1:=20;
    S:=0;   C:=0;
    TryF1(1);
    P2:=MAX_A-P1;
    M2:=0;
    S:=0;   C:=0;
    TryF2(1);
    Quick_sort(F2,1,M2);
end;

procedure   Find(X:longint);
var
    i,j:longint;
begin
    Res:=-1;
    if (X <= 1) or (X > 1866028165) then exit;
    for i:=1 to M2 do
        if F2[i].s > X then break
        else
            begin
                j:=X-F2[i].s;
                if j <= MAX_L then
                    if (j = 0) or (L[j] <> 0) then
                        Res:=max(Res,F2[i].c+L[j]);
            end;
    if Res = 0 then Res:=-1;
end;

begin
    A_Init;
    F_Init;
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            readln(fi,X);
            Find(X);
            writeln(fo,'Case #',i,': ',Res);
        end;
    close(fo);
    close(fi);
end.
