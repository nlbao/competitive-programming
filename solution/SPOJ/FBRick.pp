const   INPUT = 'FBRick.in';
        OUTPUT = 'FBRick.out';
        MAX_A = 1000000000;
        MAX_N = 1000000000;
        MAX_M = 1000000000;
        SIZE = 7;

type    arrMatrix = array[1..SIZE,1..SIZE] of int64;

var fi,fo:text;
    nTest,n,m:int64;
    a,s:array[1..4] of int64;
    matBase:arrMatrix;

{---------------------------------------------------------------------------}
function    modM(x:int64):int64;
begin
    while x < 0 do x:=x+m;
    exit(x mod m);
end;
{---------------------------------------------------------------------------}
function    matMultiply(x,y:arrMatrix):arrMatrix;
var i,j,k:longint;
    z:arrMatrix;
begin
    for i:=1 to SIZE do
        for j:=1 to SIZE do begin
            z[i,j]:=0;
            for k:=1 to SIZE do
                z[i,j]:=modM(z[i,j]+modM(x[i,k]*y[k,j]));
        end;
    exit(z);
end;
{---------------------------------------------------------------------------}
function    power(p:int64):arrMatrix;
var tmp:arrMatrix;
begin
    if p = 1 then exit(matBase);
    tmp:=power(p div 2);
    if p mod 2 = 0 then exit(matMultiply(tmp,tmp))
    else exit(matMultiply(matMultiply(tmp,tmp),matBase));
end;
{---------------------------------------------------------------------------}
function    solve:int64;
var i,j,c:longint;
    x:arrMatrix;
    b:array[1..SIZE] of int64;
    res:int64;
begin
    a[2]:=modM(a[2]);
    c:=modM(2*a[2]);
    s[1]:=1;    s[2]:=modM(s[1]+modM(a[2]*a[2]));
    for i:=3 to 4 do begin
        a[i]:=modM(modM(c*a[i-1])-a[i-2]);
        s[i]:=modM(s[i-1]+modM(a[i]*a[i]));
    end;

    if n < 5 then exit(s[N]);

    matBase[2,2]:=c;            matBase[2,6]:=c;
    matBase[4,4]:=modM(c*c);    matBase[4,7]:=matBase[4,4];
    matBase[6,4]:=modM(-2*c);   matBase[6,7]:=matBase[6,4];

    x:=power(n-4);

    b[1]:=a[3]; b[2]:=a[4];
    b[3]:=modM(a[3]*a[3]);  b[4]:=modM(a[4]*a[4]);
    b[5]:=modM(a[2]*a[3]);  b[6]:=modM(a[3]*a[4]);
    b[7]:=s[4];

    res:=0;
    for i:=1 to 7 do
        res:=modM(modM(x[i,7]*b[i])+res);
    exit(res);
end;
{---------------------------------------------------------------------------}
procedure   init;
var i,j:longint;
begin
    a[1]:=1;
    for i:=1 to SIZE do
        for j:=1 to SIZE do matBase[i,j]:=0;
    matBase[1,2]:=-1;
    matBase[2,1]:=1;
    matBase[3,4]:=1;    matBase[3,7]:=1;
    matBase[4,3]:=1;
    matBase[5,6]:=-1;
    matBase[6,5]:=1;
    matBase[7,7]:=1;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,a[2],n,m);
        writeln(fo,solve);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.