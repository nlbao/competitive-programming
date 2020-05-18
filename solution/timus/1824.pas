{$M+ 16777216}
uses    math;

const   MAX_N = 32;
        BASE = (1 shl 14)-1;
        R = 10007;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,m,res:longint;
    a,g:array[0..MAX_N] of ll;
    ok:array[0..BASE] of boolean;
    h:array[0..BASE] of ll;
    value:array[0..BASE] of longint;
    b,choose:array[0..MAX_N] of boolean;


procedure   enter();
var i,j,r:longint;
    d:ll;
    x,y:array[0..MAX_N] of longint;
begin
    read(fi,n,r);
    r:=r*r;
    for i:=1 to n do read(fi,x[i],y[i]);
    d:=1;
    for i:=1 to n do begin
        a[i]:=0;
        for j:=1 to n do
            if sqr(x[i]-x[j])+sqr(y[i]-y[j]) <= r then
                a[i]:=a[i] or (d shl (j-1));
    end;
end;


function    find(x:ll):longint;
var i:longint;
begin
    i:=x and BASE;
    while (ok[i]) and (h[i] <> x) do i:=(i+R) and BASE;
    if not ok[i] then begin
        h[i]:=x;
        ok[i]:=true;
        value[i]:=oo;
    end;
    exit(i);
end;


procedure   tryf(pos,c:longint; f:ll);
var i,j:longint;
    ff:ll;
begin
    b[pos]:=true;
    if c >= res then exit;
    if f = g[1] then begin
        res:=c;
        for i:=1 to n do choose[i]:=b[i];
        exit;
    end;
    for i:=pos+1 to n do
        if (f or g[i]) < g[1] then break
        else begin
            ff:=f or a[i];
            if ff <> f then begin
                j:=find(ff);
                if c < value[j] then begin
                    value[j]:=c;
                    tryf(i,c+1,ff);
                    b[i]:=false;
                end;
            end;
        end;
end;

procedure   swap(var x,y:ll);
var t:ll;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   solve();
var i,j:longint;
    id:array[0..MAX_N] of ll;
begin
    for i:=1 to n do id[i]:=i;
    for i:=1 to n do
        for j:=i+1 to n do
            if a[j] > a[i] then begin
                swap(a[j],a[i]);
                swap(id[j],id[i]);
            end;
    for i:=0 to BASE do ok[i]:=false;

    res:=n;
    g[n+1]:=0;
    for i:=n downto 1 do begin
        g[i]:=g[i+1] or a[i];
        b[i]:=false;
        choose[i]:=true;
    end;
    for i:=1 to n do begin
        tryf(i,1,a[i]);
        b[i]:=false;
    end;

    writeln(fo,res);
    for i:=1 to n do
        if choose[i] then write(fo,id[i],' ');
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'1824.in');    reset(fi);
    assign(fo,'1824.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.