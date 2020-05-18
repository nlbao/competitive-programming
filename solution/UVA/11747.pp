const   MAX_N = 200010;
        MAX_M = 200010;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:ll;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..MAX_M] of recEdge;
    p:array[0..MAX_N] of longint;
    f:array[0..MAX_M] of longint;

procedure   enter;
var i:longint;
begin
    for i:=1 to m do with e[i] do begin
        readln(fi,x,y,w);
        inc(x);  inc(y);
    end;
end;

procedure   sort(l,r:longint);
var i,j:longint;
    p:ll;
    t:recEdge;
begin
    if l >= r then exit;
    p:=e[l+random(r-l)].w;
    i:=l;   j:=r;
    repeat
        while e[i].w < p do inc(i);
        while e[j].w > p do dec(j);
        if i <= j then begin
            t:=e[i];    e[i]:=e[j];     e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;


function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   solve;
var i,r1,r2,nF:longint;
begin
    randomize;
    sort(1,m);
    for i:=1 to n do p[i]:=-1;
    nF:=0;
    for i:=1 to m do with e[i] do begin
        r1:=get_root(x);
        r2:=get_root(y);
        if r1 <> r2 then begin
            p[r1]:=p[r1]+p[r2];
            p[r2]:=r1;
        end
        else begin
            inc(nF);
            f[nF]:=i;
        end;
    end;
    if nF = 0 then writeln(fo,'forest')
    else begin
        for i:=1 to nF-1 do write(fo,e[f[i]].w,' ');
        writeln(fo,e[f[nF]].w);
    end;
end;

begin
    assign(fi,'11747.in');  reset(fi);
    assign(fo,'11747.out'); rewrite(fo);
    readln(fi,n,m);
    while n > 0 do begin
        enter;
        solve;
        readln(fi,n,m);
    end;
    close(fo);
    close(fi);
end.