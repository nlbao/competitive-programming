const   INPUT = 'I.in';
        OUTPUT = 'I.out';
        MAX_N = 200010;
        MAX_M = MAX_N;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,i,n,m,root,res:longint;
    e:array[0..MAX_M] of recEdge;
    head,degI,parent,f:array[0..MAX_N] of longint;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        link:=head[u];
        head[u]:=m;
    end;
end;

procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n);
    m:=0;
    for i:=0 to n-1 do begin
        head[i]:=0;
        degI[i]:=0;
    end;
    for i:=1 to n-1 do begin
        readln(fi,u,v);
        add_edge(u,v);
        inc(degI[v]);
    end;
    for i:=0 to n-1 do
        if degI[i] = 0 then begin
            root:=i;
            break;
        end;
end;

procedure   DFS(u:longint);
var i:longint;
begin
    f[u]:=0;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if parent[y] < 0 then begin
                parent[y]:=u;
                DFS(y);
                inc(f[u]);
            end;
            i:=link;
        end;
    if (f[u] > 0) and (u <> root) then dec(f[u]);
end;

procedure   solve;
var i:longint;
begin
    for i:=0 to n-1 do parent[i]:=-1;
    parent[root]:=MAX_N;
    DFS(root);
    res:=0;
    for i:=0 to n-1 do inc(res,f[i]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        enter;
        solve;
        writeln(fo,'Case ',i,': ',res);
    end;
    close(fo);
    close(fi);
end.
