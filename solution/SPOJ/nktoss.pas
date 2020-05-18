uses    math;

const   MAX_N = 10004;
        DIGIT = 9;
        BASE = 1000000000;
        MAX_LEN = 377;

type    ll = longint;
        bigNum = array[0..MAX_LEN] of ll;

var fi,fo:text;
    n,m,k:longint;
    f:array[0..1,0..1] of bigNum;
    s:array[0..MAX_N] of bigNum;
    tmp,res:bigNum;


function    toString(a:bigNum):ansiString;
var i:longint;
    s,t:ansiString;
begin
    s:='';
    for i:=1 to a[0] do begin
        str(a[i],t);
        while length(t) < DIGIT do t:='0'+t;
        s:=t+s;
    end;
    while (length(s) > 1) and (s[1] = '0') do delete(s,1,1);
    if length(s) = 0 then s:='0';
    exit(s);
end;


operator := (n:ll) c:bigNum;
begin
    fillchar(c,sizeof(c),0);
    while n > 0 do begin
        inc(c[0]);
        c[c[0]]:=n mod BASE;
        n:=n div BASE;
    end;
    if c[0] = 0 then inc(c[0]);
end;


operator + (var a,b:bigNum) c:bigNum;
var i:longint;
    r:ll;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=max(a[0],b[0]);
    r:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]+b[i]+r;
        r:=c[i] div BASE;
        c[i]:=c[i] mod BASE;
    end;
    while r > 0 do begin
        inc(c[0]);
        c[c[0]]:=r mod BASE;
        r:=r div BASE;
    end;
    while (c[0] > 1) and (c[c[0]] = 0) do dec(c[0]);
end;


operator - (var a,b:bigNum) c:bigNum;
var i:longint;
    r:ll;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    r:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]-b[i]-r;
        r:=0;
        while c[i] < 0 do begin
            c[i]:=c[i]+BASE;
            r:=r+1;
        end;
        c[i]:=c[i] mod BASE;
    end;
    while r > 0 do begin
        inc(c[0]);
        c[c[0]]:=r mod BASE;
        r:=r div BASE;
    end;
    while (c[0] > 1) and (c[c[0]] = 0) do dec(c[0]);
end;


procedure   solve();
var i,j,t,tt:longint;
begin
    res:=1;
    m:=k-1;
    t:=0;
    f[0][0]:=1;
    f[0][1]:=0;
    s[0]:=1;
    for i:=1 to n do begin
        res:=res + res;
        tt:=t;
        t:=1-t;
        f[t][0]:=f[tt][0] + f[tt][1];
        if i <= m then f[t][1]:=s[i-1]
        else f[t][1]:=s[i-1] - s[i-m-1];
        s[i]:=s[i-1] + f[t][0];
    end;

    tmp:=f[t][0]+f[t][1];
    res:=res - tmp;
    writeln(fo,toString(res));
end;



begin
{$IFDEF WINDOWS}
    assign(fi,'nktoss.in');    reset(fi);
    assign(fo,'nktoss.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');   rewrite(fo);
{$ENDIF}
    readln(fi,n,k);
    solve();
    close(fo);
    close(fi);
end.