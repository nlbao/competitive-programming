const   MAX_N = 100010;

var fi,fo:text;
    n,m,h_size:longint;
    a,b,id,c,pos,h:array[0..MAX_N] of longint;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   qsort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=a[id[l+random(r-l+1)]];
    i:=l;   j:=r;
    repeat
        while a[id[i]] < p do inc(i);
        while a[id[j]] > p do dec(j);
        if i <= j then begin
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   init;
var i,j,k,t:longint;
begin
    for i:=1 to n do id[i]:=i;
    randomize;
    qsort(1,n);
    i:=1;   k:=0;
    repeat
        j:=i;   t:=a[id[i]];
        inc(k); b[k]:=t;
        while (j <= n) and (a[id[j]] = t) do begin
            a[id[j]]:=k;
            inc(j);
        end;
        i:=j;
    until i > n;
end;

procedure   up_heap(i:longint);
var r:longint;
begin
    r:=i shr 1;
    {writeln('                   ',h[r],' ',h[i],' ',cmp(h[r],h[i]),' ',r,' ',i);}
    if (r < 1) or (h[r] >= h[i]) then exit;
    swap(pos[h[r]],pos[h[i]]);
    swap(h[r],h[i]);
    up_heap(r);
end;

procedure   down_heap(i:longint);
var c:longint;
begin
    c:=i shl 1;
    if (c < h_size) and (h[c+1] > h[c]) then inc(c);
    if (c > h_size) or (h[c] <= h[i]) then exit;
    swap(pos[h[c]],pos[h[i]]);
    swap(h[c],h[i]);
    down_heap(c);
end;

procedure   push(x:longint);
var j:longint;
begin
    if pos[x] = -1 then begin
        inc(h_size);
        h[h_size]:=x;
        pos[x]:=h_size;
        up_heap(h_size);
    end
    else begin
        j:=pos[x];
        up_heap(j);
        down_heap(j);
    end;
end;

function    pop(i:longint):longint;
var x:longint;
begin
    if (i < 1) or (i > h_size) then exit(-1);
    x:=h[i];
    pos[x]:=-1;
    h[i]:=h[h_size];
    pos[h[i]]:=i;
    dec(h_size);
    if h_size > 0 then begin
        up_heap(i);
        down_heap(i);
    end;
    exit(x);
end;

procedure   solve;
var i,j:longint;
begin
    for i:=0 to n do begin
        c[i]:=0;
        pos[i]:=-1;
    end;
    h_size:=0;
    for i:=1 to m-1 do inc(c[a[i]]);
    for i:=1 to m-1 do
        if c[a[i]] = 1 then push(a[i]);
    for i:=m to n do begin
        dec(c[a[i-m]]);
        inc(c[a[i]]);
        if i > m then
            if c[a[i-m]] = 1 then push(a[i-m])
            else pop(pos[a[i-m]]);
        if c[a[i]] = 1 then push(a[i])
        else pop(pos[a[i]]);
        {writeln(i,' ',a[i],' ',c[a[i]],' ',j);
        writeln('    ',h_size,' ',h[1],' ',h[2],' ',cmp(h[1],h[2]));
        writeln;}
        if h_size > 0 then writeln(fo,b[h[1]])
        else writeln(fo,'Nothing')
    end;
end;

begin
    assign(fi,'69E.in');    reset(fi);
    assign(fo,'69E.out');   rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.