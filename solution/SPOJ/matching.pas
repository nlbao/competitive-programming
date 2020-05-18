uses    math;

const   MAX_N = 50010;
        MAX_M = 150004;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nX,nY,n,m,nE:longint;
    e:array[0..MAX_M] of recEdge;
    head,q,d,list,matchX,matchY:array[0..MAX_N] of longint;


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
    read(fi,nX,nY,m);
    nE:=0;
    for i:=0 to nX do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;


function    find_path():boolean;
var l,r,i,u,v:longint;
begin
    l:=1;   r:=0;
    for i:=1 to nX do
        if matchX[i] = 0 then begin
            d[i]:=0;
            inc(r); q[r]:=i;
        end
        else d[i]:=-1;
    d[0]:=-1;

    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            v:=matchY[y];
            if d[v] = -1 then begin
                d[v]:=d[u]+1;
                if v = 0 then exit(true);
                inc(r); q[r]:=v;
            end;
            i:=link;
        end;
    until l > r;
    exit(false);
end;

procedure   fix(u,v:longint);   begin   matchX[u]:=v;   matchY[v]:=u;   end;

function    dfs(u:longint):boolean;
var i,v:longint;
begin
    if u = 0 then exit(true);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        v:=matchY[y];
        if (d[v] = d[u]+1) and (dfs(v)) then begin
            fix(u,y);
            exit(true);
        end;
        i:=link;
    end;
    d[u]:=-1;
    exit(false);
end;



procedure   solve();
var i,u,old,res:longint;
begin
    res:=0;
    m:=0;
    for i:=1 to nX do matchX[i]:=0;
    for i:=1 to nY do matchY[i]:=0;
    for u:=1 to nX do begin
        inc(m);
        list[m]:=u;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if matchY[y] = 0 then begin
                fix(u,y);
                inc(res);
                dec(m);
                break;
            end;
            i:=link;
        end;
    end;

    while find_path() do begin
        old:=m;
        for i:=old downto 1 do begin
            u:=list[i];
            if (matchX[u] = 0) and (dfs(u)) then begin
                inc(res);
                list[i]:=list[m];
                dec(m);
            end;
        end;
        if old = m then break;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'MATCHING.in');    reset(fi);
    assign(fo,'MATCHING.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.