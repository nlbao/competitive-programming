const
    INPUT = 'MaKhoa2.inp';
    OUTPUT = 'MaKhoa2.out';
    MAX_M = 31;
    MAX_N = 31;

type
    arrA = array[0..MAX_M,0..MAX_N] of longint;

var
    fi,fo:text;
    N,M:longint;
    A,B,W:arrA;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    for i:=1 to M do begin
        read(fi,A[i,0]);
        for j:=1 to A[i,0] do read(fi,A[i,j]);
    end;
    for i:=1 to N do begin
        read(fi,B[i,0]);
        for j:=1 to B[i,0] do read(fi,B[i,j]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    for i:=0 to M+1 do
        for j:=0 to N+1 do
            W[i,j]:=0;
end;
{---------------------------------------------------------------------------}
procedure   push_row(i,pos:longint);
var
    j:longint;
begin
    if (W[i,N] = 1) or (W[i,pos-1] = 1) then exit;
    for j:=N downto pos+1 do
        W[i,j]:=W[i,j-1];
    W[i,pos]:=0;
end;
{---------------------------------------------------------------------------}
procedure   fixColumn(j:longint);
var
    i,t,k:longint;
begin
    i:=0;
    for k:=1 to B[j,0] do begin
        for t:=1 to B[j,k] do inc(i);
        inc(i);
        if W[i,j] = 1 then push_row(i,j);
    end;
    while i < M do begin
        inc(i);
        if W[i,j] = 1 then push_row(i,j);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solveM;
var
    i,j,k,t:longint;
begin
    for i:=1 to M do begin
        j:=0;
        for k:=1 to A[i,0] do begin
            for t:=1 to A[i,k] do begin
                inc(j);
                W[i,j]:=1;
            end;
            inc(j);
        end;
    end;
    for i:=1 to N do
        fixColumn(i);
end;
{---------------------------------------------------------------------------}
procedure   push_column(i,pos:longint);
var
    j:longint;
begin
    if (W[M,i] = 1) or (W[pos-1,i] = 1) then exit;
    for j:=M downto pos+1 do
        W[j,i]:=W[j-1,i];
    W[pos,i]:=0;
end;
{---------------------------------------------------------------------------}
procedure   fixRow(j:longint);
var
    i,t,k:longint;
begin
    i:=0;
    for k:=1 to A[j,0] do begin
        for t:=1 to A[j,k] do inc(i);
        inc(i);
        if W[j,i] = 1 then push_column(i,j);
    end;
    while i < N do begin
        inc(i);
        if W[j,i] = 1 then push_column(i,j);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solveN;
var
    i,j,k,t:longint;
begin
    for i:=1 to N do begin
        j:=0;
        for k:=1 to B[i,0] do begin
            for t:=1 to B[i,k] do begin
                inc(j);
                W[j,i]:=1;
            end;
            inc(j);
        end;
    end;
    for i:=1 to M do
        fixRow(i);
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,j:longint;
begin
    for i:=1 to M do begin
        for j:=1 to N do write(fo,W[i,j]);
        writeln(fo);
    end
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    if M >= N then solveM
    else solveN;
    print_result;
    close(fo);
    close(fi);
end.