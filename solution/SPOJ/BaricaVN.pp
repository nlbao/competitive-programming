const   MAX_N = 300010;
        MAX_K = 1010;
        MAX_X = 100010;

var fi,fo:text;
    n,k:longint;
    id,x,y,p,fx,fy:array[0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do begin
        read(fi,x[i],y[i],p[i]);
        id[i]:=i;
    end;
end;

procedure   quick_sort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=id[l+random(r-l+1)];
    p1:=x[i];   p2:=y[i];
    i:=l;   j:=r;
    repeat
        while (x[id[i]] < p1) or ((x[id[i]] = p1) and (y[id[i]] < p2)) do inc(i);
        while (x[id[j]] > p1) or ((x[id[j]] = p1) and (y[id[j]] > p2)) do dec(j);
        if i <= j then begin
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

function    solve:longint;
var i,j,t,u,v,res:longint;
begin
    res:=0;
    randomize;
    quick_sort(1,n);
    for i:=0 to MAX_X do begin
        fx[i]:=0;   fy[i]:=0;
    end;
    j:=1;
    while id[j] <> 1 do inc(j);
    fx[x[1]]:=p[1]; fy[y[1]]:=p[1];
    for i:=j+1 to n do begin
        u:=x[id[i]];    v:=y[id[i]];
        t:=max(fx[u],fy[v]);
        if t >= k then begin
            t:=t+p[id[i]]-k;
            if id[i] = n then exit(t);
            fx[u]:=max(fx[u],t);
            fy[v]:=max(fy[v],t);
        end;
    end;
    exit(0);
end;

begin
    assign(fi,'BaricaVN.in');   reset(fi);
    assign(fo,'BaricaVN.out');  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.
