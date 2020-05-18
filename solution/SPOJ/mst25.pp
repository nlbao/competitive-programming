const   MAX_N = 1010;
        MAX_M = sqr(MAX_N) div 2;

var fi,fo:text;
    n,m:longint;
    x,y,w:array[0..MAX_M] of longint;
    ok:array[0..MAX_N] of boolean;
    p:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to m do begin
        readln(fi,x[i],y[i],w[i]);
        ok[i]:=false;
    end;
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=w[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while w[i] < p do inc(i);
        while w[j] > p do dec(j);
        if i <= j then begin
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            swap(w[i],w[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;

function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   solve;
var i,r1,r2,res:longint;
begin
    randomize;
    sort(1,m);
    for i:=1 to n do p[i]:=-1;
    res:=0;
    for i:=1 to m do begin
        r1:=get_root(x[i]);
        r2:=get_root(y[i]);
        if r1 <> r2 then begin
            res:=res+w[i];
            ok[i]:=true;
            p[r1]:=p[r1]+p[r2];
            p[r2]:=r1;
        end;
    end;
    writeln(fo,res);
    for i:=1 to m do
        if ok[i] then writeln(fo,x[i],' ',y[i]);
end;

begin
    assign(fi,'mst25.in');      reset(fi);
    assign(fo,'mst25.out');     rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.