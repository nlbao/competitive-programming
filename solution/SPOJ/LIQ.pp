const
    INPUT = 'LIQ.inp';
    OUTPUT = 'LIQ.out';
    MAX_N = 1000;

var
    N,max:longint;
    A:array[1..MAX_N] of longint;

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

procedure   Find;
var
    F:array[1..MAX_N] of longint;
    i,j:longint;
begin
    F[1]:=1;
    for i:=2 to N Do
        begin
            F[i]:=1;
            for j:=i-1 downto 1 do
                if (A[i] > A[j]) and (F[j]+1 > F[i]) then
                    F[i]:=F[j]+1;
        end;
    max:=F[1];
    for i:=2 to N do
        if F[i] > max then
            max:=F[i];
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,max);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.