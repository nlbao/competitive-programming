const   MAX_N = 510;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
        end;

var fi,fo:text;
    nTest,n,nS,m:longint;
    x,y,p:array[0..MAX_N] of longint;
    e:array[0..MAX_M] of recEdge;

procedure   enter;
var i:longint;
begin
    readln(fi,nS,n);
    for i:=1 to n do read(fi,x[i],y[i]);
end;

procedure   init(d:double);
var i,j:longint;
begin
    d:=d*d;
    m:=0;
    for i:=1 to n do
        for j:=i+1 to n do
            if sqr(x[j]-x[i])+sqr(y[j]-y[i]) <= d then begin
                inc(m);
                with e[m] do begin
                    x:=i;
                    y:=j;
                end;
            end;
end;

function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

function    check(d:double):boolean;
var i,r1,r2,c:longint;
begin
    for i:=1 to n do p[i]:=-1;
    for i:=1 to m do with e[i] do begin
        r1:=get_root(x);
        r2:=get_root(y);
        if r1 <> r2 then begin
            p[r1]:=p[r1]+p[r2];
            p[r2]:=r1;
        end;
    end;
    c:=0;
    for i:=1 to n do
        if p[i] < 0 then inc(c);
    if c <= nS then exit(true);
    exit(false);
end;

procedure   solve;
var l,r,mid,res:double;
    i:longint;
begin
    l:=0;   r:=1000000000;
    for i:=1 to 50 do begin
        mid:=(l+r)/2;
        init(mid);
        if check(mid) = true then begin
            res:=mid;
            r:=mid;
        end
        else l:=mid;
    end;
    writeln(fo,res:0:2);
end;


begin
    assign(fi,'10369.in');  reset(fi);
    assign(fo,'10369.out'); rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.