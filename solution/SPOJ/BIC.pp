const
    INPUT = 'BIC.inp';
    OUTPUT = 'BIC.out';
    MAX_N = 10000;
    MAX_M = 100000;
    modun = 1000000000;

type
    recE = record
        u,v:longint;
    end;

var
    fi,fo:text;
    N,M,nComponent,StackSize:longint;
    E:array[1..MAX_M] of recE;
    head,newHead:array[1..MAX_N+1] of longint;
    adj,newAdj:array[1..MAX_M] of longint;
    stack,C,sumC,list:array[1..MAX_N] of longint;
    to2:array[1..MAX_N] of boolean;
    Res:string;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to M do
        begin
            read(fi,E[i].u,E[i].v);
            inc(head[E[i].u]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;
            dec(head[E[i].u]);
        end;
end;
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
procedure   NewGraph;
var
    i,count:longint;
    number,low:array[1..MAX_N] of longint;
    avail:array[1..MAX_N] of boolean;

    procedure   Tarjan(u:longint);
    var
        i,v:longint;
    begin
        Push(u);
        inc(count);
        number[u]:=count;   low[u]:=count;
        for i:=head[u]+1 to head[u+1] do
            begin
                v:=adj[i];
                if avail[v] then
                    if number[v] = -1 then
                        begin
                            Tarjan(v);
                            low[u]:=min(low[u],low[v]);
                        end
                    else low[u]:=min(low[u],number[v]);
            end;
        if low[u] = number[u] then
            begin
                inc(nComponent);
                i:=0;
                repeat
                    v:=Pop;
                    C[v]:=nComponent;
                    inc(i);
                until v = u;
                sumC[nComponent]:=i;
            end;
        avail[u]:=false;
    end;
begin
    for i:=1 to N do
        begin
            avail[i]:=true;
            number[i]:=-1;
        end;
    nComponent:=0;
    count:=0;
    StackSize:=0;
    Tarjan(1);
    for i:=1 to nComponent+1 do newHead[i]:=0;
    for i:=1 to M do
        if C[E[i].u] <> C[E[i].v] then
            inc(newHead[C[E[i].u]]);
    for i:=2 to nComponent+1 do newHead[i]:=newHead[i]+newHead[i-1];
    for i:=1 to M do
        if C[E[i].u] <> C[E[i].v] then
            begin
                newAdj[newHead[C[E[i].u]]]:=C[E[i].v];
                dec(newHead[C[E[i].u]]);
            end;
end;
{---------------------------------------------------------------------------}
procedure   TopoSorting;
var
    i,count:longint;
    avail:array[1..MAX_N] of boolean;

    procedure   DFSVisit(u:longint);
    var
        i,v:longint;
    begin
        avail[u]:=false;
        for i:=newHead[u]+1 to newHead[u+1] do
            begin
                v:=newAdj[i];
                if avail[v] then DFSVisit(v);
                to2[u]:=to2[u] or to2[v];
            end;
        list[count]:=u;
        dec(count);
    end;
begin
    count:=nComponent;
    for i:=1 to nComponent do
        begin
            avail[i]:=true;
            to2[i]:=false;
            list[i]:=-1;
        end;
    to2[C[2]]:=true;
    DFSVisit(C[1]);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,u,v:longint;
    F:array[1..MAX_N] of int64;
    print:boolean;
begin
    Res:='';
    print:=false;
    for i:=1 to nComponent do F[i]:=0;
    F[C[1]]:=1;
    for i:=1 to nComponent do
        if list[i] <> -1 then
            begin
                u:=list[i];
                if to2[u] = true then
                    begin
                        if sumC[u] > 1 then
                            begin
                                Res:='inf';
                                break;
                            end;
                        for j:=newHead[u]+1 to newHead[u+1] do
                            begin
                                v:=newAdj[j];
                                F[v]:=F[v]+F[u];
                                if F[v] >= modun then print:=true;
                                F[v]:=F[v] mod modun;
                            end;
                    end;
            end;
    if Res <> 'inf' then
        begin
            str(F[C[2]],Res);
            if print = true then
                while length(Res) < 9 do Res:='0'+Res;
        end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    NewGraph;
    TopoSorting;
    Solve;
    writeln(fo,Res);
    close(fo);
    close(fi);
end.
