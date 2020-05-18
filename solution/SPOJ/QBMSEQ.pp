const
    INPUT = 'QBMSEQ.inp';
    OUTPUT = 'QBMSEQ.out';
    MAX_N = 10000;

var
    N,maxF:longint;
    A:array[0..MAX_N] of longint;

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

function    check(x:longint):boolean;
var
    y,i:longint;
begin
    if x = 0 then exit(false);
    y:=2*x;
    i:=trunc(sqrt(y));
    if i*(i+1) = y then exit(true)
    else exit(false);
end;

procedure   Find;
var
    i:longint;
    F:array[0..MAX_N] of longint;
begin
    A[0]:=MAXLONGINT;
    maxF:=0;
    for i:=1 to N do
        begin
            if check(A[i]) = false then F[i]:=0
            else
                if A[i] >= A[i-1] then F[i]:=F[i-1]+1
                else F[i]:=1;
            if F[i] > maxF then maxF:=F[i];
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,maxF);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.