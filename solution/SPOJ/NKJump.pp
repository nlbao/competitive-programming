const
    INPUT = 'NKJump.inp';
    OUTPUT = 'NKJump.out';
    MAX_N = 1000;
    MAX_M = 1000000;

type
    recE = record
        u,v:longint;
    end;

var
    N,Res:longint;
    A:array[0..MAX_N+1] of longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    F:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while A[i] < p do inc(i);
        while A[j] > p do dec(j);
        if i <= j then
            begin
                tmp:=A[i];  A[i]:=A[j]; A[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   InitGraph;
var
    M,i,j,k,l,r,mid,tmp:longint;
    E:array[1..MAX_M] of recE;
begin
    Quick_sort(1,N);
    A[0]:=-1;   A[N+1]:=-1;
    M:=0;
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to N-1 do
        for j:=i+1 to N do
            begin
                tmp:=A[i]+A[j];
                l:=1;   r:=N;
                while l <= r do
                    begin
                        mid:=(l+r) div 2;
                        if A[mid] < tmp then l:=mid+1
                        else
                            if A[mid] > tmp then r:=mid-1
                            else break;
                    end;
                if A[mid] = tmp then
                    begin
                        l:=mid; r:=mid;
                        while A[l-1] = tmp do dec(l);
                        while A[r+1] = tmp do inc(r);
                        for k:=l to r do
                            begin
                                inc(M); E[M].u:=i;   E[M].v:=k;
                                inc(M); E[M].u:=j;   E[M].v:=k;
                                inc(head[i]);   inc(head[j]);
                            end;
                    end;
            end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;
            dec(head[E[i].u]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,v:longint;
begin
    F[u]:=0;
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            if F[v] = -1 then DFS(v);
            if F[v] <> 0 then
                F[u]:=max(F[u],F[v]);
        end;
    inc(F[u]);
    Res:=max(Res,F[u]);
end;
{---------------------------------------------------------------------------}
procedure   Find;
var
    i:longint;
begin
    Res:=0;
    for i:=1 to N do F[i]:=-1;
    for i:=1 to N do
        if F[i] = -1 then
            DFS(i);
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{---------------------------------------------------------------------------}
begin
    Enter;
    InitGraph;
    Find;
    Print_result;
end.