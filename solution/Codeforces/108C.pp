const   INPUT = '108C.in';
        OUTPUT = '108C.out';
        MAX_N = 1010;
        MAX_M = MAX_N;
        MAX_INT = 1000000000;

type    recEdge = record
            x,y:longint;
            d:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..MAX_M] of recEdge;
    head,degI,degO,des,c:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v,d0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        d:=d0;
        link:=head[u];
        head[u]:=m;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j,u,v,d:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do begin
        head[i]:=0;
        degI[i]:=0; degO[i]:=0;
    end;
    for i:=1 to j do begin
        readln(fi,u,v,d);
        add_edge(u,v,d);
        inc(degI[v]);   inc(degO[u]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var i:longint;
begin
    des[u]:=u;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if c[y] = MAX_INT then begin
                c[u]:=min(c[u],d);
                DFS(y);
                c[u]:=min(c[u],c[y]);
                des[u]:=des[y];
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,nRes:longint;
    res:array[0..MAX_N] of longint;
begin
    nRes:=0;
    for i:=1 to n do c[i]:=MAX_INT;
    for i:=1 to n do
        if (degI[i] = 0) and (degO[i] > 0) then begin
            DFS(i);
            if degO[des[i]] = 0 then begin
                inc(nRes);
                res[nRes]:=i;
            end;
        end;
    writeln(fo,nRes);
    for i:=1 to nRes do
        writeln(fo,res[i],' ',des[res[i]],' ',c[res[i]]);
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