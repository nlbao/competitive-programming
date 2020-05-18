const
    INPUT = 'QBGame.inp';
    OUTPUT = 'QBGame.out';
    MAX_M = 8;
    MAX_N = 10000;
    MAX_T = 255;

type
    recT = record
        count:longint;
        pre:array[1..MAX_T+1] of byte;
    end;

var
    N:longint;
    S:int64;
    A:array[1..MAX_M,1..MAX_N] of longint;
    T:array[0..MAX_T] of recT;
    F:array[1..MAX_N,0..MAX_T] of int64;
    avail:array[0..MAX_T] of boolean;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to MAX_M do
        begin
            for j:=1 to N do
                read(fi,A[i,j]);
            readln(fi);
        end;
    close(fi);
end;

function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;

function    GetBit(x,k:byte):byte;
begin
    exit((x shr (k-1)) and 1);
end;

function    sum(i:longint;  x:byte):int64;
var
    j:longint;
begin
    sum:=0;
    for j:=1 to MAX_M do
        begin
            if GetBit(x,j) = 1 then
                sum:=sum+A[j,i];
        end;
end;

procedure   Init;
var
    i,j,k:longint;
    check:boolean;
begin
    for i:=0 to MAX_T do
        begin
            avail[i]:=true;
            for j:=1 to MAX_M-1 do
                if (GetBit(i,j) = 1) and (GetBit(i,j+1) = 1) then
                    begin
                        avail[i]:=false;
                        break;
                    end;
        end;
    for i:=0 to MAX_T do
        if avail[i] then
            begin
                T[i].count:=0;
                for j:=0 to MAX_T do
                    if avail[j] then
                        begin
                            check:=true;
                            for k:=1 to MAX_M do
                                if (GetBit(i,k) = 1) and (GetBit(j,k) = 1) then
                                    begin
                                        check:=false;
                                        break;
                                    end;
                            if check = true then
                                begin
                                    inc(T[i].count);
                                    T[i].pre[T[i].count]:=j;
                                end;
                        end;
            end;
end;

procedure   Find;
var
    i,j,k:longint;
    tmp:int64;
    check:boolean;
begin
    S:=-MAXLONGINT;
    check:=false;
    for i:=1 to MAX_M do
        for j:=1 to N do
            begin
                S:=max(S,A[i,j]);
                if A[i,j] > 0 then
                    begin
                        check:=true;
                        break;
                    end;
            end;
    if check = false then exit;

    for i:=0 to MAX_T do
        if avail[i] then
            F[1,i]:=sum(1,i);
    for i:=2 to N do
        for j:=0 to MAX_T do
            if avail[j] then
                begin
                    F[i,j]:=0;
                    tmp:=sum(i,j);
                    for k:=1 to T[j].count do
                        F[i,j]:=max(F[i,j],F[i-1,T[j].pre[k]]+tmp);
                end;
    S:=0;
    for i:=0 to MAX_T do
        if avail[i] then
            S:=max(S,F[N,i]);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,S);
    close(fo);
end;

begin
    Enter;
    Init;
    Find;
    Print_result;
end.
