const
    INPUT = 'LatGach4.inp';
    OUTPUT = 'LatGach4.out';
    MAX_N = 2000000001;
    MODUN = 111539786;

type
    arrMatrix = array[1..2,1..2] of int64;

var
    fi,fo:text;
    T,N:longint;
    a,b:arrMatrix;

{---------------------------------------------------------------------------}
function    matMultiply(x,y:arrMatrix):arrMatrix;
var
    tmp:arrMatrix;
    i,j,k:longint;
begin
    for i:=1 to 2 do
        for j:=1 to 2 do begin
            tmp[i,j]:=0;
            for k:=1 to 2 do
                tmp[i,j]:=(tmp[i,j]+(x[i,k]*y[k,j]) mod MODUN) mod MODUN;
        end;
    exit(tmp);
end;
{---------------------------------------------------------------------------}
function    matPower(i:longint):arrMatrix;
var
    tmp:arrMatrix;
begin
    if i = 1 then exit(b);
    tmp:=matPower(i shr 1);
    if i mod 2 = 0 then exit(matMultiply(tmp,tmp))
    else exit(matMultiply(matMultiply(tmp,tmp),b));
end;
{---------------------------------------------------------------------------}
procedure   solve;

begin
    if N < 3 then begin
        writeln(fo,N);
        exit;
    end;
    b[1][1]:=1; b[1][2]:=1;
    b[2][1]:=1; b[2][2]:=0;
    a:=matPower(N-2);
    writeln(fo,(a[1][1]*2+a[1][2]) mod MODUN);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    repeat
        readln(fi,N);
        solve;
        dec(T);
    until T = 0;
    close(fo);
    close(fi);
end.