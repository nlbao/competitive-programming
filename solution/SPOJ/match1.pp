const   MAX_N = 110;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nX,nY,nE:longint;
    e:array[0..MAX_M] of recEdge;
    head,a,match:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    found:boolean;


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
    readln(fi,nX,nY);
    for i:=1 to nX do head[i]:=0;
    while not eof(fi) do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then begin
            ok[y]:=false;
            if match[y] = 0 then found:=true
            else dfs(match[y]);
            if found then begin
                match[y]:=u;
                exit;
            end;
        end;
        i:=link;
    end;
end;


procedure   solve();
var i,c,res:longint;
    stop:boolean;
begin
    for i:=1 to nY do match[i]:=0;
    for i:=1 to nX do a[i]:=i;
    res:=0; c:=nX;
    repeat
        stop:=true;
        for i:=1 to nY do ok[i]:=true;
        for i:=c downto 1 do begin
            found:=false;
            dfs(a[i]);
            if found then begin
                inc(res);
                a[i]:=a[c];
                dec(c);
                stop:=false;
            end;
        end;
    until stop;

    writeln(fo,res);
    for i:=1 to nY do
        if match[i] > 0 then
            writeln(fo,match[i],' ',i);
end;


begin
    assign(fi,'match1.in');    reset(fi);
    assign(fo,'match1.out');   rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.