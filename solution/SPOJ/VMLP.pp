const   MAX_N = 1010;
        MAX_M = 10010;


var fi,fo:text;
    n,m,res:longint;
    head,c,f,t,r,p:array[0..MAX_N] of longint;
    e:array[0..2*MAX_M] of longint;
    ok,avail:array[0..MAX_N] of boolean;


procedure   enter;
var i:longint;
    u,v:array[0..MAX_M] of longint;
begin
    read(fi,n,m);
    for i:=0 to n+1 do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u[i],v[i]);
        inc(head[u[i]]);
        inc(head[v[i]]);
    end;
    for i:=2 to n+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to m do begin
        e[head[u[i]]]:=v[i]; dec(head[u[i]]);
        e[head[v[i]]]:=u[i]; dec(head[v[i]]);
    end;
    for i:=1 to n do c[i]:=head[i+1]-head[i];
end;

procedure   dfs(u:longint);
var i,j,v:longint;
begin
    ok[u]:=false;
    f[u]:=1;    t[u]:=u;
    j:=random(c[u]);
    for i:=1 to c[u] do begin
        j:=(j+1) mod c[u];
        v:=e[head[u]+1+j];
        if p[v] = -1 then begin
            p[v]:=u;
            dfs(v);
            if f[v] >= f[u] then begin
                f[u]:=f[v]+1;
                t[u]:=v;
            end;
        end;
    end;
end;

procedure   update(u:longint);
var i,v,f1,f2,v1,v2:longint;
begin
    f1:=0;  f2:=0;
    v1:=0;  v2:=0;
    for i:=head[u]+1 to head[u+1] do begin
        v:=e[i];
        if p[v] <> u then continue;
        if f[v] > f1 then begin
            f2:=f1;     v2:=v1;
            f1:=f[v];   v1:=v;
        end
        else if f[v] > f2 then begin
            f2:=f[v];   v2:=v;
        end;
    end;
    if f1+f2+1 <= res then exit;

    res:=f1+f2+1;
    for i:=f1 downto 1 do begin
        r[i]:=v1;
        v1:=t[v1];
    end;
    r[f1+1]:=u;
    for i:=f1+2 to f1+f2+1 do begin
        r[i]:=v2;
        v2:=t[v2];
    end;
end;

procedure   solve();
var limit,turn,i,j,u:longint;
begin
    randomize;
    res:=1;
    r[1]:=1;

    for limit:=1 to MAX_M do
        if limit*(m+n) > 5000000 then break;
    //limit:=MAX_N;

    u:=1;
    for turn:=1 to limit do begin
        for i:=1 to n do p[i]:=-1;
        u:=(turn mod n)+1;
        p[u]:=0;
        dfs(u);
        update(u);
    end;

    u:=r[res];
    for turn:=1 to limit do begin
        for i:=1 to n do p[i]:=-1;
        p[u]:=0;
        dfs(u);
        update(u);
        u:=r[res];
    end;

    writeln(fo,res);
    for i:=1 to res do write(fo,r[i],' ');
end;


begin
    assign(fi,'VMLP.in');   reset(fi);
    assign(fo,'VMLP.out'); rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.
