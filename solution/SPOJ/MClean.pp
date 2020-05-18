const
    INPUT = 'MClean.inp';
    OUTPUT = 'MClean.out';
    MAX_W = 21;
    MAX_H = 21;
    MAX_N = MAX_W*MAX_H;
    MAX_M = 8*MAX_N;
    MAX_INT = 1000000000;

type
    recEdge = record
        x,y:longint;
    end;

var
    fi,fo:text;
    W,H,N,M,nA,res,sum:longint;
    e:array[0..MAX_M] of recEdge;
    head,a,x:array[0..MAX_N] of longint;
    link:array[0..MAX_M] of longint;
    is_dirty,avail:array[0..MAX_N] of boolean;
    f:array[0..MAX_N,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);  inline;
begin
    if (u = 0) or (v = 0) then exit;
    inc(M);
    with e[M] do begin
        x:=u;
        y:=v;
        link[M]:=head[u];
        head[u]:=M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    s:string;
    i,j:longint;
    id:array[0..MAX_H,0..MAX_W] of longint;
begin
    fillchar(id,sizeof(id),0);
    for i:=0 to MAX_N do is_dirty[i]:=false;
    N:=0;   nA:=0;
    a[0]:=-1;
    for i:=1 to H do begin
        readln(fi,s);
        for j:=1 to W do begin
            if s[j] <> 'x' then begin
                inc(N);
                id[i,j]:=N;
                if s[j] = 'o' then a[0]:=N
                else
                    if s[j] = '*' then begin
                        inc(nA);
                        a[nA]:=N;
                        is_dirty[N]:=true;
                    end;
            end;
        end;
    end;
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to H do
        for j:=1 to W do begin
            add_edge(id[i,j],id[i-1,j]);    add_edge(id[i-1,j],id[i,j]);
            add_edge(id[i,j],id[i+1,j]);    add_edge(id[i+1,j],id[i,j]);
            add_edge(id[i,j],id[i,j-1]);    add_edge(id[i,j-1],id[i,j]);
            add_edge(id[i,j],id[i,j+1]);    add_edge(id[i,j+1],id[i,j]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   BFS(s:longint);
var
    i,u,front,rear:longint;
    queue,c:array[0..MAX_N] of longint;
begin
    for i:=1 to N do avail[i]:=true;
    front:=1;   rear:=1;
    queue[1]:=s;
    avail[s]:=false;
    c[s]:=0;
    repeat
        u:=queue[front];    inc(front);
        i:=head[u];
        while i <> 0 do begin
            with e[i] do
                if avail[y] then begin
                    inc(rear);  queue[rear]:=y;
                    avail[y]:=false;
                    c[y]:=c[u]+1;
                    if is_dirty[y] then f[s,y]:=c[y];
                end;
            i:=link[i];
        end;
    until front = rear+1;
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    if a[0] = -1 then exit;
    for i:=1 to N do
        for j:=1 to N do
            f[i,j]:=MAX_INT;
    for i:=0 to nA do BFS(a[i]);
end;
{---------------------------------------------------------------------------}
procedure   try_x(i:longint);
var
    j:longint;
begin
    if i > nA then begin
        if sum < res then res:=sum;
        exit;
    end;
    for j:=1 to nA do
        if avail[a[j]] then begin
            x[i]:=a[j];
            avail[a[j]]:=false;
            sum:=sum+f[x[i-1],x[i]];
            if sum < res then try_x(i+1);
            sum:=sum-f[x[i-1],x[i]];
            avail[a[j]]:=true;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    if nA = 0 then begin
        writeln(fo,0);
        exit;
    end;
    if a[0] = -1 then begin
        writeln(fo,-1);
        exit;
    end;

    res:=MAX_INT;   sum:=0;
    x[0]:=a[0];
    for i:=1 to N do avail[i]:=true;
    try_x(1);

    if res = MAX_INT then res:=-1;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,W,H);
    while W <> 0 do begin
        enter;
        init;
        solve;
        readln(fi,W,H);
    end;
    close(fo);
    close(fi);
end.