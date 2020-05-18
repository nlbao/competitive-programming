const   MAX_N = 110;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    a:array[0..MAX_N,0..MAX_N] of longint;
    e:array[0..2*MAX_M] of recEdge;
    head,f:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    ok:boolean;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
    a[u][v]:=1;
end;

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    fillchar(a,sizeof(a),0);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   tryf(i:longint);
var j:longint;
begin
    if ok then exit;
    if i > n then begin
        if a[f[i-1]][1] = 1 then ok:=true;
        exit;
    end;
    j:=head[f[i-1]];
    while j <> 0 do with e[j] do begin
        if avail[y] then begin
            f[i]:=y;
            avail[y]:=false;
            tryf(i+1);
            if ok then exit;
            avail[y]:=true;
            f[i]:=-1;
        end;
        j:=link;
    end;
end;

procedure   solve;
var i:longint;
begin
    for i:=1 to n do avail[i]:=true;
    avail[1]:=false;
    f[1]:=1;    f[n+1]:=1;
    ok:=false;
    tryf(2);
    if n = 1 then dec(n);
    for i:=1 to n+1 do write(fo,f[i],' ');
end;

begin
    assign(fi,'halmilton.in');  reset(fi);
    assign(fo,'halmilton.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.