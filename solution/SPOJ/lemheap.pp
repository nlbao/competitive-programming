const   LIMIT = 15000;

var fi,fo:text;
    n,top,i,j:longint;
    ch:char;
    a,h:array[0..LIMIT] of longint;

procedure   swapH(x,y:longint);
var t:longint;
begin   t:=h[x];    h[x]:=h[y];     h[y]:=t;    end;

function    cmpH(x,y:longint):longint;  begin   exit(h[x]-h[y]);    end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmpH(j,i) >= 0) then exit;
    swapH(j,i);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmpH(j+1,j) > 0) then inc(j);
    if (j > top) or (cmpH(j,i) <= 0) then exit;
    swapH(j,i);
    down_heap(j);
end;

procedure   push(x:longint);
begin
    inc(top);
    h[top]:=x;
    up_heap(top);
end;

procedure   pop(var x:longint);
begin
    x:=h[1];
    swapH(1,top);
    dec(top);
    down_heap(1);
end;


begin
    assign(fi,'lemheap.in');    reset(fi);
    assign(fo,'lemheap.out');   rewrite(fo);
    top:=0;
    while not eof(fi) do begin
        read(fi,ch);
        if ch = '+' then begin
            read(fi,i);
            if top < LIMIT then push(i);
        end
        else
            if top > 0 then begin
                i:=h[1];
                while (top > 0) and (h[1] = i) do pop(i);
            end;
        readln(fi);
    end;
    n:=0;   j:=2000000000;
    while top > 0 do begin
        pop(i);
        if i <> j then begin
            inc(n);
            a[n]:=i;
            j:=i;
        end;
    end;
    writeln(fo,n);
    for i:=1 to n do writeln(fo,a[i]);
    close(fo);
    close(fi);
end.