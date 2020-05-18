{$M+ 100005}
{$R-, $I-, $Q-}

uses    math;

const   MAX_N = 100005;
        MAX_M = 2*MAX_N;
        MAX_K = 1000006;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            a,b:longint;
            link:longint;
        end;

var fi,fo:text;
    n,k,nE,top:longint;
    e:array[0..MAX_M] of recEdge;
    head,p,h:array[0..MAX_N] of longint;
    f,g:array[0..MAX_M] of longint;


procedure   add_edge(u,v,aa,bb:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        a:=aa;  b:=bb;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i,x,y,a,b:longint;
begin
    nE:=0;
    read(fi,n,k);
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        read(fi,x,y,a,b);
        add_edge(x,y,a,b);
        add_edge(y,x,a,b);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = -1 then begin
            p[y]:=i;
            f[i]:=a;
            g[i]:=g[p[u]]+b;
            dfs(y);
            f[p[u]]:=max(f[p[u]],f[i]+e[p[u]].a);
        end;
        i:=link;
    end;
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

function    cmp(i,j:longint):longint;   begin   exit(f[h[i]]-f[h[j]]);  end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) >= 0) then exit;
    swap(h[i],h[j]);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) > 0) then inc(j);
    if (j > top) or (cmp(j,i) <= 0) then exit;
    swap(h[i],h[j]);
    down_heap(j);
end;

procedure   push(u:longint);
begin
    inc(top);
    h[top]:=u;
    up_heap(top);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    swap(h[1],h[top]);
    dec(top);
    down_heap(1);
end;

procedure   add(i:longint);
var u,j:longint;
begin
    u:=e[i].y;
    j:=i;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = i then begin
            f[i]:=f[i]+g[j];
            push(i);
        end;
        i:=link;
    end;
end;


procedure   dfs_2(u:longint);
var i:longint;
begin
    f[u]:=0;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = i then begin
            dfs_2(y);
            f[u]:=max(f[u],f[y]+a);
        end;
        i:=link;
    end;
end;


procedure   solve();
var i,j,limit,res:longint;
begin
    for i:=0 to nE do begin
        f[i]:=0;
        g[i]:=0;
    end;
    for i:=1 to n do p[i]:=-1;
    p[1]:=0;
    dfs(1);

    top:=0;
    e[0].y:=1;
    e[0].a:=0;  e[0].b:=0;
    add(0);


    while (k > 0) and (top > 0) do begin
        {pop(i);
        limit:=min(e[i].a-e[i].b,k);
        if top > 0 then begin
            j:=h[1];
            limit:=min(limit,(f[i]-d[i]) - (f[j]-d[j]) + 1);
        end;
        d[i]:=d[i]+limit;
        e[i].a:=e[i].a-limit;
        k:=k-limit;
        if e[i].a = e[i].b then add(i)
        else push(i);}

        i:=h[1];
        limit:=min(e[i].a-e[i].b,k);
        if top > 1 then begin
            if (top > 2) and (f[h[3]] > f[h[2]]) then j:=h[3]
            else j:=h[2];
            limit:=min(limit,f[i]-f[j]+1);
        end;

        k:=k-limit;
        f[i]:=f[i]-limit;
        e[i].a:=e[i].a-limit;

        if e[i].a = e[i].b then begin
            pop(i);
            add(i);
        end
        else down_heap(1);
     end;

    dfs_2(1);
    writeln(fo,f[1]);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'MROADS.in');   reset(fi);
    assign(fo,'MROADS.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.


