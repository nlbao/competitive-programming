{$N+}

const
    INPUT = 'Bridges.inp';
    OUTPUT = 'Bridges.out';
    MAX_N = 10010;
    MAX_M = 2*MAX_N;

type
    recE = record
        u,v:longint;
        l:double;
    end;

var
    fi,fo:text;
    N,M,K:longint;
    Vp,Vc:double;
    E:array[0..MAX_M] of recE;
    head,nChild,parent:array[0..MAX_N] of longint;
    adj,id:array[0..MAX_M] of longint;
    F:array[0..MAX_M] of double;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,K,Vp,Vc);
    for i:=1 to N+1 do head[i]:=0;
    M:=N-1;
    for i:=1 to M do begin
        readln(fi,E[i].u,E[i].v,E[i].l);
        inc(head[E[i].u]);
        inc(head[E[i].v]);
    end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do begin
        adj[head[E[i].u]]:=E[i].v;
        adj[head[E[i].v]]:=E[i].u;
        dec(head[E[i].u]);    dec(head[E[i].v]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFSVisit(u:longint);
var
    i,v:longint;
begin
    nChild[u]:=1;
    for i:=head[u]+1 to head[u+1] do begin
        v:=adj[i];
        if parent[v] = -1 then begin
            parent[v]:=u;
            DFSVisit(v);
            nChild[u]:=nChild[u]+nChild[v];
        end;
    end;
end;
{---------------------------------------------------------------------------}
function    nhan(x,y:longint):double;
var
    tmp1,tmp2:double;
begin
    tmp1:=x;
    tmp2:=y;
    exit(tmp1*tmp2);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,tmpID:longint;
    p,tmpF:double;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=F[(i+j) div 2];
    repeat
        while F[i] < p do inc(i);
        while F[j] > p do dec(j);
        if i <= j then begin
            tmpF:=F[i]; F[i]:=F[j]; F[j]:=tmpF;
            tmpID:=id[i];   id[i]:=id[j];   id[j]:=tmpID;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=2 to N do parent[i]:=-1;
    parent[1]:=0;
    DFSVisit(1);
    for i:=1 to M do begin
        F[i]:=E[i].l/Vc-E[i].l/Vp;
        if parent[E[i].u] = E[i].v then
            F[i]:=F[i]*nhan(nChild[E[i].u],N-nChild[E[i].u])
        else
            F[i]:=F[i]*nhan(nChild[E[i].v],N-nChild[E[i].v]);
        id[i]:=i;
    end;
    quick_sort(1,M);

    for i:=1 to K do write(fo,id[i],' ');
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
