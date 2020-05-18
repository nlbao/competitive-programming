const
    INPUT = 'NKSEQ.inp';
    OUTPUT = 'NKSEQ.out';
    MAX_N = 100000;

var
    N,C:longint;
    A:array[0..MAX_N+1] of longint;

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

function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;

procedure   Count;
var
    i,s:longint;
    F:array[0..MAX_N+1] of longint;
begin
    C:=0;
    s:=A[1];
    for i:=2 to N do s:=s+A[i];
    if s <= 0 then exit;
    F[N]:=A[N];
    s:=A[N];
    for i:=1 to N-1 do
        begin
            s:=s+A[i];
            F[N]:=min(F[N],s);
        end;
    if F[N] > 0 then inc(C);
    for i:=N-1 downto 1 do
        begin
            F[i]:=min(A[i],A[i]+F[i+1]);
            if F[i] > 0 then inc(C);
        end;
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
