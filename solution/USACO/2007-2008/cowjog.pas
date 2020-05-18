uses    math;

const   MAX_N = 1010;
        MAX_M = 10010;
        MAX_K = 110;
        oo = 2000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:ll;
            link:longint;
        end;

var fi,fo:text;
    n,nE,k:longint;
    e:array[0..MAX_M] of recEdge;
    head,deg,q:array[0..MAX_N] of longint;
    f,g:array[0..MAX_N,0..MAX_K] of ll;


procedure   add_edge(u,v,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
end;

procedure   enter();
var i,m,u,v,w:longint;
begin
    nE:=0;
    read(fi,n,m,k);
    for i:=0 to n+1 do begin
        head[i]:=0;
        deg[i]:=0;
    end;
    for i:=1 to m do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
        inc(deg[v]);
    end;
end;


procedure   solve();
var i,j,t,l,r,c,u,h:longint;
    d:ll;
begin
    for i:=1 to n do
        for j:=1 to k do begin
            f[i][j]:=oo;
            g[i][j]:=0;
        end;
    f[n][1]:=0;
    g[n][1]:=1;

    l:=1;   r:=1;
    q[1]:=n;
    repeat
        u:=q[l];    inc(l);
        t:=head[u];
        while t <> 0 do with e[t] do begin
            i:=1;   j:=1;
            while (i <= k) and (j <= k) do begin
                if f[u][i] = oo then break;
                d:=f[u][i]+w;
                if d < f[y][j] then begin
                    for h:=k downto j+1 do begin
                        f[y][h]:=f[y][h-1];
                        g[y][h]:=g[y][h-1];
                    end;
                    f[y][j]:=d;
                    g[y][j]:=g[u][i];
                    inc(i); inc(j);
                end
                else if d = f[y][j] then begin
                    g[y][j]:=min(g[y][j]+g[u][i],k);
                    inc(i); inc(j);
                end
                else inc(j);
            end;

            dec(deg[y]);
            if deg[y] = 0 then begin
                inc(r);
                q[r]:=y;
            end;
            t:=link;
        end;
    until l > r;

    c:=0;
    for i:=1 to k do
        if f[1][i] = oo then begin
            writeln(fo,-1);
            inc(c);
            if c = k then break;
        end
        else
            for j:=1 to g[1][i] do begin
                writeln(fo,f[1][i]);
                inc(c);
                if c = k then break;
            end;
end;


begin
    assign(fi,'cowjog.in');     reset(fi);
    assign(fo,'cowjog.out');    rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.
