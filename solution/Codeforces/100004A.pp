const   MAX_N = 100010;
        MAX_M = MAX_N;
        oo = 1000000000000000000;

type    int = int64;
        recEdge = record
            x,y:longint;
            w:int;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..2*MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    c,f:array[0..MAX_N] of int;
    s,res:int;

function    min(x,y:int):int;   begin   if x < y then exit(x);  exit(y);    end;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,u,v,w:longint;
begin
    readln(fi,n);
    m:=0;   s:=0;
    for i:=0 to n do begin
        read(fi,c[i]);
        head[i]:=0;
    end;
    for i:=1 to n do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
        s:=s+2*w;
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    avail[u]:=false;
    res:=min(res,s-f[u]+c[u]);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[y] then begin
            f[y]:=f[u]+w;
            dfs(y);
        end;
        i:=link;
    end;
end;

procedure   solve;
var i:longint;
begin
    res:=oo;
    for i:=1 to n do avail[i]:=true;
    f[0]:=0;
    dfs(0);
    writeln(fo,res);
end;

begin
    assign(fi,'100004A.in');    reset(fi);
    assign(fo,'100004A.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.