const
    INPUT = 'MSE07B.inp';
    OUTPUT = 'MSE07B.out';
    MAX_N = 1000001;
    MAX_HEAP_SIZE = 2*MAX_N;

type
    recCustomer = record
        x:longint;  {do uu tien}
        pos:array[1..2] of longint; {vi tri trong heap}
    end;

var
    fi,fo:text;
    a:array[0..MAX_N] of recCustomer;
    heap_size:array[1..2] of longint;
    heap:array[1..2,0..MAX_HEAP_SIZE] of longint;

{---------------------------------------------------------------------------}
procedure   up_heap(i,id:longint);
var
    root,tmp:longint;
begin
    tmp:=heap[id,i];
    root:=i div 2;
    while root >= 1 do begin
        case id of
            1:  if a[heap[id,root]].x < a[tmp].x then break;
            2:  if a[heap[id,root]].x > a[tmp].x then break;
        end;
        heap[id,i]:=heap[id,root];
        a[heap[id,i]].pos[id]:=i;
        i:=root;    root:=i div 2;
    end;
    heap[id,i]:=tmp;
    a[heap[id,i]].pos[id]:=i;
end;
{---------------------------------------------------------------------------}
procedure   down_heap(i,id:longint);
var
    child,tmp:longint;
begin
    tmp:=heap[id,i];
    child:=i*2;
    while child <= heap_size[id] do begin
        case id of
            1: begin
                if (child < heap_size[id]) and (a[heap[id,child+1]].x < a[heap[id,child]].x) then inc(child);
                if a[heap[id,child]].x >= a[tmp].x then break;
            end;
            2: begin
                if (child < heap_size[id]) and (a[heap[id,child+1]].x > a[heap[id,child]].x) then inc(child);
                if a[heap[id,child]].x <= a[tmp].x then break;
            end;
        end;
        heap[id,i]:=heap[id,child];
        a[heap[id,i]].pos[id]:=i;
        i:=child;   child:=i*2;
    end;
    heap[id,i]:=tmp;
    a[heap[id,i]].pos[id]:=i;
end;
{---------------------------------------------------------------------------}
procedure   push(k,id:longint);   inline;
begin
    inc(heap_size[id]);
    heap[id,heap_size[id]]:=K;
    a[k].pos[id]:=heap_size[id];
    up_heap(heap_size[id],id);
end;
{---------------------------------------------------------------------------}
function    pop(i,id:longint):longint;  inline;
begin
    pop:=heap[id,i];
    a[heap[id,i]].pos[id]:=-1;
    heap[id,i]:=heap[id,heap_size[id]];
    a[heap[id,heap_size[id]]].pos[id]:=i;
    dec(heap_size[id]);
    up_heap(i,id);
    down_heap(i,id);
end;
{---------------------------------------------------------------------------}
procedure   init;
begin
    heap_size[1]:=0;
    heap_size[2]:=0;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    types,K,P,res:longint;
begin
    repeat
        read(fi,types);
        if types = 0 then break;
        if types = 1 then begin
            readln(fi,K,P);
            a[K].x:=P;
            push(K,1);
            push(K,2);
        end
        else begin
            if heap_size[1] = 0 then res:=0
            else
                if types = 2 then begin
                    res:=pop(1,2);
                    pop(a[res].pos[1],1);
                end
                else begin
                    res:=pop(1,1);
                    pop(a[res].pos[2],2);
                end;
            writeln(fo,res);
        end;
    until types = 0;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    solve;
    close(fo);
    close(fi);
end.