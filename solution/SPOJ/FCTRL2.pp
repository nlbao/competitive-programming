const   MAX_N = 100;
        MAX_DIGIT = 7;
        BASE = 10000000;
        MAX_LENGTH = 25;

type
    bigNum = array[0..MAX_LENGTH] of longint;

var
    fi,fo:text;
    nTest,n:longint;


procedure   toBigNum(S:ansiString;   var X:bigNum);
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

function    nhan(a,b:bigNum):bigNum;
var i,j,k,nho:longint;
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

function    toString(a:bigNum):ansiString;
var i:longint;
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

procedure   solve(n:longint);
var i:longint;
    s:ansiString;
    f,x:bigNum;
begin
    toBigNum('1',f);
    for i:=1 to n do begin
        str(i,s);
        toBigNum(s,x);
        f:=nhan(f,x);
    end;
    writeln(toString(f));
end;

begin
    readln(nTest);
    while nTest > 0 do begin
        readln(n);
        solve(n);
        dec(nTest);
    end;
end.