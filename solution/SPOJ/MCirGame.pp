const
    INPUT = 'MCirGame.inp';
    OUTPUT = 'MCirGame.out';
    MAX_N = 310;
    MAX_DIGIT = 3;
    BASE = 1000;
    MAX_LENGTH = 1000;

type
    bigNum = array[0..MAX_LENGTH] of longint;

var
    fi,fo:text;
    N:longint;
    f:array[0..MAX_N] of bigNum;

{---------------------------------------------------------------------------}
procedure   to_BigNum(S:ansiString;   var X:bigNum);
var
    i,j:longint;
begin
    fillchar(X,sizeof(X),0);
    i:=length(S);
    repeat
        j:=i;
        while (j > 1) and (i-j+1 < MAX_DIGIT) do dec(j);
        inc(X[0]);
        val(copy(S,j,i-j+1),X[X[0]]);
        i:=j-1;
    until i < 1;
    while (X[0] > 0) and (X[X[0]] = 0) do dec(X[0]);
end;
{---------------------------------------------------------------------------}
function    cong(a,b:bigNum):bigNum;
var
    i,nho:longint;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    if b[0] > c[0] then c[0]:=b[0];
    nho:=0;
    for i:=1 to c[0] do
        begin
            c[i]:=a[i]+b[i]+nho;
            nho:=c[i] div BASE;
            c[i]:=c[i] mod BASE;
        end;
    if nho > 0 then
        begin
            inc(c[0]);
            c[c[0]]:=nho;
        end;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    nhan(a,b:bigNum):bigNum;
var
    i,j,k,nho:longint;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0]+b[0]-1;
    for i:=1 to a[0] do
        for j:=1 to b[0] do
            begin
                k:=i+j-1;
                c[k]:=c[k]+a[i]*b[j];
            end;
    nho:=0;
    for i:=1 to c[0] do
        begin
            c[i]:=c[i]+nho;
            nho:=c[i] div BASE;
            c[i]:=c[i] mod BASE;
        end;
    if nho > 0 then
        begin
            inc(c[0]);
            c[c[0]]:=nho;
        end;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    to_string(a:bigNum):ansiString;
var
    i:longint;
    s,s1:ansiString;
begin
    s:='';
    for i:=1 to a[0] do
        begin
            str(a[i],s1);
            while length(s1) < MAX_DIGIT do s1:='0'+s1;
            s:=s1+s;
        end;
    while (length(s) > 0) and (s[1] = '0') do delete(s,1,1);
    if length(s) = 0 then s:='0';
    exit(s);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    to_bigNum('1',f[0]);
    i:=0;
    repeat
        inc(i,2);
        to_bigNum('0',f[i]);
        j:=0;
        repeat
            f[i]:=cong(f[i],nhan(f[j],f[i-j-2]));
            inc(j,2);
        until j = i;
    until i = MAX_N;
end;
{---------------------------------------------------------------------------}
procedure   solve;
begin
    repeat
        readln(fi,N);
        if N = -1 then break;
        writeln(fo,to_string(f[2*N]));
    until N = -1;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    solve;
    close(fo);
    close(fi);
end.