const
    INPUT = 'NKINV.inp';
    OUTPUT = 'NKINV.out';
    MAX_N = 60000;
    MAX_A = 60000;

var
    N,Res:longint;
    A:array[1..MAX_N] of longint;
    T:array[1..MAX_A] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;

procedure   UpdateT(X:longint);
begin
    if (X < 1) or (X > MAX_A) then exit;
    inc(T[X]);
    UpdateT(X + X and (-X));
end;

function    GetT(X:longint):longint;
begin
    if (X < 1) or (X > MAX_A) then exit(0);
    exit(T[X]+GetT(X - X and (-X)));
end;

procedure   Find;
var
    i:longint;
begin
    Res:=0;
    for i:=1 to N do T[i]:=0;
    for i:=1 to N do
        begin
            UpdateT(A[i]);
            Res:=Res+i-GetT(A[i]);
        end;
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