const   MAX_DIGIT = 8;
        BASE = 100000000;
        MAX_LENGTH = 250;

type    myStr = ansiString;
        int = int64;
        bigNum = array[0..MAX_LENGTH] of int;

var fi,fo:text;
    a,b:bigNum;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

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

function    cmp(a,b:bigNum):longint;
var i:longint;
begin
    if a[0] < b[0] then exit(-1);
    if a[0] > b[0] then exit(1);
    for i:=a[0] downto 1 do
        if a[i] < b[i] then exit(-1)
        else if a[i] > b[i] then exit(1);
    exit(0);
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

function    tru(a,b:bigNum):bigNum;
var i:longint;
    nho:int;
    c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=max(a[0],b[0]);
    nho:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]-b[i]-nho;
        nho:=0;
        while c[i] < 0 do begin
            c[i]:=c[i]+BASE;
            inc(nho);
        end;
        c[i]:=c[i] mod BASE;
    end;
    while (c[0] > 1) and (c[c[0]] = 0) do dec(c[0]);
    exit(c);
end;

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
    while nho > 0 do begin
        inc(c[0]);  c[c[0]]:=nho mod BASE;
        nho:=nho div BASE;
    end;
    while (c[0] > 1) and (c[c[0]] = 0) do dec(c[0]);
    exit(c);
end;


procedure   enter;
var s:myStr;
begin
    readln(fi,s);   a:=toBigNum(s);
    readln(fi,s);   b:=toBigNum(s);
end;

procedure   solve;
var i:longint;
begin
    writeln(fo,toString(cong(a,b)));
    i:=cmp(a,b);
    if i = 0 then writeln(fo,0)
    else if i = -1 then writeln(fo,'-',toString(tru(b,a)))
    else writeln(fo,toString(tru(a,b)));
    writeln(fo,toString(nhan(a,b)));
end;


begin
    assign(fi,'BigNum.in');     reset(fi);
    assign(fo,'BigNum.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.