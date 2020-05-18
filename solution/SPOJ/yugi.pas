{$M 2000000,0,2000000}
uses    math;

const   MAX_N = 202;
        MAX_M = sqr(MAX_N) shr 1;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
        end;

var fi,fo:text;
    n,m,k:longint;
    e:array[0..MAX_M] of recEdge;
    p:array[0..MAX_N] of longint;


procedure   enter();
var i,j,a:longint;
begin
    m:=0;
    readln(fi,n,k);
    for i:=1 to n do
        for j:=1 to n do begin
            inc(m);
            with e[m] do begin
                x:=i; y:=j;
                read(fi,w);
            end;
            if i >= j then dec(m);
        end;
end;


procedure   sort(l,r:longint);
var i,j,p:longint;
    t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=e[i].w;

    i:=l;   j:=r;
    repeat
        while e[i].w < p do inc(i);
        while e[j].w > p do dec(j);
        if i <= j then begin
            t:=e[i];
            e[i]:=e[j];
            e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


function    get_root(u:longint):longint;
begin
    if p[u] < 1 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;


function    solve():longint;
var i,c,r1,r2:longint;
begin
    randomize;
    sort(1,m);

    c:=n;
    for i:=1 to n do p[i]:=-1;

    for i:=1 to m do with e[i] do begin
        r1:=get_root(x);
        r2:=get_root(y);
        if r1 = r2 then continue;
        if c = k then exit(w);
        p[r1]:=p[r1]+p[r2];
        p[r2]:=r1;
        dec(c);
    end;
    exit(0);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'yugi.in');    reset(fi);
    assign(fo,'yugi.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    writeln(fo,solve());
    close(fo);
    close(fi);
end.