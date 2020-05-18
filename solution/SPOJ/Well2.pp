const
    INPUT = 'Well.inp';
    OUTPUT = 'Well.out';
    MAX_N1 = 20;
    MAX_M1 = 10000;
    MAX_N2 = 8;
    MAX_M2 = 64;
    MAX_P2 = MAX_N1*MAX_M1;
    MAX_DIGIT = 8;
    BASE = 100000000;
    MAX_LENGTH = 10000;

type
    bigNum = array[0..MAX_LENGTH] of longint;
    bigNum2 = ansiString;

var
    fi,fo:text;
    nTest,i,types,M,N:longint;
    p2M,p2MN:bigNum;
    F:array[0..MAX_M2,0..MAX_P2] of int64;

{---------------------------------------------------------------------------}
procedure   toBigNum(S:ansiString;   var X:bigNum);
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
function    tru(a,b:bigNum):bigNum;
var
    i,nho:longint;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    nho:=0;
    for i:=1 to c[0] do
        begin
            c[i]:=a[i]-b[i]-nho;
            if c[i] < 0 then
                begin
                    c[i]:=c[i]+BASE;
                    nho:=1
                end
            else nho:=0;
            c[i]:=c[i] mod BASE;
        end;
    while (c[0] > 0) and (c[c[0]] = 0) do dec(c[0]);
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
function    toString(a:bigNum):ansiString;
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
function    chia(a:bigNum2;  b:longint):bigNum2;
var
    s,i,hold:longint;
    c:bigNum2;
begin
    hold:=0;    s:=0;   c:='';
    for i:=1 to length(a) do begin
        hold:=hold*10+ord(a[i])-48;
        s:=hold div b;
        hold:=hold mod b;
        c:=c+chr(s+48);
    end;
    while (length(c) > 1) and (c[1] = '0') do delete(c,1,1);
    exit(c);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
    tmp1,tmp2:bigNum;
begin
    toBigNum('1',tmp1);
    toBigNum('2',tmp2);
    for i:=1 to M do
        tmp1:=nhan(tmp1,tmp2);
    p2M:=tmp1;
    for i:=M+1 to M*N do
        tmp1:=nhan(tmp1,tmp2);
    p2MN:=tmp1;
end;
{---------------------------------------------------------------------------}
procedure   solve1;
var
    tmp:bigNum;
    s:bigNum2;
begin
    tmp:=tru(p2MN,p2M);
    s:=toString(tmp);
    s:=chia(s,N);
    toBigNum(s,tmp);
    tmp:=cong(tmp,p2M);
    writeln(fo,toString(tmp));
    {writeln(fo,cong(chia(tru(p2[M*N],p2[M]),N),p2[M]));}
end;
{---------------------------------------------------------------------------}
function    get_bit(x,i:longint):longint;   inline;
begin
    exit((x shr (i-1)) and 1);
end;
{---------------------------------------------------------------------------}
function    check(x,y:longint):boolean;
var
    i:longint;
begin
    for i:=1 to N-1 do
        if (get_bit(x,i) = get_bit(y,i)) and (get_bit(x,i+1) = get_bit(y,i+1)) and (get_bit(x,i) = get_bit(x,i+1)) then
            exit(false);
    if (get_bit(x,N) = get_bit(y,N)) and (get_bit(x,1) = get_bit(y,1)) and (get_bit(x,N) = get_bit(x,1)) then
        exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   solve2;
var
    i,j,k,R:longint;
    s1,s2:int64;
begin
    if N = 1 then begin
        writeln(fo,toString(p2M));
        exit;
    end;
    R:=1;
    for i:=1 to N do R:=R*2;
    dec(R);
    for j:=0 to R do F[1,j]:=1;
    for i:=2 to M do
        for j:=0 to R do begin
            F[i,j]:=0;
            for k:=0 to R do
                if check(j,k) = true then
                    F[i,j]:=F[i,j]+F[i-1,k];
        end;
    s1:=0;
    for j:=0 to R do
        s1:=s1+F[M,j];
    s2:=0;
    for j:=0 to R do
        if check(j,j) = true then
            s2:=s2+1;
    writeln(fo,(s1-s2) div N + s2);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        readln(fi,types,M,N);
        init;
        if types = 1 then solve1
        else solve2;
    end;
    close(fo);
    close(fi);
end.