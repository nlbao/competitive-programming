const   INPUT = '109C.in';
        OUTPUT = '109C.out';
        MAX_N = 100010;
        MAX_M = MAX_N;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,parent,nChild:array[0..MAX_N] of longint;
    f,g:array[0..MAX_N] of int64;
    ok:array[0..MAX_N] of boolean;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        w:=w0;
        link:=head[u];
        head[u]:=m;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,u,v,w:longint;
begin
    readln(fi,n);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;
{---------------------------------------------------------------------------}
function    is_lucky(x:longint):boolean;
var s:string;
    i:longint;
begin
    str(x,s);
    for i:=1 to length(s) do
        if (s[i] <> '4') and (s[i] <> '7') then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   cal_f(u:longint);
var i:longint;
begin
    f[u]:=0;
    nChild[u]:=1;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if y <> parent[u] then begin
                parent[y]:=u;
                cal_f(y);
                inc(nChild[u],nChild[y]);
                if is_lucky(w) then begin
                    inc(f[u],nChild[y]);
                    ok[y]:=true;
                end
                else inc(f[u],f[y]);
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   cal_g(u:longint);
var i,v:longint;
begin
    v:=parent[u];
    if v = -1 then g[u]:=0
    else
        if ok[u] then g[u]:=n-nChild[u]
        else g[u]:=g[v]+f[v]-f[u];
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if y <> parent[u] then cal_g(y);
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
    res:int64;
begin
    for i:=1 to n do ok[i]:=false;
    parent[1]:=-1;
    cal_f(1);
    cal_g(1);
    res:=0;
    for i:=1 to n do
        res:=res+f[i]*(f[i]-1)+g[i]*(g[i]-1)+2*f[i]*g[i];
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.