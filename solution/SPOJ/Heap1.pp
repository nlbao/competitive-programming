const
    INPUT = 'Heap1.inp';
    OUTPUT = 'Heap1.out';
    MAX_N = 20000;

var
    fi,fo:text;
    T,N,HeapSize,i:longint;
    Heap:array[1..MAX_N] of int64;

{---------------------------------------------------------------------------}
procedure   UpHeap(i:longint);
var
    r:longint;
    tmp:int64;
begin
    tmp:=Heap[i];
    r:=i div 2;
    while (r > 0) and (Heap[r] > tmp) do begin
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
    tmp:int64;
begin
    tmp:=Heap[i];
    c:=2*i;
    while c <= HeapSize do begin
        if (c < HeapSize) and (Heap[c+1] < Heap[c]) then c:=c+1;
        if Heap[c] >= tmp then break;
        Heap[i]:=Heap[c];
        i:=c;
        c:=2*i;
    end;
    Heap[i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   Push(x:longint);
begin
    inc(HeapSize);
    Heap[HeapSize]:=x;
    UpHeap(HeapSize);
end;
{---------------------------------------------------------------------------}
function    Pop:longint;
begin
    Pop:=Heap[1];
    Heap[1]:=Heap[HeapSize];
    dec(HeapSize);
    DownHeap(1);
end;
{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,x:longint;
begin
    HeapSize:=0;
    read(fi,N);
    for i:=1 to N do begin
        read(fi,x);
        Push(x);
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i:longint;
    x,y,Res:int64;
begin
    Res:=0;
    if N = 1 then Res:=Pop;
    for i:=1 to N-1 do begin
        x:=Pop; y:=Pop;
        Res:=Res+x+y;
        Push(x+y);
    end;
    writeln(fo,Res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,T);
    for i:=1 to T do begin
        Enter;
        Solve;
    end;
    close(fo);
    close(fi);
end.