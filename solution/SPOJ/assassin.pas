{$M+ 16777216}

uses    math;

const   MAX_N = 1003;
        MAX_M = 1000006;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,test_id,n,m,nE,nC,nX,nY,count,top:longint;
    e:array[0..MAX_M] of recEdge;
    head,q,stt,num,low,c:array[0..MAX_N] of longint;
    d,matchX,matchY:array[0..MAX_N] of longint;
    a:array[0..MAX_N,0..MAX_N] of boolean;

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
    nE:=0;
    fillchar(head,sizeof(head),0);
    read(fi,n,m);
    for i:=1 to m do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   dfs_0(u:longint);
var i:longint;
begin
    stt[u]:=0;
    inc(top);   q[top]:=u;
    inc(count);
    num[u]:=count;  low[u]:=oo;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if stt[y] < 1 then
            if stt[y] = -1 then begin
                dfs_0(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        i:=link;
    end;
    if low[u] >= num[u] then begin
        inc(nC);
        repeat
            i:=q[top];  dec(top);
            c[i]:=nC;
            stt[i]:=1;
        until i = u;
    end;
end;

procedure   dfs_1(u:longint);
var i:longint;
begin
    stt[u]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if stt[y] = 0 then dfs_1(y);
        i:=link;
    end;
end;

procedure   init();
var i,j:longint;
begin
    top:=0;
    count:=0;   nC:=0;
    for i:=1 to n do stt[i]:=-1;
    for i:=1 to n do
        if stt[i] = -1 then dfs_0(i);

    n:=nC;
    m:=nE;  nE:=0;
    for i:=1 to n do begin
        head[i]:=0;
        num[i]:=0;
    end;
    for i:=1 to m do with e[i] do
        if c[x] <> c[y] then
            add_edge(c[x],c[y]);

    for i:=1 to n do begin
        for j:=1 to n do stt[j]:=0;
        dfs_1(i);
        for j:=1 to n do a[i][j]:=(stt[j] = 1);
        a[i][i]:=false;
    end;

    nE:=0;
    fillchar(head,sizeof(head),0);
    for i:=1 to n do
        for j:=1 to n do
            if a[i][j] then add_edge(i,j);
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


function    solve():longint;
var i,u,old,res:longint;
    list:array[0..MAX_N] of longint;
begin
    nX:=n;  nY:=n;
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
    exit(n-res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'ASSASSIN.in');    reset(fi);
    assign(fo,'ASSASSIN.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    for test_id:=1 to nTest do begin
        enter();
        init();
        writeln(fo,'Case ',test_id,': ',solve());
    end;
    close(fi);
    close(fo);
end.
