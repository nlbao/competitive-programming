const
    INPUT = 'KMIN.inp';
    OUTPUT = 'KMIN.out';
    MAX_M = 50000;

type
    recHeap = record
        id,s:longint;
    end;
    arr = array[1..MAX_M] of longint;

var
    M,N,K,HeapSize:longint;
    A,B,next:arr;
    Heap:array[1..MAX_M] of recHeap;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,M,N,K);
    for i:=1 to M do read(fi,A[i]);
    for i:=1 to N do read(fi,B[i]);
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Quick_sort(var X:arr;   l,r:longint);
var
    i,j,p,tmp:longint;
begin
    i:=l;   j:=r;
    p:=X[(i+j) div 2];
    repeat
        while X[i] < p do inc(i);
        while X[j] > p do dec(j);
        if i <= j then
            begin
                tmp:=X[i];  X[i]:=X[j]; X[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(X,l,j);
    if i < r then Quick_sort(X,i,r);
end;
{---------------------------------------------------------------------------}
function    sum(i:longint):longint;
begin
    exit(A[i]+B[next[i]]);
end;
{---------------------------------------------------------------------------}
procedure   UpHeap(i:longint);
var
    r:longint;
    tmp:recHeap;
begin
    tmp:=Heap[i];
    r:=i div 2;
    while (r > 0) and (Heap[r].s > tmp.s) do
        begin
            Heap[i]:=Heap[r];
            i:=r;
            r:=i div 2;
        end;
    Heap[i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   DownHeap(i:longint);
var
    c:longint;
    tmp:recHeap;
begin
    tmp:=Heap[i];
    c:=2*i;
    while c <= HeapSize do
        begin
            if (c < HeapSize) and (Heap[c+1].s < Heap[c].s) then inc(c);
            if Heap[c].s >= tmp.s then break;
            Heap[i]:=Heap[c];
            i:=c;
            c:=2*i;
        end;
    Heap[i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   Push(X:longint);
begin
    inc(HeapSize);
    Heap[HeapSize].id:=X;
    Heap[HeapSize].s:=sum(X);
    UpHeap(HeapSize);
end;
{---------------------------------------------------------------------------}
function    Pop:recHeap;
begin
    Pop:=Heap[1];
    Heap[1]:=Heap[HeapSize];
    dec(HeapSize);
    DownHeap(1);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    Quick_sort(A,1,M);
    Quick_sort(B,1,N);
    for i:=1 to M do next[i]:=1;
    HeapSize:=0;
    for i:=1 to M do Push(i);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    fo:text;
    i:longint;
    tmp:recHeap;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to K do
        begin
            tmp:=Pop;
            writeln(fo,tmp.s);
            if next[tmp.id] < N then
                begin
                    inc(next[tmp.id]);
                    Push(tmp.id);
                end;
        end;
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Init;
    Solve;
end.