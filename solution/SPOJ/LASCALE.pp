const
    INPUT = 'LASCALE.inp';
    OUTPUT = 'LASCALE.out';
    MAX_M = 100000000;
    MAX_N = 17;

var
    M,N,cA,cB:longint;
    P,S,A,B:array[0..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,M);
    close(fi);
end;

procedure   Init(M:longint);
var
    i:longint;
begin
    p[0]:=1;
    for i:=1 to MAX_N do
        p[i]:=p[i-1]*3;
    N:=-1;
    while M > 0 do
        begin
            inc(N);
            S[N]:=M mod 3;
            M:=M div 3;
        end;
end;

procedure   Find;
var
    i,carry:longint;
begin
    carry:=0;
    for i:=0 to N do
        begin
            if carry > 0 then
                begin
                    if S[i] = 1 then A[i]:=1
                    else A[i]:=0;
                end
            else
                if S[i] = 2 then A[i]:=1
                else A[i]:=0;
            B[i]:=S[i]+A[i]+carry;
            if B[i] = 3 then
                begin
                    B[i]:=0;
                    carry:=1;
                end
            else
                carry:=0;
        end;
    if carry = 1 then
        begin
            inc(N);
            A[N]:=0;
            B[N]:=1;
        end;
    cA:=0;  cB:=0;
    for i:=0 to N do
        begin
            cA:=cA+A[i];
            cB:=cB+B[i];
        end;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,cA,' ');
    for i:=0 to N do
        if A[i] = 1 then
            write(fo,P[i],' ');
    writeln(fo);
    write(fo,cB,' ');
    for i:=0 to N do
        if B[i] = 1 then
            write(fo,P[i],' ');
    close(fo);
end;

begin
    Enter;
    Init(M);
    Find;
    Print_result;
end.