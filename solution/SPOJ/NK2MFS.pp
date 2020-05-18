const
    INPUT = 'NK2MFS.inp';
    OUTPUT = 'NK2MFS.out';
    MAX_N = 10000;

type
    recF = record
        a,b:longint;
        idx:longint;
    end;

var
    N,M1,M2,Time:longint;
    F1,F2:array[1..MAX_N] of recF;

procedure   Enter;
var
    fi:text;
    i:longint;
    A,B:array[1..MAX_N] of longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do read(fi,A[i]);
    for i:=1 to N do read(fi,B[i]);
    close(fi);
    M1:=0;  M2:=0;
    for i:=1 to N do
        if A[i] <= B[i] then
            begin
                inc(M1);
                F1[M1].a:=A[i];
                F1[M1].b:=B[i];
                F1[M1].idx:=i;
            end
        else
            begin
                inc(M2);
                F2[M2].a:=A[i];
                F2[M2].b:=B[i];
                F2[M2].idx:=i;
            end;
end;

procedure   SwapF(var x,y:recF);
var
    tmp:recF;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

procedure   Quick_sort_F1(l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=F1[(i+j) div 2].a;
    repeat
        while F1[i].a < p do inc(i);
        while F1[j].a > p do dec(j);
        if i <= j then
            begin
                SwapF(F1[i],F1[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort_F1(l,j);
    if i < r then Quick_sort_F1(i,r);
end;

procedure   Quick_sort_F2(l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=F2[(i+j) div 2].b;
    repeat
        while F2[i].b > p do inc(i);
        while F2[j].b < p do dec(j);
        if i <= j then
            begin
                SwapF(F2[i],F2[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort_F2(l,j);
    if i < r then Quick_sort_F2(i,r);
end;

procedure   Find;
var
    i,tA,tB:longint;
    F:array[1..MAX_N] of recF;
begin
    Quick_sort_F1(1,M1);
    Quick_sort_F2(1,M2);
    for i:=1 to M1 do F[i]:=F1[i];
    for i:=1 to M2 do F[i+M1]:=F2[i];
    Time:=F[1].a;
    tA:=0;  tB:=F[1].b;
    for i:=2 to N do
        begin
            tA:=tA+F[i].a;
            if tA < tB then
                tB:=tB+F[i].b
            else
                tB:=tA+F[i].b;
        end;
    Time:=Time+tB;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Time);
    for i:=1 to M1 do write(fo,F1[i].idx,' ');
    for i:=1 to M2 do write(fo,F2[i].idx,' ');
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.
