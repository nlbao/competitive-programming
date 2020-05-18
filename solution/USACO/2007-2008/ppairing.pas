const   MAX_N = 100010;
        MAX_C = MAX_N;

var fi,fo:text;
    n,m,top,i,j,u,v:longint;
    a,h:array[0..MAX_N] of longint;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

function    cmp(i,j:longint):longint;   begin   exit(a[h[i]]-a[h[j]]);    end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) >= 0) then exit;
    swap(h[i],h[j]);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) > 0) then inc(j);
    if (j > top) or (cmp(j,i) <= 0) then exit;
    swap(h[i],h[j]);
    down_heap(j);
end;

procedure   push(u:longint);
begin
    if a[u] = 0 then exit;
    inc(top);
    h[top]:=u;
    up_heap(top);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    h[1]:=h[top];
    dec(top);
    down_heap(1);
end;

begin
    assign(fi,'ppairing.in');   reset(fi);
    assign(fo,'ppairing.out');  rewrite(fo);
    top:=0;
    readln(fi,n,m);
    for i:=1 to m do begin
        read(fi,a[i]);
        push(i);
    end;

    for u:=1 to m do
        for i:=1 to a[u] do begin
            v:=u;
            while v <= u do pop(v);
            writeln(fo,u,' ',v);
            dec(a[v]);
            push(v);
        end;
    close(fo);
    close(fi);
end.