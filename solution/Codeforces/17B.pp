const   MAX_N = 1010;
        MAX_M = 10010;
        oo = 1000100000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    head,q,f:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    e:array[0..MAX_M] of recEdge;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;


procedure   enter;
var i,j,u,v,w:longint;
begin
    readln(fi,n);
    m:=0;
    for i:=1 to n do begin
        read(fi,q[i]);
        head[i]:=0;
    end;
    readln(fi,j);
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
    end;
end;

function    solve:longint;
var i,t,u:longint;
begin
    t:=-1;
    for i:=1 to n do begin
        ok[i]:=true;
        f[i]:=oo;
        if q[i] > t then begin
            t:=q[i];
            u:=i;
        end;
    end;
    f[u]:=0;
    repeat
        ok[u]:=false;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            f[y]:=min(f[y],w);
            i:=link;
        end;
        u:=-1;  t:=oo;
        for i:=1 to n do
            if (ok[i]) and (f[i] < t) then begin
                t:=f[i];
                u:=i;
            end;
    until u = -1;
    t:=0;
    for i:=1 to n do
        if f[i] = oo then exit(-1)
        else t:=t+f[i];
    exit(t);
end;

begin
    assign(fi,'17B.in');    reset(fi);
    assign(fo,'17B.out');   rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.