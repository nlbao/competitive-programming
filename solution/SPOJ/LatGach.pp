const
    INPUT = 'LatGach.inp';
    OUTPUT = 'LatGach.out';
    MAX_N = 100;
    MAX_LENGTH = 100;

type
    int = longint;
    bigNum = array[0..MAX_LENGTH] of int;

var
    fi,fo:text;
    i,T,N:longint;
    F:array[0..MAX_N] of bigNum;

{---------------------------------------------------------------------------}
function    toBigNum(N:int):bigNum;
var
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    repeat
        inc(c[0]);
        c[c[0]]:=N mod 10;
        N:=N div 10;
    until N < 1;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    cong(a,b:bigNum):bigNum;
var
    i:longint;
    nho:int;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    if a[0] > b[0] then c[0]:=a[0]
    else c[0]:=b[0];
    nho:=0;
    for i:=1 to c[0] do
        begin
            c[i]:=a[i]+b[i]+nho;
            nho:=c[i] div 10;
            c[i]:=c[i] mod 10;
        end;
    if nho > 0 then
        begin
            inc(c[0]);
            c[c[0]]:=nho;
        end;
    exit(c);
end;
{---------------------------------------------------------------------------}
procedure   print(a:bigNum);
var
    i:longint;
begin
    for i:=a[0] downto 1 do write(fo,a[i]);
    writeln(fo);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    F[0]:=toBigNum(1);    F[1]:=toBigNum(1);
    for i:=2 to MAX_N do
        F[i]:=cong(F[i-1],F[i-2]);
    readln(fi,T);
    for i:=1 to T do
        begin
            readln(fi,N);
            print(F[N]);
        end;
    close(fo);
    close(fi);
    end.