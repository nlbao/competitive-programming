const
    INPUT = 'SHTH.inp';
    OUTPUT = 'SHTH.out';
    MAX_DIGIT = 9;
    BASE = 1000000000;
    MAX_LENGTH = 12;
    MAX_N = 301;

type
    int = longint;
    bigNum = array[0..MAX_LENGTH] of int;

var
    fi,fo:text;
    N,K,i:longint;
    S:ansiString;
    A:array[0..MAX_N] of longint;
    P:bigNum;
    C,sum:array[0..MAX_N,0..MAX_N] of bigNum;

{---------------------------------------------------------------------------}
function    toBigNum(N:int):bigNum;
var
    x:bigNum;
begin
    fillchar(x,sizeof(x),0);
    repeat
        inc(x[0]);
        x[x[0]]:=N mod BASE;
        N:=N div BASE;
    until N = 0;
    exit(x);
end;
{---------------------------------------------------------------------------}
function    SoSanh(a,b:bigNum):longint;
var
    i:longint;
begin
    if a[0] > b[0] then exit(1)
        else
            if a[0] < b[0] then exit(-1);
    for i:=a[0] downto 1 do
        if a[i] > b[i] then exit(1)
        else
            if a[i] < b[i] then exit(-1);
    exit(0);
end;
{---------------------------------------------------------------------------}
function    cong(a,b:bigNum):bigNum;
var
    i:longint;
    nho:int;
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
    i:longint;
    nho:int;
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
    i,j,k:longint;
    nho:int;
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
procedure   Init;
var
    i,j:longint;
begin
    fillchar(P,sizeof(P),0);
    i:=length(S);
    repeat
        j:=i;
        while (j > 1) and (i-j+1 < MAX_DIGIT) do dec(j);
        inc(P[0]);
        val(copy(S,j,i-j+1),P[P[0]]);
        i:=j-1;
    until i < 1;

    fillchar(c,sizeof(c),0);
    fillchar(sum,sizeof(sum),0);
    for i:=1 to N do
        begin
            C[i,1]:=toBigNum(1);
            sum[i,1]:=toBigNum(i);
        end;
    for j:=2 to K do
        for i:=1 to N do
            begin
               C[i,j]:=cong(C[i,j],sum[N,j-1]);
               C[i,j]:=tru(C[i,j],sum[i,j-1]);
               sum[i,j]:=cong(C[i,j],sum[i-1,j]);
            end;
end;
{---------------------------------------------------------------------------}
procedure   FindA;
var
    i,j:longint;
    tmp:bigNum;
begin
    A[0]:=0;
    for i:=1 to K do
        begin
            j:=A[i-1]+1;
            while SoSanh(P,C[j,k-i+1]) = 1 do
                begin
                    P:=tru(P,C[j,k-i+1]);
                    inc(j);
                end;
            A[i]:=j;
        end;
    for i:=1 to K do write(fo,A[i],' ');
    writeln(fo);
end;
{---------------------------------------------------------------------------}
procedure   FindP;
var
    i,j:longint;
begin
    P:=toBigNum(1);
    A[0]:=0;
    for i:=1 to K do
        for j:=A[i-1]+1 to A[i]-1 do
            P:=cong(P,C[j,k-i+1]);
    writeln(fo,toString(P));
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    readln(fi,S);
    Init;
    FindA;
    for i:=1 to K do read(fi,A[i]);
    FindP;
    close(fo);
    close(fi);
end.