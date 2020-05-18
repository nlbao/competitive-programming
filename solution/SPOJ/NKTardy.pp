const   MAX_N = 100010;

var fi,fo:text;
    n,m,top:longint;
    a,b,id,x,h:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=b[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while b[i] < p do inc(i);
        while b[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do begin
        read(fi,b[i]);
        id[i]:=i;
    end;
    randomize;
    qsort(1,n);
end;

function    cmpH(x,y:longint):longint;   begin   exit(a[h[x]]-a[h[y]]);  end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmpH(j,i) >= 0) then exit;
    swap(h[j],h[i]);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmpH(j+1,j) > 0) then inc(j);
    if (j > top) or (cmpH(j,i) <= 0) then exit;
    swap(h[j],h[i]);
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
    h[1]:=h[top];
    dec(top);
    down_heap(1);
end;

procedure   solve;
var i,j,t:longint;
begin
    for i:=1 to n do ok[i]:=true;
    m:=0;   t:=0;   top:=0;
    for i:=1 to n do begin
        push(i);
        t:=t+a[i];
        if t > b[i] then begin
            if top = 0 then break;
            pop(j); ok[j]:=false;
            t:=t-a[j];
            inc(m); x[m]:=j;
        end;
    end;
    writeln(fo,m);
    for i:=1 to n do
        if ok[i] then write(fo,id[i],' ');
    for i:=1 to m do write(fo,id[x[i]],' ');
end;

begin
    assign(fi,'NKTardy.in');    reset(fi);
    assign(fo,'NKTardy.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.