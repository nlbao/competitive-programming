const
    INPUT = 'MaKhoa2.inp';
    OUTPUT = 'MaKhoa2.out';
    MAX_M = 31;
    MAX_N = 31;

type
    arrW = array[0..MAX_M,0..MAX_N] of longint;

var
    fi,fo:text;
    N,M:longint;
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
    if found = true then exit;
    if i > M then begin
        if checkW = true then begin
            print_result;
            found:=true;
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
