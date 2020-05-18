const
    INPUT = 'NKABD.inp';
    OUTPUT = 'NKABD.out';
    MAX_R = 100000;

var
    L,R,C:longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,L,R);
    close(fi);
end;

procedure   Count;
var
    i,j:longint;
    F:array[1..MAX_R] of longint;
begin
    C:=0;
    for i:=1 to R do
        F[i]:=0;
    for i:=1 to (R div 2) do
        for j:=2 to (R div i) do
            inc(F[i*j],i);
    for i:=L to R do
        if F[i] > i then
            inc(C);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,C);
    close(fo);
end;

begin
    Enter;
    Count;
    Print_result;
end.
