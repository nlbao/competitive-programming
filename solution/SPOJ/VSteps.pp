const
    INPUT = 'VSteps.inp';
    OUTPUT = 'VSteps.out';
    MAX_N = 100000;
    MX = 14062008;

var
    N,K:longint;
    R:array[1..MAX_N] of boolean;
    Res:int64;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,K);
    for i:=1 to N do R[i]:=true;
    for i:=1 to K do
        begin
            read(fi,j);
            R[j]:=false;
        end;
    close(fi);
end;

procedure   Find;
var
    i:longint;
    F0,F1,tmp:int64;
begin
    F0:=0;
    F1:=1;
    for i:=2 to N do
        begin
            tmp:=F1;
            if R[i] = false then F1:=0
            else F1:=(F1+F0) mod MX;
            F0:=tmp;
        end;
    Res:=F1;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.