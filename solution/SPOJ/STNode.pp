const   MAX_N = 10010;
        MAX_M = 100010;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,s,t:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,f,p,trace,id:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    check:boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,u,v:longint;
begin
    read(fi,n,j,s,t);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   DFS1(u:longint);
var i:longint;
begin
    if u = t then check:=true;
    if check = true then exit;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[y] then begin
            trace[y]:=u;
            DFS1(y);
        end;
        i:=link;
    end;
end;

procedure   DFS2(u:longint);
var i:longint;
begin
    avail[u]:=false;
    i:=head[u];
    writeln(u);
    while i <> 0 do with e[i] do begin
        if avail[y] then DFS2(y);
        if id[u]-id[y] <> 1 then begin
            writeln(u,' ',y,' ',f[y]);
            f[u]:=min(f[u],f[y]);
        end;
        i:=link;
    end;
end;

procedure   solve;
var i,j,k,res:longint;
begin
    check:=false;
    for i:=1 to n do begin
        avail[i]:=true;
        id[i]:=oo;
    end;
    DFS1(s);
    k:=1;   p[1]:=t;    id[t]:=1;
    repeat
        inc(k);
        p[k]:=trace[p[k-1]];
        id[p[k]]:=k;
        write(p[k],' ');
    until p[k] = s;
    writeln;
    for i:=1 to n do begin
        avail[i]:=true;
        f[i]:=id[i];
    end;
    writeln(f[2]);
    DFS2(s);
    writeln('    ',f[2]);
    res:=0; j:=f[p[k]];
    for i:=k-1 downto 2 do begin
        if j >= i then inc(res);
        if j >= i then writeln(p[i]);

        j:=min(j,f[p[i]]);
    end;
    writeln(fo,res);
end;


begin
    assign(fi,'STNode.in');     reset(fi);
    assign(fo,'STNode.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.