const
    INPUT = 'NKCable.inp';
    OUTPUT = 'NKCable.out';
    MAX_N = 25000;

var
    N:longint;
    A:array[1..MAX_N] of longint;
    F:array[1..MAX_N,0..1] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N-1 do read(fi,A[i]);
    close(fi);
end;

function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;

procedure   Find;
var
    i:longint;
begin
    F[1,0]:=0;  F[1,1]:=A[1];
    F[2,0]:=A[1];   F[2,1]:=A[1]+A[2];
    for i:=3 to N do
        begin
            F[i,0]:=min(F[i-1,1],F[i-1,0]+A[i-1]);
            F[i,1]:=min(F[i-1,0],F[i-1,1])+A[i];
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,F[N,0]);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.