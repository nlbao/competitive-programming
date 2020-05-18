const
    INPUT = 'BallGame.inp';
    OUTPUT = 'BallGame.out';
    MAX_N = 100000;
    MAX_M = 100000;

type
    recQ = record
        turn:char;
        start,time:longint;
    end;
    recRes = record
        turn:char;
        hole:longint;
    end;

var
    fi,fo:text;
    N,M,check,crrTime,turnA,turnB:longint;
    Q:array[1..MAX_M] of recQ;
    nHeap:array[1..3] of longint;
    heap:array[1..3,1..MAX_N] of longint;
    H:array[1..MAX_N] of longint;
    avail:array[1..MAX_N] of boolean;
    Res:array[1..MAX_M] of recRes;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,tmp:longint;
begin
    readln(fi,N,M);
    for i:=1 to M do begin
        readln(fi,Q[i].turn,Q[i].start,tmp);
        Q[i].time:=Q[i].start+tmp;
    end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p:longint;
    tmp:recQ;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=Q[(i+j) div 2].start;
    repeat
        while Q[i].start < p do inc(i);
        while Q[j].start > p do dec(j);
        if i <= j then begin
            tmp:=Q[i]; Q[i]:=Q[j];  Q[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   up_heap(i,k:longint);
var
    r,tmp:longint;
begin
    tmp:=heap[k][i];
    r:=i div 2;
    while r > 0 do begin
        case k of
            1: if heap[k][r] <= tmp then break;
            2: if heap[k][r] >= tmp then break;
            3: if H[heap[k][r]] <= H[tmp] then break;
        end;
        heap[k][i]:=heap[k][r];
        i:=r;
        r:=i div 2;
    end;
    heap[k][i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   down_heap(i,k:longint);
var
    c,tmp:longint;
begin
    tmp:=heap[k][i];
    c:=i*2;
    while c <= nHeap[k] do begin
        case k of
            1: begin
                if (c < nHeap[k]) and (heap[k][c+1] < heap[k][c]) then inc(c);
                if heap[k][c] >= tmp then break;
            end;
            2: begin
                if (c < nHeap[k]) and (heap[k][c+1] > heap[k][c]) then inc(c);
                if heap[k][c] <= tmp then break;
            end;
            3: begin
                if (c < nHeap[k]) and (H[heap[k][c+1]] < H[heap[k][c]]) then inc(c);
                if H[heap[k][c]] >= H[tmp] then break;
            end;
        end;
        heap[k][i]:=heap[k][c];
        i:=c;
        c:=2*i;
    end;
    heap[k][i]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   push(i,k:longint);
begin
    inc(nHeap[k]);
    heap[k][nHeap[k]]:=i;
    up_heap(nHeap[k],k);
    if k = 3 then avail[i]:=false
    else avail[i]:=true;
end;
{---------------------------------------------------------------------------}
function    pop(k:longint):longint;
begin
    pop:=heap[k][1];
    heap[k][1]:=heap[k][nHeap[k]];
    dec(nHeap[k]);
    down_heap(1,k);
    if k = 3 then avail[pop]:=true
    else avail[pop]:=false;
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j:longint;
begin
    quick_sort(1,M);
    for i:=1 to 3 do nHeap[i]:=0;
    for i:=1 to N do begin
        H[i]:=-1;
        avail[i]:=true;
        push(i,1);
        push(i,2);
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,count:longint;
begin
    crrTime:=0;
    turnA:=0;   turnB:=0;
    count:=0;
    for i:=1 to M do begin
        crrTime:=Q[i].start;
        while (nHeap[3] > 0) and (H[heap[3][1]] <= crrTime) do begin
            j:=pop(3);
            H[j]:=-1;
            push(j,1);
            push(j,2);
        end;
        inc(count);
        if Q[i].turn = 'A' then begin
            inc(turnA);
            while (nHeap[1] > 0) and (not avail[heap[1][1]]) do pop(1);
            if nHeap[1] = 0 then begin
                check:=-1;
                exit;
            end;
            j:=pop(1);
            Res[count].turn:='A';
        end
        else begin
            inc(turnB);
            while (nHeap[2] > 0) and (not avail[heap[2][1]]) do pop(2);
            if nHeap[2] = 0 then begin
                check:=1;
                exit;
            end;
            j:=pop(2);
            Res[count].turn:='B';
        end;
        H[j]:=Q[i].time;
        push(j,3);
        Res[count].hole:=j;
    end;
    check:=0;
    crrTime:=Q[1].time;
    for i:=2 to M do
        if Q[i].time > crrTime then
            crrTime:=Q[i].time;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i:longint;
begin
    if check = 0 then begin
        writeln(fo,'DRAW');
        writeln(fo,'Game lasts: ',crrTime);
        for i:=1 to M do
            if Res[i].turn = 'A' then writeln(fo,'Alice takes the hole: ',Res[i].hole)
            else writeln(fo,'Bob takes the hole: ',Res[i].hole);
    end
    else begin
        if check = -1 then writeln(fo,'Alice loses at her turn: ',turnA)
        else writeln(fo,'Bob loses at his turn: ',turnB);
        writeln(fo,'Game lasts: ',crrTime,' minute(s)');
    end;
end;
{---------------------------------------------------------------------------}
begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Init;
    Solve;
    Print_result;
    close(fo);
    close(fi);
end.