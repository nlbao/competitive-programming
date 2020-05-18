const
    INPUT = 'SEQ.inp';
    OUTPUT = 'SEQ.out';
    MAX_N = 1000000000;
    MAX_K = 10;
    MODUN = 1000000000;

type
    arrMatrix = array[1..MAX_K,1..MAX_K] of int64;

var
    fi,fo:text;
    nTest,N,K:longint;
    a,c:array[0..MAX_K] of int64;
    matBase,x:arrMatrix;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,K);
    for i:=1 to K do read(fi,a[i]);
    for i:=1 to K do read(fi,c[i]);
    readln(fi,N);

    for i:=1 to K do begin
        a[i]:=a[i] mod MODUN;
        c[i]:=c[i] mod MODUN;
    end;
end;
{---------------------------------------------------------------------------}
function    matMultiply(x,y:arrMatrix):arrMatrix;
var
    tmp:arrMatrix;
    i,j,t:longint;
begin
    for i:=1 to K do
        for j:=1 to K do begin
            tmp[i,j]:=0;
            for t:=1 to K do
                tmp[i,j]:=(tmp[i,j]+(x[i,t]*y[t,j]) mod MODUN) mod MODUN;
        end;
    exit(tmp);
end;
{---------------------------------------------------------------------------}
function    matPower(i:longint):arrMatrix;
var
    tmp:arrMatrix;
begin
    if i = 1 then exit(matBase);
    tmp:=matPower(i shr 1);
    if i mod 2 = 0 then exit(matMultiply(tmp,tmp))
    else exit(matMultiply(matMultiply(tmp,tmp),matBase));
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    res:longint;
begin
    if N <= K then begin
        writeln(fo,a[N]);
        exit;
    end;

    for j:=1 to K do matBase[1,j]:=c[j];
    for i:=2 to K do begin
        for j:=1 to K do matBase[i,j]:=0;
        matBase[i,i-1]:=1;
    end;

    x:=matPower(N-K);
    res:=0;
    for i:=1 to K do
        res:=(res+(x[1,i]*a[K-i+1]) mod MODUN) mod MODUN;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    repeat
        enter;
        solve;
        dec(nTest);
    until nTest = 0;
    close(fo);
    close(fi);
end.