const   MAX_N = 1000010;
        MAX_M = 400010;
        MAX_DIGIT = 8;
        BASE = 100000000;
        MAX_LENGTH = 250;

type    myStr = ansiString;
        int = int64;
        bigNum = array[0..MAX_LENGTH] of int;
        pList = ^recList;
        recList = record
            id:longint;
            link:pList;
        end;

var fi,fo:text;
    n,m:longint;
    c:array[0..MAX_M] of int;
    a,b:array[0..MAX_N] of pList;


function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

function    toBigNum(x:int):bigNum;
var i,j:longint;
    s:myStr;
    c:bigNum;
begin
    str(x,s);
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

function    div2(a:myStr):myStr;
var i,nho,x:longint;
    b:myStr;
begin
    nho:=0;
    for i:=1 to length(a) do begin
        x:=10*nho+ord(a[i])-ord('0');
        nho:=x mod 2;
        b:=b+chr(x div 2+ord('0'));
    end;
    while (length(b) > 1) and (b[1] = '0') do delete(b,1,1);
    exit(b);
end;

procedure   add(var p:pList;    i:longint);
var q:pList;
begin
    new(q);
    q^.id:=i;   q^.link:=p;
    p:=q;
end;

procedure   enter;
var i,x,y:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do a[i]:=nil;
    for i:=1 to m do begin
        readln(fi,x,y,c[i]);
        add(a[x],i);
        add(b[y],i);
    end;
end;

procedure   solve;
var i,j:longint;
    p:pList;
    res,s,s2,t,t2:bigNum;
begin
    res:=toBigNum(0);
    s:=toBigNum(0);     s2:=toBigNum(0);
    j:=0;
    for i:=1 to n do begin
        p:=a[i];
        while p <> nil do begin
            t:=toBigNum(c[p^.id]);
            t2:=toBigNUm(sqr(c[p^.id]));
            s:=cong(s,t);
            s2:=cong(s2,t2);
            inc(j);
            p:=p^.link;
        end;
        if j > 1 then res:=cong(res,tru(nhan(s,s),s2));
        p:=b[i];
        while p <> nil do begin
            t:=toBigNum(c[p^.id]);
            t2:=toBigNUm(sqr(c[p^.id]));
            s:=tru(s,t);
            s2:=tru(s2,t2);
            dec(j);
            p:=p^.link;
        end;
    end;
    writeln(fo,div2(toString(res)));
end;

begin
    assign(fi,'TConcert.in');   reset(fi);
    assign(fo,'TConcert.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
