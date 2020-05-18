const
    INPUT = 'Roads.inp';
    OUTPUT = 'Roads.out';
    MAX_N = 100;
    MAX_M = 10000;
    MAX_K = 10000;

type
    recE = record
        u,v,d,c:longint;
    end;
    recAdj = record
        v,d,c:longint;
    end;

var
    fi,fo:text;
    T,i,N,M,K,sD,sC,Res:longint;
    fHead,rHead:array[1..MAX_N+1] of longint;
    fAdj,rAdj:array[1..MAX_M] of recAdj;
    avail:array[1..MAX_N] of boolean;
    minC:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    E:array[1..MAX_M] of recE;
begin
    readln(fi,K);
    readln(fi,N);
    readln(fi,M);
    for i:=1 to N+1 do
        begin
            fHead[i]:=0;
            rHead[i]:=0;
        end;
    for i:=1 to M do
        begin
            readln(fi,E[i].u,E[i].v,E[i].d,E[i].c);
            inc(fHead[E[i].u]); inc(rHead[E[i].v]);
        end;
    for i:=2 to N+1 do
        begin
            fHead[i]:=fHead[i]+fHead[i-1];
            rHead[i]:=rHead[i]+rHead[i-1];
        end;
    for i:=1 to M do
        begin
            fAdj[fHead[E[i].u]].v:=E[i].v;  fAdj[fHead[E[i].u]].d:=E[i].d;  fAdj[fHead[E[i].u]].c:=E[i].c;
            dec(fHead[E[i].u]);
            rAdj[rHead[E[i].v]].v:=E[i].u;  rAdj[rHead[E[i].v]].d:=E[i].d;  rAdj[rHead[E[i].v]].c:=E[i].c;
            dec(rHead[E[i].v]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   Dijkstra;
var
    i,u,v,tmp:longint;
begin
    for i:=1 to N do
        begin
            avail[i]:=true;
            minC[i]:=MAXLONGINT;
        end;
    minC[N]:=0;
    repeat
        u:=-1;  tmp:=MAXLONGINT;
        for i:=1 to N do
            if (avail[i]) and (minC[i] < tmp) then
                begin
                    tmp:=minC[i];
                    u:=i;
                end;
        if u = -1 then break;
        avail[u]:=false;
        for i:=rHead[u]+1 to rHead[u+1] do
            begin
                v:=rAdj[i].v;
                if avail[v] then
                    begin
                        tmp:=minC[u]+rAdj[i].c;
                        if tmp < minC[v] then minC[v]:=tmp;
                    end;
            end;
    until u = -1;
end;
{---------------------------------------------------------------------------}
procedure   Visit(u:longint);
var
    i,v:longint;
begin
    writeln(u);
    if u = N then
        begin
            if (sD < Res) and (sC <= K) then Res:=sD;
            exit;
        end;
    avail[u]:=false;
    for i:=fHead[u]+1 to fHead[u+1] do
        begin
            v:=fAdj[i].v;
            sD:=sD+fAdj[i].d;   sC:=sC+fAdj[i].c;
            if (avail[v]) and (minC[v] <> MAXLONGINT) then
                if (sD < Res) and (sC+minC[v] <= K) then Visit(v);
            sD:=sD-fAdj[i].d;   sC:=sC-fAdj[i].c;
        end;
    avail[u]:=true;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i:longint;
begin
    for i:=1 to N do avail[i]:=true;
    Res:=MAXLONGINT;
    sD:=0;  sC:=0;
    Visit(1);
    if Res = MAXLONGINT then Res:=-1;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            Enter;
            Dijkstra;
            Solve;
            writeln(fo,Res);
        end;
    close(fo);
    close(fi);
end.