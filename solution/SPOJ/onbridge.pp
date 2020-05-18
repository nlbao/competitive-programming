const   MAX_N = 50010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;


var fi,fo:text;
    nTest,n,m,nE:longint;
    x,y:array[0..MAX_M] of longint;
    e:array[0..2*MAX_N] of recEdge;
    head,h,f,p:array[0..MAX_N] of longint;
    ok:array[0..MAX_M] of boolean;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;

function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   enter;
var i,r1,r2:longint;
begin
    nE:=0;
    readln(fi,n,m);
    fillchar(ok, sizeof(ok), false);
    for i:=1 to n do begin
        p[i]:=-1;
        head[i]:=0;
    end;

    for i:=1 to m do begin
        readln(fi,x[i],y[i]);
        inc(x[i]);  inc(y[i]);
        r1:=get_root(x[i]);
        r2:=get_root(y[i]);
        if r1 <> r2 then begin
            p[r2]:=r1;
            add_edge(x[i],y[i]);
            add_edge(y[i],x[i]);
            ok[i]:=true;
        end;
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if h[y] = 0 then begin
            f[y]:=u;
            h[y]:=h[u]+1;
            dfs(y);
        end;
        i:=link;
    end;
end;

procedure   solve;
var i,u,v,res:longint;
begin
    fillchar(h, sizeof(h), 0);
    for i:=1 to n do begin
        if h[i] = 0 then begin
            f[i]:=-1;
            h[i]:=1;
            dfs(i);
        end;
        p[i]:=-1;
    end;

    res:=0;
    for i:=1 to m do begin
        if ok[i] then inc(res)
        else begin
            u:=get_root(x[i]);
            v:=get_root(y[i]);
            while u <> v do begin
                if h[u] > h[v] then begin
                    p[u]:=get_root(f[u]);
                    u:=p[u];
                end
                else begin
                    p[v]:=get_root(f[v]);
                    v:=p[v];
                end;
                dec(res);
            end;
        end;
        writeln(fo,res);
    end;
end;


begin
    assign(fi,{'test.out'}'onbridge.in');   reset(fi);
    assign(fo,'onbridge.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
