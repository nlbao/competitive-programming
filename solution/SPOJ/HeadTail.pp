const   INPUT = 'HeadTail.in';
        OUTPUT = 'HeadTail.out';
        MAX_N = 60;
        MAX_S = 1010;
        MAX_DIGIT = 16;
        BASE = 10000000000000000;
        MAX_LENGTH = 100;

type    int = int64;
        myStr = ansiString;
        bigNum = array[0..MAX_LENGTH] of int;

var fi,fo:text;
    n,s:longint;
    f:array[0..MAX_N,0..MAX_S] of bigNum;

{---------------------------------------------------------------------------}
procedure   toBigNum(S:myStr;   var X:bigNum);
var i,j:longint;
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
var i:longint;
    nho:int;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    if b[0] > c[0] then c[0]:=b[0];
    nho:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]+b[i]+nho;
        nho:=c[i] div BASE;
        c[i]:=c[i] mod BASE;
    end;
    if nho > 0 then begin
        inc(c[0]);
        c[c[0]]:=nho;
    end;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    tru(a,b:bigNum):bigNum;
var i:longint;
    nho:int;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    nho:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]-b[i]-nho;
        if c[i] < 0 then begin
            c[i]:=c[i]+BASE;
            nho:=1;
        end
        else nho:=0;
        c[i]:=c[i] mod BASE;
    end;
    while (c[0] > 0) and (c[c[0]] = 0) do dec(c[0]);
    exit(c);
end;
{---------------------------------------------------------------------------}
function    nhan(a,b:bigNum):bigNum;
var i,j,k:longint;
    nho:int;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0]+b[0]-1;
    for i:=1 to a[0] do
        for j:=1 to b[0] do begin
            k:=i+j-1;
            c[k]:=c[k]+a[i]*b[j];
        end;
    nho:=0;
    for i:=1 to c[0] do begin
        c[i]:=c[i]+nho;
        nho:=c[i] div BASE;
        c[i]:=c[i] mod BASE;
    end;
    if nho > 0 then begin
        inc(c[0]);
        c[c[0]]:=nho;
    end;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    toString(a:bigNum):myStr;
var i:longint;
    s,s1:myStr;
begin
    s:='';
    for i:=1 to a[0] do begin
        str(a[i],s1);
        while length(s1) < MAX_DIGIT do s1:='0'+s1;
        s:=s1+s;
    end;
    while (length(s) > 0) and (s[1] = '0') do delete(s,1,1);
    if length(s) = 0 then s:='0';
    exit(s);
end;
{---------------------------------------------------------------------------}
function    solve1(n,s:longint):myStr;
var i,j,k,t:longint;
    p,res:bigNum;
    tmp:myStr;
begin
    if s = 2*n then exit('1');
    if s = 2*n+1 then exit('3');
    if s = 2*n+2 then exit('6');
    for j:=1 to s do begin
        toBigNum('2',f[0][j]);
        str(j-1,tmp);
        toBigNum(tmp,p);
        f[0][j]:=cong(f[0][j],p);
    end;
    for i:=1 to n do begin
        toBigNum('1',f[i][2*i]);
        for j:=2*i+1 to s do begin
            toBigNum('0',f[i][j]);
            t:=j-2*i;
            for k:=0 to i-1 do
                f[i][j]:=cong(f[i][j],f[k][t+2*k]);
        end
    end;
    toBigNum('0',res);
    for j:=2*n to s do
        res:=cong(res,f[n][j]);
    exit(toString(res));
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n,s);
    writeln(fo,1);
    writeln(fo,1,' ',solve1(n,s));
    close(fo);
    close(fi);
end.
