const
    INPUT = 'CIJEVI.inp';
    OUTPUT = 'CIJEVI.out';
    MAX_M = 26;
    MAX_N = 26;

type
    recPoint = record
        x,y:longint;
    end;
    recQueue = record
        front,rear:longint;
        items:array[0..MAX_M*MAX_N] of recPoint;
    end;

var
    fi,fo:text;
    M,N:longint;
    A:array[0..MAX_M,0..MAX_N] of char;
    S,T:recPoint;
    avail:array[0..MAX_M,0..MAX_N] of boolean;
    queue:recQueue;

{---------------------------------------------------------------------------}
procedure   set_point(var p:recPoint;   i,j:longint);   inline;
begin
    p.x:=i;
    p.y:=j;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    for i:=1 to M do begin
        for j:=1 to N do begin
            read(fi,A[i,j]);
            if A[i,j] = 'M' then set_point(S,i,j)
            else
                if A[i,j] = 'Z' then set_point(T,i,j);
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    queue.front:=0; queue.rear:=0;
    for i:=1 to M do
        for j:=1 to N do
            avail[i,j]:=true;
    for i:=0 to M+1 do begin
        A[i,0]:='.';    A[i,N+1]:='.';
        avail[i,0]:=false;
        avail[i,N+1]:=false;
    end;
    for j:=0 to N+1 do begin
        A[0,j]:='.';    A[M+1,j]:='.';
        avail[0,j]:=false;
        avail[M+1,j]:=false;
    end;
end;
{---------------------------------------------------------------------------}
procedure   push_to_queue(i,j:longint); inline;
begin
    with queue do begin
        inc(rear);
        set_point(items[rear],i,j);
    end;
    avail[i,j]:=false;
end;
{---------------------------------------------------------------------------}
function    pop_from_queue:recPoint;    inline;
begin
    with queue do begin
        pop_from_queue:=items[front];
        inc(front);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    u:recPoint;
begin
    push_to_queue(S.x,S.y);
    with queue do
        repeat
            u:=pop_from_queue;
            with u do
                case A[x,y] of
                    'M': begin
                        if A[x-1,y] <> '.' then push_to_queue(x-1,y);
                        if A[x+1,y] <> '.' then push_to_queue(x+1,y);
                        if A[x,y-1] <> '.' then push_to_queue(x,y-1);
                        if A[x,y+1] <> '.' then push_to_queue(x,y+1);
                    end;
                    'T': exit;
                    '|': begin
                        add
                    end;

                    end;
                end;
        until front = rear;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.