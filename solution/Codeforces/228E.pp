const   MAX_N = 110;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,nP:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,stt,f:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;


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
var i,j,u,v,w,m:longint;
begin
    nE:=0;
    read(fi,n,m);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,w);
        add_edge(u,v,1-w);
        add_edge(v,u,1-w);
    end;
end;


function    dfs(u,d:longint):boolean;
var i:longint;
begin
    avail[u]:=false;
    stt[u]:=1;

    f[u]:=d;
    if d = 1 then inc(nP);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if stt[y] = 0 then begin
            if dfs(y,d xor w) = false then exit(false);
        end
        else if f[y] <> (d xor w) then exit(false);
        i:=link;
    end;

    stt[i]:=0;
    exit(true);
end;


procedure   solve();
var i,j,nR:longint;
    ok:boolean;
begin
    nR:=0;
    ok:=true;
    for i:=1 to n do begin
        avail[i]:=true;
        stt[i]:=0;
        f[i]:=0;
    end;
    for i:=1 to n do
        if avail[i] then begin
            nP:=0;
            if dfs(i,0) = false then begin
                nP:=0;
                ok:=dfs(i,1);
            end;
            if not ok then break;
            nR:=nR+nP;

        end;

    if not ok then begin
        writeln(fo,'Impossible');
        exit;
    end;

    writeln(fo,nR);
    for i:=1 to n do
        if f[i] = 1 then write(fo,i,' ');
end;

begin
    assign(fi,'228E.in');   reset(fi);
    assign(fo,'228E.out');  rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.