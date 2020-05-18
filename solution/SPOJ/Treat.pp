const
    INPUT = 'Treat.inp';
    OUTPUT = 'Treat.out';
    MAX_N = 100000;

var
    fi,fo:text;
    N,i,StackSize,count:longint;
    next,F:array[1..MAX_N] of longint;
    Stack,number,low:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Push(u:longint);
begin
    inc(StackSize);
    Stack[StackSize]:=u;
end;
{---------------------------------------------------------------------------}
function    Pop:longint;
begin
    Pop:=Stack[StackSize];
    dec(StackSize);
end;
{---------------------------------------------------------------------------}
procedure   DFSVisit(u:longint);
var
    v:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=count;
    Push(u);
    F[u]:=0;
    v:=next[u];
    if F[v] = -1 then
        begin
            DFSVisit(v);
            low[u]:=min(low[u],low[v]);
        end
    else
        if F[v] = 0 then low[u]:=min(low[u],number[v]);
    F[u]:=F[v]+1;
    if low[u] =number[u] then
        repeat
            v:=Pop;
            F[v]:=F[u];
        until v = u;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,N);
    for i:=1 to N do read(fi,next[i]);
    StackSize:=0;
    for i:=1 to N do F[i]:=-1;
    for i:=1 to N do
        if F[i] = -1 then DFSVisit(i);
    for i:=1 to N do writeln(fo,F[i]);
    close(fo);
    close(fi);
end.