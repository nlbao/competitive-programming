{$M 16777216}
uses    math;

const   MAX_N = 100005;
        MAX_M = 100005;
        MAX_L = 1166800;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,top,time,last:longint;
    e:array[0..2*MAX_M] of recEdge;
    ok:array[0..MAX_N] of boolean;
    head,c,q,start,finish:array[0..MAX_N] of longint;
    list:array[0..MAX_L] of longint;
    h:array[0..MAX_N] of ll;
    res:ll;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;

procedure   enter();
var i,u,v:longint;
begin
    readln(fi,n);
    nE:=0;
    fillchar(head,sizeof(head),0);
    for i:=1 to n-1 do begin
        read(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   dfs_0(u:longint);
var i:longint;
begin
    ok[u]:=false;
    inc(top);   q[top]:=u;
    inc(time);  start[u]:=time;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then begin
            h[y]:=h[u]+1;
            dfs_0(y);
        end;
        i:=link;
    end;
    inc(time);  finish[u]:=time;
end;

procedure   push(u,i:longint);
begin
    list[c[i]]:=u;
    dec(c[i]);
end;

procedure   init();
var i,j,k,u:longint;
begin
    for i:=1 to n do ok[i]:=true;
    ok[1]:=false;
    h[1]:=1;
    time:=0; top:=0;
    dfs_0(1);

    fillchar(c,sizeof(c),0);
    for i:=1 to n do begin
        j:=i;
        while j <= n do begin
            inc(c[i]);
            j:=j+i;
        end;
    end;

    for i:=1 to n+1 do c[i]:=c[i-1]+c[i];
    for i:=n downto 1 do begin
        u:=q[i];
        for j:=1 to u do
            if j*j > u then break
            else if (u mod j) = 0 then begin
                push(u,j);
                k:=u div j;
                if k <> j then push(u,k);
            end;
    end;
end;

function    is_ancestor(u,v:longint):boolean;
begin   exit((start[u] <= start[v]) and (finish[v] <= finish[u]));  end;

procedure   dfs(u:longint);
var i,v:longint;
begin
    inc(top);
    while top <= last do begin
        v:=list[top];
        if not is_ancestor(u,v) then break;
        res:=res + 2*(h[v]-h[u]);
        dfs(v);
        inc(top);
    end;
    dec(top);
end;

procedure   solve();
var i:longint;
begin
    for i:=1 to n do begin
        top:=c[i];
        last:=c[i+1];
        res:=0;
        dfs(1);
        writeln(fo,res);
    end;
end;

begin
    assign(fi,'TRIP.inp');   reset(fi);
    assign(fo,'TRIP.out');   rewrite(fo);
    enter();
    init();
    solve();
    close(fo);
    close(fi);
end.