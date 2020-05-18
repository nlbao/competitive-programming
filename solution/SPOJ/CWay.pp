const
    INPUT = 'CWay.inp';
    OUTPUT = 'CWay.out';
    MAX_N = 2001;
    MAX_DIGIT = 6;
    BASE = 1000000;
    MAX_LENGTH = 1000;

type
    int = longint;
    bigNum = array[0..MAX_LENGTH] of int;

var
    fi,fo:text;
    N:longint;

{---------------------------------------------------------------------------}
function    to_bigNum(k:longint):bigNum;
var
    i,j:longint;
    s:ansiString;
    x:bigNum;
begin
    str(k,s);
    fillchar(x,sizeof(x),0);
    i:=length(s);
    repeat
        j:=i;
        while (j > 1) and (i-j+1 < MAX_DIGIT) do dec(j);
        inc(x[0]);
        val(copy(s,j,i-j+1),x[x[0]]);
        i:=j-1;
    until i < 1;
    while (x[0] > 0) and (x[x[0]] = 0) do dec(x[0]);
    exit(x);
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
function    nhan(a,b:bigNum):bigNum;
var
    i,j,k:longint;
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
function    to_string(a:bigNum):ansiString;
var
    i:longint;
    s,s1:ansiString;
begin
    s:='';
    for i:=1 to a[0] do begin
        str(a[i],s1);
        while length(s1) < MAX_DIGIT do s1:='0'+s1;
        s:=s1+s;
    end;
    while (length(s) > 1) and (s[1] = '0') do delete(s,1,1);
    if length(s) = 0 then s:='0';
    exit(s);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
    f,tmp:bigNum;
begin
    tmp:=to_bigNum(1);
    f:=tmp;
    for i:=3 to N do
        f:=cong(tmp,nhan(to_bigNum(i-2),f));
    writeln(fo,to_string(f));
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    solve;
    close(fo);
    close(fi);
end.