const   MAX_N = 100010;

type    int = int64;

var fi,fo:text;
    n,nT,tx,ty:longint;
    x,y,z,id,p:array[0..MAX_N] of longint;
    t:array[0..MAX_N] of int;

function    max(x,y:int):int;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   enter;
var i:longint;
begin
    readln(fi,tx,ty,n);
    for i:=1 to n do read(fi,x[i],y[i],z[i]);
    inc(n);
    x[n]:=tx;   y[n]:=ty;   z[n]:=0;
end;

procedure   qsort1(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p1:=x[i];   p2:=y[i];
    i:=l;   j:=r;
    repeat
        while (x[i] < p1) or ((x[i] = p1) and (y[i] < p2)) do inc(i);
        while (x[j] > p1) or ((x[j] = p1) and (y[j] > p2)) do dec(j);
        if i <= j then begin
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            swap(z[i],z[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort1(l,j);    qsort1(i,r);
end;


procedure   qsort2(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=y[id[l+random(r-l+1)]];
    i:=l;   j:=r;
    repeat
        while y[id[i]] < p do inc(i);
        while y[id[j]] > p do dec(j);
        if i <= j then begin
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort2(l,j);    qsort2(i,r);
end;

procedure   init;
var i,j:longint;
begin
    randomize;
    qsort1(1,n);
    for i:=1 to n do id[i]:=i;
    qsort2(1,n);
    i:=1;   nT:=0;
    repeat
        j:=i;   inc(nT);
        while (j <= n) and (y[id[j]] = y[id[i]]) do begin
            p[id[j]]:=nT;
            inc(j);
        end;
        i:=j;
    until i > n;
end;

procedure   update(i:longint;   var value:int);
begin
    if (i > nT) or (value <= t[i]) then exit;
    t[i]:=value;
    update(i+(i and (-i)),value);
end;

function    get(i:longint):int;
begin
    if i < 1 then exit(0);
    exit(max(get(i-(i and (-i))),t[i]));
end;

function    solve:int;
var i:longint;
    tmp,f:int;
begin
    for i:=1 to nT do t[i]:=0;
    i:=1;
    while (i <= n) and ((x[i] < 1) or (y[i] < 1)) do inc(i);
    while i <= n do begin
        if y[i] < 1 then continue;
        tmp:=z[i];
        f:=get(p[i])+tmp;
        if (x[i] = tx) and (y[i] = ty) then exit(f);
        update(p[i],f);
        inc(i);
    end;
end;

begin
    assign(fi,'MBus.in');  reset(fi);
    assign(fo,'MBus.out'); rewrite(fo);
    enter;
    init;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.