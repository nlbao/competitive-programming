const
    INPUT = 'PCycle.inp';
    OUTPUT = 'PCycle.out';
    MAX_N = 200;
    MAX_M = sqr(MAX_N);
    MAX = MAX_M*10000+1;

var
    fi,fo:text;
    N,M,sW,top,count,pos:longint;
    W:array[1..MAX_N,1..MAX_N] of longint;
    deg:array[1..MAX_N] of longint;
    stack,A,F:array[1..2*MAX_M] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,u,v:longint;
begin
    readln(fi,N,M);
    for u:=1 to N do begin
        for v:=1 to N do W[u,v]:=MAX;
        deg[u]:=0;
    end;
    sW:=0;
    for i:=1 to M do begin
        readln(fi,u,v,W[u,v]);
        W[v,u]:=W[u,v];
        sW:=sW+W[u,v];
        inc(deg[u]);    inc(deg[v]);
    end;
end;
{---------------------------------------------------------------------------}
function    check:boolean;
var
    i:longint;
begin
    if sW < 0 then exit(false);
    for i:=1 to N do
        if deg[i] mod 2 = 1 then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   Find_Euler_cycle;
var
    u,v:longint;
    avail:array[1..MAX_N,1..MAX_N] of boolean;
begin
    for u:=1 to N do
        for v:=1 to N do
            if W[u,v] = MAX then avail[u,v]:=false
            else avail[u,v]:=true;
    top:=1;
    stack[1]:=1;
    count:=0;
    repeat
        u:=stack[top];
        for v:=1 to N do
            if avail[u,v] then begin
                avail[u,v]:=false;  avail[v,u]:=false;
                inc(top);
                stack[top]:=v;
                break;
            end;
        if u = stack[top] then begin
            inc(count);
            A[count]:=stack[top];
            dec(top);
        end;
    until top = 0;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,tmp:longint;
begin
    count:=-1;
    if check = false then exit;

    Find_Euler_cycle;
    F[1]:=0;    tmp:=0;
    pos:=1;
    for i:=2 to count do begin
        F[i]:=F[i-1]+W[A[i-1],A[i]];
        if F[i] < tmp then begin
            tmp:=F[i];
            pos:=i;
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i:longint;
begin
    if count = -1 then writeln(fo,-1)
    else begin
        for i:=pos to count do write(fo,A[i],' ');
        for i:=2 to pos do write(fo,A[i],' ');
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    Print_result;
    close(fo);
    close(fi);
end.
