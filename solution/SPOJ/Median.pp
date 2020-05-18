const
    INPUT = 'Median.inp';
    OUTPUT = 'Median.out';
    MAX_N = 250000;
    MAX_K = 5000;

type
    recA = record
        value:longint;
        id:longint;
        heap_id,pos:longint;
    end;

var
    fi,fo:text;
    nTest,N,K,i,heap_id:longint;
    A:array[1..MAX_N] of recA;
    link:array[1..MAX_N] of longint;
    heap_size,nHeap:array[1..2] of longint;
    heap:array[1..2,1..MAX_K] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    seed,mul,add,tmp:int64;
begin
    readln(fi,seed,mul,add,N,K);
    A[1].value:=seed;   A[1].id:=1;
    A[1].heap_id:=0;    A[1].pos:=0;
    for i:=2 to N do begin
        tmp:=A[i-1].value;
        tmp:=(tmp*mul+add) mod 65536;
        A[i].value:=tmp;
        A[i].id:=i;
        A[i].heap_id:=0;    A[i].pos:=0;
    end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j:longint;
    p:longint;
    tmp:recA;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=A[(i+j) div 2].value;
    repeat
        while A[i].value < p do inc(i);
        while A[j].value > p do dec(j);
        if i <= j then begin
            tmp:=A[i]; A[i]:=A[j];  A[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    quick_sort(1,K);
    for i:=1 to N do link[A[i].id]:=i;
    heap_size[1]:=K div 2;    heap_size[2]:=K-(K div 2);
    nHeap[1]:=0;  nHeap[2]:=0;
end;
{---------------------------------------------------------------------------}
procedure   up_heap(i:longint);
var
    r,tmp:longint;
begin
    tmp:=heap[heap_id][i];
    r:=i div 2;
    while r > 0 do begin
        case heap_id of
            1: if A[heap[heap_id][r]].value >= A[tmp].value then break;
            2: if A[heap[heap_id][r]].value <= A[tmp].value then break;
        end;
        heap[heap_id][i]:=heap[heap_id][r];
        A[heap[heap_id][i]].pos:=i;
        i:=r;
        r:=i div 2;
    end;
    heap[heap_id][i]:=tmp;
    A[tmp].pos:=i;
end;
{---------------------------------------------------------------------------}
procedure   down_heap(i:longint);
var
    c,tmp:longint;
begin
    tmp:=heap[heap_id][i];
    c:=2*i;
    while c <= nHeap[heap_id] do begin
        case heap_id of
            1: begin
                if (c < nHeap[heap_id]) and (A[heap[heap_id][c+1]].value >= A[heap[heap_id][c]].value) then inc(c);
                if A[heap[heap_id][c]].value <= A[tmp].value then break;
            end;
            2: begin
                if (c < nHeap[heap_id]) and (A[heap[heap_id][c+1]].value <= A[heap[heap_id][c]].value) then inc(c);
                if A[heap[heap_id][c]].value >= A[tmp].value then break;
            end;
        end;
        heap[heap_id][i]:=heap[heap_id][c];
        A[heap[heap_id][i]].pos:=i;
        i:=c;
        c:=2*i;
    end;
    heap[heap_id][i]:=tmp;
    A[tmp].pos:=i;
end;
{---------------------------------------------------------------------------}
procedure   push(i,j:longint);
begin
    heap_id:=j;
    inc(nHeap[j]);
    heap[j][nHeap[j]]:=i;
    A[i].heap_id:=j;
    A[i].pos:=nHeap[j];
    up_heap(nHeap[j]);
end;
{---------------------------------------------------------------------------}
function    pop(i,j:longint):longint;
begin
    heap_id:=j;
    pop:=i;
    heap[j][A[i].pos]:=heap[j][nHeap[j]];
    A[heap[j][nHeap[j]]].pos:=A[i].pos;
    dec(nHeap[j]);
    down_heap(A[i].pos);
    up_heap(A[i].pos);
    A[i].heap_id:=0;
    A[i].pos:=0;
end;
{---------------------------------------------------------------------------}
procedure   Solve(test_id:longint);
var
    i,j:longint;
    tmp,Res:int64;
begin
    for i:=1 to heap_size[1] do push(i,1);
    for i:=heap_size[1]+1 to K do push(i,2);
    Res:=A[heap[(K mod 2)+1][1]].value;

    for i:=K+1 to N do begin
        j:=link[i-K];
        pop(j,A[j].heap_id);

        if A[i].value >= A[heap[1][1]].value then push(i,2)
        else push(i,1);

        if nHeap[1] > heap_size[1] then push(pop(heap[1][1],1),2);
        if nHeap[2] > heap_size[2] then push(pop(heap[2][1],2),1);

        tmp:=A[heap[(K mod 2)+1][1]].value;
        Res:=Res+tmp;
    end;
    writeln(fo,'Case #',test_id,': ',Res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        Enter;
        Init;
        Solve(i);
    end;
    close(fo);
    close(fi);
end.