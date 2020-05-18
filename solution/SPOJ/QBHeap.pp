const
    INPUT = 'QBHeap.inp';
    OUTPUT = 'QBHeap.out';
    MAX_HEAPSIZE = 15000;

var
    fi,fo:text;
    ch:char;
    V,HeapSize:longint;
    Heap:array[1..MAX_HEAPSIZE] of longint;

{---------------------------------------------------------------------------}
procedure   DownHeap(i:longint);
var
    tmp,child:longint;
begin
    tmp:=Heap[i];
    child:=2*i;
    while child <= HeapSize do
        begin
            if (child < HeapSize) and (Heap[child+1] > Heap[child]) then child:=child+1;
            if Heap[child] <= tmp then break;
            Heap[i]:=Heap[child];
            i:=child;
            child:=2*i;
        end;
    Heap[i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   UpHeap(i:longint);
var
    tmp,root:longint;
begin
    tmp:=Heap[i];
    root:=i div 2;
    while (root > 0) and (Heap[root] < tmp) do
        begin
            Heap[i]:=Heap[root];
            i:=root;
            root:=i div 2;
        end;
    Heap[i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   Push(V:longint);
begin
    if HeapSize = MAX_HEAPSIZE then exit;
    HeapSize:=HeapSize+1;
    Heap[HeapSize]:=V;
    UpHeap(HeapSize);
end;
{---------------------------------------------------------------------------}
function    Pop:longint;
begin
    if HeapSize = 0 then exit(-1);
    Pop:=Heap[1];
    Heap[1]:=Heap[HeapSize];
    HeapSize:=HeapSize-1;
    DownHeap(1);
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i,count:longint;
    Res:array[1..MAX_HEAPSIZE] of longint;
begin
    i:=-MAXLONGINT;  count:=0;
    while HeapSize > 0 do
        begin
            V:=Pop;
            if V <> i then
                begin
                    inc(count);
                    Res[count]:=V;
                    i:=V;
                end;
        end;
    writeln(fo,count);
    for i:=1 to count do write(fo,Res[i],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    HeapSize:=0;
    while not eof(fi) do
        begin
            read(fi,ch);
            if ch = '+' then
                begin
                    readln(fi,V);
                    Push(V);
                end
            else
                begin
                    V:=Heap[1];
                    while (HeapSize > 0) and (Heap[1] = V) do Pop;
                    readln(fi);
                end;
        end;
    Print_result;
    close(fo);
    close(fi);
end.