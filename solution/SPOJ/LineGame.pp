const
    INPUT = 'LineGame.inp';
    OUTPUT = 'LineGame.out';
    MAX_N = 1000000;

var
    N:longint;
    A:array[1..MAX_N] of longint;
    F0,F1:int64;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        read(fi,A[i]);
    close(fi);
end;

function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   Find;
var
    i:longint;
    pre_F0,pre_F1:int64;
begin
    F0:=A[1];
    F1:=0;
    for i:=2 to N do
        begin
            pre_F0:=F0;
            pre_F1:=F1;
            F0:=max(pre_F1+A[i],pre_F0);
            F1:=max(pre_F0-A[i],pre_F1);
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,max(F0,F1));
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.