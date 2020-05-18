const
    INPUT = 'NKTheme.inp';
    OUTPUT = 'NKTheme.out';
    MAX_N = 5000;
    MAX_A = 87;

var
    N,Res:longint;
    A:array[1..MAX_N] of longint;
    F:array[1..MAX_N,1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do
        read(fi,A[i]);
    close(fi);
    for i:=1 to N-1 do
        A[i]:=A[i]-A[i+1];
    dec(N);
end;

procedure   Find;
var
    i,j:longint;
begin
    for j:=1 to N do
        if A[1] = A[j] then F[1,j]:=1
        else F[1,j]:=0;
    Res:=0;
    for i:=2 to N-1 do
        for j:=i+1 to N do
            begin
                F[i,j]:=0;
                if A[i] = A[j] then
                    begin
                        F[i,j]:=F[i-1,j-1]+1;
                        if F[i,j] >= (j-i) then
                            F[i,j]:=j-i-1;
                    end;
                if F[i,j] > Res then Res:=F[i,j];
            end;
    inc(Res);
    if Res < 5 then Res:=0;
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