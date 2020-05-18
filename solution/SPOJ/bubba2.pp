const   MAX_N = 50010;
        MAX_E = 2*MAX_N;
        MAX_Q = 50010;
        MAX_K = 50010;


type    recEdge  = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,nQ,nE,m:longint;
    e:array[0..MAX_E] of recEdge;
    head,p,a,b:array[0..MAX_N] of longint;
    res:char;

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
var i,j,k:longint;
begin
    readln(fi,n,nQ);
    for i:=1 to n do begin
        read(fi,a[i]);
        head[i]:=0;
    end;
    nE:=0;
    for i:=1 to n-1 do begin
        read(fi,j,k);
        add_edge(j,k);
        add_edge(k,j);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = 0 then begin
            p[y]:=u;
            dfs(y);
        end;
        i:=link;
    end;
end;

procedure   find(u,len:longint);
var i:longint;
begin
    if a[u] <> b[len] then exit;
    if len = m then res:='Y';
    if res = 'Y' then exit;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = u then find(y,len+1);
        if res = 'Y' then exit;
        i:=link;
    end;
end;

procedure   solve();
var i,j:longint;
begin
    fillchar(p,sizeof(p),0);
    p[1]:=n+10;
    dfs(1);

    for i:=1 to nQ do begin
        read(fi,m);
        for j:=1 to m do read(fi,b[j]);
        res:='N';
        for j:=1 to n do
            if res = 'Y' then break
            else find(j,1);
        writeln(fo,res);
    end;
end;

begin
    assign(fi,'bubba2.in');     reset(fi);
    assign(fo,'bubba2.out');    rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter();
        solve();
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
