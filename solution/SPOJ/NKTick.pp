const
    INPUT = 'NKTick.inp';
    OUTPUT = 'NKTick.out';
    MAX_N = 60000;

var
    N,minT:longint;
    T,R:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        read(fi,T[i]);
    readln(fi);
    for i:=1 to N-1 do
        read(fi,R[i]);
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
    F:array[1..MAX_N,0..1] of longint;
begin
    F[1,0]:=MAXLONGINT;
    F[1,1]:=T[1];
    for i:=2 to N do
        begin
            F[i,0]:=F[i-1,1]-T[i-1]+R[i-1];
            F[i,1]:=min(F[i-1,0],F[i-1,1])+T[i];
        end;
    minT:=min(F[N,0],F[N,1]);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,minT);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.