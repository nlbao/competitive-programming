{$M+ 16777216}
uses    math;

const   MAX_N = 37;
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


procedure   enter();
var i,u,v:longint;
    d:ll;
begin
    read(fi,n,m);
    fillchar(a,sizeof(a),0);
    d:=1;
    for i:=1 to m do begin
        read(fi,u,v);
        a[u]:=a[u] or (d shl (v-1));
        a[v]:=a[v] or (d shl (u-1));
    end;
    for i:=1 to n do a[i]:=a[i] or (d shl (i-1));
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
    if c >= res then exit;
    if f = g[1] then begin
        res:=c;
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
                end;
            end;
        end;
end;


procedure   solve();
var i,j:longint;
    t:ll;
begin
    for i:=1 to n do
        for j:=i+1 to n do
            if a[j] > a[i] then begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
            end;
    for i:=0 to BASE do ok[i]:=false;

    res:=n;
    g[n+1]:=0;
    for i:=n downto 1 do g[i]:=g[i+1] or a[i];
    for i:=1 to n do tryf(i,1,a[i]);
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKBAS.in');    reset(fi);
    assign(fo,'NKBAS.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.