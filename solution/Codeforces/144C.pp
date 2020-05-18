const   MAX_N = 100010;
        MAX_M = MAX_N;

var fi,fo:text;
    s,p:ansiString;
    n,m,c0:longint;
    b,c:array['a'..'z'] of longint;

procedure   enter;
begin
    readln(fi,s);
    readln(fi,p);
    n:=length(s);
    m:=length(p);
end;

function    check:longint;
var ch:char;
    t:longint;
begin
    t:=0;
    for ch:='a' to 'z' do
        if c[ch] > b[ch] then exit(0)
        else t:=t+b[ch]-c[ch];
    if t > c0 then exit(0);
    exit(1);
end;

function    solve:longint;
var i,res:longint;
begin
    if m > n then exit(0);
    fillchar(b,sizeof(b),0);
    fillchar(c,sizeof(c),0);
    c0:=0;
    for i:=1 to m do begin
        inc(b[p[i]]);
        if s[i] = '?' then inc(c0)
        else inc(c[s[i]]);
    end;
    res:=check;

    for i:=m+1 to n do begin
        if s[i-m] = '?' then dec(c0)
        else dec(c[s[i-m]]);

        if s[i] = '?' then inc(c0)
        else inc(c[s[i]]);
        res:=res+check;
    end;
    exit(res);
end;

begin
    assign(fi,'144C.in');   reset(fi);
    assign(fo,'144C.out');  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.