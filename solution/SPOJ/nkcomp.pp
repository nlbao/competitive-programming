{$M+ 2000000}

uses    math;

const   MAX_N = 100010;
        MAX_M = 100010;
        MAX_Q = 500010;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,top,time,maxH,qleft,qright,pos:longint;
    head,h,a,b,c,p,start,finish:array[0..MAX_N] of longint;
    e:array[0..MAX_M] of recEdge;
    f:array[0..MAX_N] of ll;
    value:ll;


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
    read(fi,n);
    nE:=0;
    for i:=0 to n+1 do head[i]:=0;
    for i:=1 to n-1 do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    inc(c[h[u]]);   maxH:=max(maxH,h[u]);
    inc(top);   a[top]:=u;
    inc(time);  start[u]:=time;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        h[y]:=h[u]+1;
        dfs(y);
        i:=link;
    end;
    inc(time);  finish[u]:=time;
end;

procedure   init();
var i,j,u:longint;
begin
    top:=0;     time:=0;
    h[1]:=1;    maxH:=0;
    for i:=0 to n+1 do c[i]:=0;
    dfs(1);
    for i:=2 to n+1 do c[i]:=c[i-1]+c[i];
    for i:=n downto 1 do begin
        u:=a[i];    j:=h[u];
        b[c[j]]:=u;
        p[u]:=c[j];
        dec(c[j]);
    end;
end;

function    find_left(h,x:longint):longint;
var l,r,mid,t:longint;
begin
    l:=c[h]+1;  r:=c[h+1];
    t:=MAX_N+1;
    while l <= r do begin
        mid:=(l+r)>>1;
        if start[b[mid]] >= x then begin
            t:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
    exit(t);
end;

function    find_right(h,x:longint):longint;
var l,r,mid,t:longint;
begin
    l:=c[h]+1;  r:=c[h+1];
    t:=-1;
    while l <= r do begin
        mid:=(l+r)>>1;
        if finish[b[mid]] <= x then begin
            t:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    exit(t);
end;

procedure   update(i:longint;   value:ll);
begin
    if (i < 1) or (i > n) then exit;
    f[i]:=f[i]+value;
    update(i+(i and (-i)),value);
end;

function    get(i:longint):ll;
begin
    if (i < 1) or (i > n) then exit(0);
    exit(get(i-(i and (-i))) + f[i]);
end;


procedure   solve();
var i,j,k,u,nQ,l,r:longint;
begin
    for i:=0 to n+1 do f[i]:=0;
    read(fi,nQ);
    for i:=1 to nQ do begin
        read(fi,j);
        if j = 1 then begin
            read(fi,u,k,value);
            j:=h[u]+k;
            if j > maxH then continue;
            l:=find_left(j,start[u]);
            r:=find_right(j,finish[u]);
            if l > r then continue;
            update(l,value);
            update(r+1,-value);
        end
        else begin
            read(fi,u);
            j:=p[u];
            writeln(fo,get(j));
        end;
    end;
end;

begin
    assign(fi,'nkcomp.in');     reset(fi);
    assign(fo,'nkcomp.out');    rewrite(fo);
    enter();
    init();
    solve();
    close(fo);
    close(fi);
end.