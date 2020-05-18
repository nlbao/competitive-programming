uses    math;

const   MAX_N = 1010;
        MAX_M = 20010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,q,s,t:longint;
    e:array[0..MAX_M] of recEdge;
    head,p:array[0..MAX_N] of longint;
    ok:array[0..MAX_M] of boolean;
    avail:array[0..MAX_N] of longint;
    cir:boolean;

procedure   qsort(l,r:longint);
var i,j,p1,p2:longint;
    t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p1:=e[i].x; p2:=e[i].y;
    repeat
        while (e[i].x < p1) or ((e[i].x = p1) and (e[i].y < p2)) do inc(i);
        while (e[j].x > p1) or ((e[j].x = p1) and (e[j].y > p2)) do dec(j);
        if i <= j then begin
            t:=e[i];    e[i]:=e[j];     e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to m do readln(fi,e[i].x,e[i].y);
    randomize;
    qsort(1,m);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do with e[i] do begin
        link:=head[x];
        head[x]:=i;
    end;
end;


{procedure   dfs1(u:longint);
var i:longint;
begin
    avail[u]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[y] = 0 then begin
            p[y]:=i;
            dfs1(y);
        end
        else if avail[y] = 1 then begin
            s:=u;   t:=y;
            ok[i]:=true;
        end;
        if s > 0 then exit;
        i:=link;
    end;
    avail[u]:=2;
end;

procedure   init;
var i:longint;
begin
    fillchar(ok,sizeof(ok),false);
    fillchar(avail,sizeof(avail),0);
    fillchar(p,sizeof(p),0);
    q:=1;   s:=-1;
    for i:=1 to n do
        if (avail[i] = 0) and (s = -1) then
            dfs1(i);
    if s = -1 then exit;
    repeat
        inc(q);
        ok[p[s]]:=true;
        s:=e[p[s]].x;
    until s = t;
end;  }

procedure   dfs2(u:longint);
var i:longint;
begin
    avail[u]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if i <> s then
            if avail[y] = 0 then dfs2(y)
            else if avail[y] = 1 then cir:=true;
        if cir = true then exit;
        i:=link;
    end;
    avail[u]:=2;
end;

procedure   solve;
var i,j:longint;
begin
    fillchar(ok,sizeof(ok),true);
    q:=m;
    for i:=1 to m do
        if ok[i] then begin
            fillchar(avail,sizeof(avail),0);
            s:=i;   cir:=false;
            for j:=1 to n do
                if (avail[j] = 0) and (not cir) then
                    dfs2(j);
                    if cir = true then begin
                dec(q);
                ok[i]:=false;
            end;
        end;
    if q < 1 then begin
        writeln(fo,-1);
        exit;
    end;
    writeln(fo,q);
    for i:=1 to m do
        if ok[i] then writeln(fo,e[i].x,' ',e[i].y);
end;

begin
    assign(fi,'QBCirArc.in');   reset(fi);
    assign(fo,'QBCirArc.out');  rewrite(fo);
    enter;
    {init;}
    solve;
    close(fo);
    close(fi);
end.