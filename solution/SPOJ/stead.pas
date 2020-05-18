uses    math;

const   MAX_A = 1003;
        MAX_B = 22;
        MAX_N = MAX_A + MAX_B;
        MAX_M = MAX_A + MAX_B + MAX_A*MAX_B;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w,c,f:longint;
            link:longint;
        end;


var fi,fo:text;
    n,m,nA,nB,nE,s,t:longint;
    id:array[1..2,0..MAX_N] of longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,q,d,pos:array[0..MAX_N] of longint;


procedure   push(var x:longint);    begin   inc(n); x:=n;   end;

procedure   add_edge(u,v,cc,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        c:=cc;  w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        c:=0;   w:=ww;
        link:=head[x];
        head[x]:=-nE;
    end;
end;

procedure   enter();
var i,j,k:longint;
begin
    read(fi,nA,nB);
    n:=2;   nE:=0;
    s:=1;   t:=2;
    fillchar(head,sizeof(head),0);
    for i:=1 to nA do push(id[1][i]);
    for i:=1 to nB do push(id[2][i]);

    for i:=1 to nA do add_edge(s,id[1][i],1,0);
    for i:=1 to nA do
        for j:=1 to nB do begin
            read(fi,k);
            add_edge(id[1][i],id[2][k],1,j);
        end;
    for i:=1 to nB do begin
        read(fi,j);
        add_edge(id[2][i],t,j,0);
    end;
end;


function    find_path():boolean;
var l,r,i,u:longint;
begin
    for i:=1 to n do d[i]:=-1;
    d[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (d[y] = -1) and (f < c) then begin
                d[y]:=d[u]+1;
                if y = t then exit(true);
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    until l > r;
    exit(false);
end;

function    augment_flow(u:longint;  flow:ll):ll;
var delta:ll;
begin
    if flow = 0 then exit(0);
    if u = t then exit(flow);
    while pos[u] <> 0 do with e[pos[u]] do begin
        if d[y] = d[u]+1 then begin
            delta:=augment_flow(y,min(flow, c-f));
            if delta > 0 then begin
                f:=f+delta;
                with e[-pos[u]] do f:=f-delta;
                exit(delta);
            end;
        end;
        pos[u]:=link;
    end;
    exit(0);
end;

function    check(left,right:longint):boolean;
var i,u,delta,flow:longint;
begin
    for u:=id[1][1] to id[1][nA] do begin
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (y <> s) then
                if (w < left) or (w > right) then c:=0
                else c:=1;
            i:=link;
        end;
    end;
    for i:=-nE to nE do e[i].f:=0;

    flow:=0;
    while find_path() do begin
        for i:=1 to n do pos[i]:=head[i];
        repeat
            delta:=augment_flow(s,oo);
            flow:=flow+delta;
        until delta = 0;
    end;
    exit(flow >= nA);
end;

procedure   solve();
var l,r,mid,i,res:longint;
    ok:boolean;
begin
    l:=1;   r:=nB;
    while l <= r do begin
        mid:=(l+r) shr 1;
        ok:=false;
        for i:=1 to nB-mid+1 do
            if check(i,i+mid-1) then begin
                ok:=true;
                break;
            end;
        if ok then begin
            res:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'STEAD.in');    reset(fi);
    assign(fo,'STEAD.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.