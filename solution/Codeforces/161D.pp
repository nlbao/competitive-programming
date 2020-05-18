const   MAX_N = 50010;
        MAX_K = 510;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,k:longint;
    e:array[0..2*MAX_N] of recEdge;
    head,p:array[0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_K] of int64;
    s:array[0..MAX_K] of int64;
    res:int64;


procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[u];
        head[u]:=m;
    end;
end;

procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n,k);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   dfs(u:longint);
var i,j:longint;
begin
    f[u][0]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = 0 then begin
            p[y]:=u;
            dfs(y);
            for j:=1 to k do
                f[u][j]:=f[u][j]+f[y][j-1];
        end;
        i:=link;
    end;

    fillchar(s,sizeof(s),0);
    s[0]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = u then begin
            for j:=0 to k-1 do
                res:=res+f[y][j]*s[k-j-1];
            for j:=0 to k-1 do
                s[j+1]:=s[j+1]+f[y][j];
        end;
        i:=link;
    end;
end;

procedure   solve;
var i,j:longint;
begin
    res:=0;
    for i:=0 to n do begin
        p[i]:=0;
        for j:=0 to k+1 do f[i][j]:=0;
    end;
    p[1]:=-1;
    dfs(1);
    writeln(fo,res);
end;

begin
    assign(fi,'161D.in');   reset(fi);
    assign(fo,'161D.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
