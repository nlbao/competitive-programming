{$R+,Q+}

const   MAX_N = 4010;
        MAX_DIGIT = 9;
        BASE = 1000000000;
        MAX_LENGTH = 6;

type    myStr = ansiString;
        int = int64;
        bigNum = array[0..MAX_LENGTH] of int;

var fi,fo:text;
    n,i,j,t,pt:longint;
    f:array[0..1,0..MAX_N] of bigNum;
    res:bigNum;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

function    toBigNum(s:myStr):bigNum;
var i,j:longint;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    i:=length(s);
    repeat
        j:=i-MAX_DIGIT+1;
        if j < 1 then j:=1;
        inc(c[0]);
        val(copy(s,j,i-j+1),c[c[0]]);
        i:=j-1;
    until i < 1;
    while (c[0] > 1) and (c[c[0]] = 0) do dec(c[0]);
    exit(c);
end;

function    toString(a:bigNum):myStr;
var i:longint;
    s,t:myStr;
begin
    s:='';
    for i:=1 to a[0] do begin
        str(a[i],t);
        while length(t) < MAX_DIGIT do t:='0'+t;
        s:=t+s;
    end;
    if length(s) = 0 then s:='0';
    while (length(s) > 0) and (s[1] = '0') do delete(s,1,1);
    exit(s);
end;

function    cong(a,b:bigNum):bigNum;
var i:longint;
    nho:int;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=max(a[0],b[0]);
    nho:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]+b[i]+nho;
        nho:=c[i] div BASE;
        c[i]:=c[i] mod BASE;
    end;
    while nho > 0 do begin
        inc(c[0]);  c[c[0]]:=nho mod BASE;
        nho:=nho div BASE;
    end;
    while (c[0] > 1) and (c[c[0]] = 0) do dec(c[0]);
    exit(c);
end;

begin
    assign(fi,'PBCDem.in');     reset(fi);
    assign(fo,'PBCDem.out');    rewrite(fo);
    readln(fi,n);
    {f[1][1]:=toBigNum('1');
    for j:=2 to n do
        f[1][j]:=toBigNum('0');
    for i:=2 to n do begin
        f[i][1]:=toBigNum('0');
        for j:=2 to i-1 do
            f[i][j]:=cong(f[i-1][j-1],f[i-j][j-1]);
        f[i][i]:=toBigNum('1');
        for j:=i+1 to n do
            f[i][j]:=toBigNum('0');
    end;
    res:=toBigNum('0');
    for j:=2 to n-1 do res:=cong(res,f[n][j]);}

    res:=toBigNum('0');
    f[0][1]:=toBigNum('1');
    for j:=2 to n do f[0][j]:=toBigNum('0');
    for i:=2 to n-1 do begin
        pt:=t;
        t:=(t+1) mod 2;
        for j:=0 to i-1 do f[t][j]:=toBigNum('0');
        f[t][i]:=toBigNum('1');
        for j:=i+1 to n do
            f[t][j]:=cong(f[pt][j-1],f[pt][j-i]);
        res:=cong(res,f[t][n]);
    end;
    writeln(fo,toString(res));
    close(fo);
    close(fi);
end.
