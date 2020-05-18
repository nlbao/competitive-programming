const   MAX_N = 100010;

var fi,fo:text;
    n,m,nr,maxC,top:longint;
    a,b,c,h:array[0..MAX_N] of longint;
    f:array[1..3,0..MAX_N] of longint;
    r:array[0..MAX_N,1..3] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=a[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   init;
var i,j:longint;
begin
    randomize;
    qsort(1,n);
    i:=1;   m:=0;
    repeat
        j:=i;
        inc(m); b[m]:=a[i]; c[m]:=0;
        while (j <= n) and (a[j] = a[i]) do inc(j);
        c[m]:=j-i;
        i:=j;
    until i > n;
    nr:=0;
end;

procedure   update;
var i,j:longint;
begin
    for i:=1 to maxC do begin
        for j:=1 to 3 do if f[j][i] = 0 then exit;
        inc(nr);
        for j:=1 to 3 do r[nr][j]:=f[j][i];
        if r[nr][1] < r[nr][2] then swap(r[nr][1],r[nr][2]);
        if r[nr][2] < r[nr][3] then swap(r[nr][2],r[nr][3]);
        if r[nr][1] < r[nr][2] then swap(r[nr][1],r[nr][2]);
    end;
end;

function    cmp(x,y:longint):longint;   begin   exit(c[h[x]]-c[h[y]]);  end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) >= 0) then exit;
    swap(h[j],h[i]);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) > 0) then inc(j);
    if (j > top) or (cmp(j,i) <= 0) then exit;
    swap(h[j],h[i]);
    down_heap(j);
end;

procedure   push(u:longint);
begin
    inc(top);
    h[top]:=u;
    up_heap(top);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    h[1]:=h[top];
    dec(top);
    if top > 0 then down_heap(1);
end;

function    solve:longint;
var i,j,k,p:longint;
begin
    top:=0;
    for i:=1 to m do
        if c[i] > 0 then push(i);
    if top = 0 then exit(-1);
    pop(p);
    maxC:=c[p]; c[p]:=0;
    fillchar(f,sizeof(f),0);
    for i:=1 to maxC do f[1][i]:=b[p];
    i:=2;   j:=0;   k:=0;
    repeat
        if (j = 0) or (c[j] = 0) then pop(j);
        while c[j] > 0 do begin
            inc(k); f[i][k]:=b[j];
            dec(c[j]);

            if k = maxC then break;
        end;
        if k = maxC then begin
            inc(i);
            k:=0;
        end;
    until (i > 3) or (top < 1);
    exit(0);
end;

procedure   print;
var i,j:longint;
begin
    writeln(fo,nr);
    for i:=1 to nr do begin
        for j:=1 to 3 do write(fo,r[i][j],' ');
        writeln(fo);
    end;
end;

begin
    assign(fi,'140C.in');   reset(fi);
    assign(fo,'140C.out');  rewrite(fo);
    enter;
    init;
    while solve = 0 do update;
    print;
    close(fo);
    close(fi);
end.