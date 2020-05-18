{$M+ 2000000}
uses    math;

const   MAX_N = 100000;
        MAX_A = 1003;

type    pF = ^recF;
        recF = record
            id,value:longint;
            pre,next:pF;
        end;

var fi,fo:text;
    n,m,k:longint;
    x,y,c,id,pos:array[0..MAX_N] of longint;
    f:array[0..MAX_N] of pF;
    root:pF;


procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do
        readln(fi,x[i],y[i],c[i]);
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

function    distance(i,j:longint):longint;   inline;
begin   exit(abs(x[i]-x[j])+abs(y[i]-y[j])); end;


function    cmp(i,j:longint):longint;
begin
    if x[i] < x[j] then exit(-1);
    if x[i] > x[j] then exit(1);
    if y[i] < y[j] then exit(-1);
    if y[i] > y[j] then exit(1);
    exit(0);
end;

procedure   sort(l,r:longint);
var i,j:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    id[0]:=id[i];
    i:=l;   j:=r;
    repeat
        while cmp(id[i],id[0]) < 0 do inc(i);
        while cmp(id[j],id[0]) > 0 do dec(j);
        if i <= j then begin
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

procedure   init();
var i,j:longint;
begin
    for i:=1 to n do id[i]:=i;
    randomize;
    sort(1,n);
    i:=1;   m:=0;
    while i <= n do begin
        j:=i;   inc(m);
        while (j <= n) and (x[id[j]] = x[id[i]]) and (y[id[j]] = y[id[i]]) do begin
            pos[id[j]]:=m;
            inc(j);
        end;
        i:=j;
    end;
end;


procedure   new_node(var p:pF;  i,v:longint);
begin
    new(p);
    p^.id:=i;
    p^.value:=v;
    p^.pre:=nil;
    p^.next:=nil;
end;

function    find(var p:pF):longint;
var q:pF;
begin
    q:=root;
    while q <> nil do begin
        if distance(q^.id,p^.id) <= k then
            exit(q^.value+c[p^.id]);
        q:=q^.next;
    end;
    exit(-1);
end;

procedure   insert(var p:pF);
var q:pF;
begin
    if p^.value >= root^.value then begin
        p^.next:=root;
        root^.pre:=p;
        root:=p;
        exit;
    end;

    q:=root;
    while (q^.next <> nil) and (q^.next^.value > p^.value) do q:=q^.next;
    if q^.next <> nil then begin
        p^.next:=q^.next;
        q^.next^.pre:=p;
    end;
    p^.pre:=q;
    q^.next:=p;
end;

procedure   delete(var p:pF);
begin
    if p^.pre <> nil then p^.pre^.next:=p^.next;
    if p^.next <> nil then p^.next^.pre:=p^.pre;
    dispose(p);
end;


procedure   solve();
var i,u,v,res:longint;
    p:pF;
begin
    res:=0;
    x[0]:=0;    y[0]:=0;    c[0]:=0;
    new_node(root,0,0);
    for i:=1 to m do f[i]:=nil;

    for i:=1 to n do begin
        new_node(p,i,0);
        p^.value:=find(p);

        u:=pos[i];
        if p^.value < 1 then continue;
        if (f[u] <> nil) and (p^.value <= f[u]^.value) then continue;

        insert(p);
        if f[u] <> nil then delete(f[u]);
        f[u]:=p;
        res:=max(res,p^.value);
    end;
    writeln(fo,res);
end;


begin
//{$IFNDEF ONLINE_JUDGE}
    assign(fi,'smartdog.inp');   reset(fi);
    assign(fo,'smartdog.out');   rewrite(fo);
//{$ELSE}
    //assign(fi,'');    reset(fi);
    //assign(fo,'');    rewrite(fo);
//{$ENDIF}
    enter();
    init();
    solve();
    close(fo);
    close(fi);
end.
