const
    INPUT = 'MaKhoa2.inp';
    OUTPUT = 'MaKhoa2.out';
    MAX_M = 31;
    MAX_N = 31;

type
    arrW = array[0..MAX_M,0..MAX_N] of longint;

var
    fi,fo:text;
    N,M,max_time,count:longint;
    A,B,W,sumA,sumB:arrW;
    nA,crrRow:array[0..MAX_M] of longint;
    nB,crrColumn:array[0..MAX_N] of longint;
    found:boolean;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    for i:=1 to M do begin
        read(fi,nA[i]);
        for j:=1 to nA[i] do read(fi,A[i,j]);
        A[i,0]:=-1;
    end;
    for i:=1 to N do begin
        read(fi,nB[i]);
        for j:=1 to nB[i] do read(fi,B[i,j]);
        B[i,0]:=-1;
    end;
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
    for k:=1 to nB[j] do begin
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
        for k:=1 to nA[i] do begin
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
    for k:=1 to nA[j] do begin
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
        for k:=1 to nB[i] do begin
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
procedure   solve2;
var
    i,j:longint;
begin
    for i:=0 to M+1 do
        for j:=0 to N+1 do
            W[i,j]:=0;
    if M >= N then solveM
    else solveN;
    print_result;
end;
{---------------------------------------------------------------------------}
function    checkW:boolean;
var
    i:longint;
begin
    for i:=1 to M do
        if (crrRow[i] < nA[i]) or (A[i,nA[i]] > 0) then exit(false);
    for i:=1 to N do
        if (crrColumn[i] < nB[i]) or (B[i,nB[i]] > 0) then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   tryW(i,j:longint);
begin

    if (found = true) or (count > max_time) then exit;
    if i > M then begin
        inc(count);
        if checkW = true then begin
            found:=true;
            print_result;
        end;
        exit;
    end;
    if j > N then begin
        tryW(i+1,1);
        exit;
    end;
{W[i,j]:=0}
    if (A[i,crrRow[i]] <= 0) and (B[j,crrColumn[j]] <= 0) then
        if (sumA[i,j+1]+nA[i]-crrRow[i] <= N-j) and (sumB[j,i+1]+nB[j]-crrColumn[j] <= M-i) then begin
            W[i,j]:=0;
            dec(A[i,crrRow[i]]);     dec(B[j,crrColumn[j]]);
            tryW(i,j+1);
            inc(A[i,crrRow[i]]);   inc(B[j,crrColumn[j]]);
        end;
{W[i,j]:=1}
    if A[i,crrRow[i]] > 0 then begin
        if B[j,crrColumn[j]] > 0 then begin
            W[i,j]:=1;
            dec(A[i,crrRow[i]]);  dec(B[j,crrColumn[j]]);
            tryW(i,j+1);
            inc(A[i,crrRow[i]]);  inc(B[j,crrColumn[j]]);
        end
        else if (B[j,crrColumn[j]] < 0) and (crrColumn[j] < nB[j]) then begin
            W[i,j]:=1;
            dec(A[i,crrRow[i]]);      inc(crrColumn[j]);  dec(B[j,crrColumn[j]]);
            tryW(i,j+1);
            inc(B[j,crrColumn[j]]);   dec(crrColumn[j]);  inc(A[i,crrRow[i]]);
        end;
    end
    else if (A[i,crrRow[i]] < 0) and (crrRow[i] < nA[i]) then begin
        if B[j,crrColumn[j]] > 0 then begin
            W[i,j]:=1;
            inc(crrRow[i]);         dec(A[i,crrRow[i]]);  dec(B[j,crrColumn[j]]);
            tryW(i,j+1);
            inc(B[j,crrColumn[j]]);   inc(A[i,crrRow[i]]);  dec(crrRow[i]);
        end
        else if (B[j,crrColumn[j]] < 0) and (crrColumn[j] < nB[j]) then begin
            W[i,j]:=1;
            inc(crrRow[i]);         dec(A[i,crrRow[i]]);
            inc(crrColumn[j]);      dec(B[j,crrColumn[j]]);
            tryW(i,j+1);
            inc(B[j,crrColumn[j]]);   dec(crrColumn[j]);
            inc(A[i,crrRow[i]]);      dec(crrRow[i]);
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
begin
    found:=false;
    i:=M*N;
    if i > 625 then max_time:=200
    else if i > 400 then max_time:=200
         else   if i > 100 then max_time:=10000
                else max_time:=100000;
    count:=0;
    for i:=1 to M do begin
        crrRow[i]:=0;
        sumA[i,nA[i]+1]:=0;
        for j:=nA[i] downto 1 do
            sumA[i,j]:=sumA[i,j+1]+A[i,j];
    end;
    for i:=1 to N do begin
        crrColumn[i]:=0;
        sumB[i,nB[i]+1]:=0;
        for j:=nB[i] downto 1 do
            sumB[i,j]:=sumB[i,j+1]+B[i,j];
    end;
    tryW(1,1);
    if not found then solve2;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.