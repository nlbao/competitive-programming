uses    math;

const   MAX_A = 207;
        MAX_N = sqr(MAX_A);
        MAX_M = 4*MAX_N;
        oo = 1000000000;
        dx:array[1..8] of longint = (+1,+2,+2,+1,-1,-2,-2,-1);
        dy:array[1..8] of longint = (-2,-1,+1,+2,+2,+1,-1,-2);

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,test_id,n,m,nX,nY,nE:longint;
    e:array[0..MAX_M] of recEdge;
    a,head,q,d,matchX,matchY:array[0..MAX_N] of longint;


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
var i,j,k,u,v:longint;
    id,color:array[-7..MAX_A,-7..MAX_A] of longint;
begin
    nE:=0;
    fillchar(head,sizeof(head),0);
    read(fi,m,n,k);
    fillchar(id,sizeof(id),0);
    for i:=1 to k do begin
        read(fi,u,v);
        id[u][v]:=-1;
    end;

    nX:=0;  nY:=0;
    for i:=1 to m do
        for j:=1 to n do
            if id[i][j] = 0 then begin
                color[i][j]:=(i+j) and 1;
                if color[i][j] = 0 then begin
                    inc(nX);
                    id[i][j]:=nX;
                end
                else begin
                    inc(nY);
                    id[i][j]:=nY;
                end;
            end;
    for i:=1 to m do
        for j:=1 to n do
            if (id[i][j] > 0) and (color[i][j] = 0) then
                for k:=1 to 8 do begin
                    u:=i+dx[k];
                    v:=j+dy[k];
                    if (id[u][v] > 0) and (color[u][v] = 1) then
                        add_edge(id[i][j],id[u][v]);
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


function    solve():longint;
var i,u,res,old:longint;
    list:array[0..MAX_N] of longint;
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
    exit(nX+nY-res);
end;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'kncb.in');    reset(fi);
    assign(fo,'kncb.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    for test_id:=1 to nTest do begin
        enter();
        writeln(fo,'Case ',test_id,': ',solve());
    end;
    close(fi);
    close(fo);
end.