const
    INPUT = 'NKOneARC.inp';
    OUTPUT = 'NKOneARC.out';
    MAX_N = 2010;
    MAX_M = 30010;

type
    recEdge = record
        x,y:longint;
    end;

var
    fi,fo:text;
    N,M,nC,count,stack_size:longint;
    e:array[0..MAX_M] of recEdge;
    link:array[0..MAX_M] of longint;
    avail:array[0..MAX_N] of boolean;
    head,stack,number,low,c,degI,degO:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);  inline;
begin
    inc(M);
    e[M].x:=u;
    e[M].y:=v;
    link[M]:=head[u];
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j,u,v:longint;
begin
    readln(fi,N,j);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
end;
{---------------------------------------------------------------------------}
procedure   push(u:longint);    inline;
begin
    inc(stack_size);
    stack[stack_size]:=u;
end;
{---------------------------------------------------------------------------}
function    pop:longint;    inline;
begin
    pop:=stack[stack_size];
    dec(stack_size);
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,v:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=count;
    push(u);
    i:=head[u];
    while i <> 0 do begin
        v:=e[i].y;
        if avail[v] then
            if number[v] = -1 then begin
                DFS(v);
                low[u]:=min(low[u],low[v]);
            end
            else low[u]:=min(low[u],number[v]);
        i:=link[i];
    end;
    if low[u] = number[u] then begin
        inc(nC);
        repeat
            v:=pop;
            avail[v]:=false;
            c[v]:=nC;
        until v = u;
    end;
end;
{---------------------------------------------------------------------------}
procedure   new_graph;
var
    i,u:longint;
begin
    nC:=0;
    for i:=1 to N do begin
        avail[i]:=true;
        number[i]:=-1;
    end;
    count:=0;   stack_size:=0;
    for i:=1 to N do
        if avail[i] then DFS(i);

    for i:=1 to nC do begin
        degI[i]:=0;
        degO[i]:=0;
    end;
    for i:=1 to M do
        with e[i] do
            if c[x] <> c[y] then begin
                inc(degO[c[x]]);
                inc(degI[c[y]]);
            end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,a,b,ca,cb:longint;
    res:string;
begin
    res:='YES';
    a:=-1;  b:=-1;
    ca:=-1; cb:=-1;
    for i:=1 to N do begin
        if (degO[c[i]] = 0) and (c[i] <> ca) then
            if a = -1 then begin
                a:=i;
                ca:=c[i];
            end
            else res:='NO';
        if (degI[c[i]] = 0) and (c[i] <> cb) then
            if b = -1 then begin
                b:=i;
                cb:=c[i];
            end
            else res:='NO';
    end;
    if (a = b) or (a = -1) then res:='NO';
    writeln(fo,res);
    if res = 'YES' then writeln(fo,a,' ',b);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    new_graph;
    solve;
    close(fo);
    close(fi);
end.