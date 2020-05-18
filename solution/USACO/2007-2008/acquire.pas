uses    math;

const   MAX_N = 50010;
        oo = 1000000000000000;

type    ll = int64;
        recLine = record
            a,b:ll;
        end;

var fi,fo:text;
    n,top:longint;
    w,h,f:array[0..MAX_N] of ll;
    id:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    lines:array[0..MAX_N] of recLine;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,w[i],h[i]);
end;

procedure   swap(var x,y:ll);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort_w(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=w[i];   p2:=h[i];
    i:=l;   j:=r;
    repeat
        while (w[i] > p1) or ((w[i] = p1) and (h[i] > p2)) do inc(i);
        while (w[j] < p1) or ((w[j] = p1) and (h[j] < p2)) do dec(j);
        if i <= j then begin
            swap(w[i],w[j]);
            swap(h[i],h[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort_w(l,j);
    sort_w(i,r);
end;


procedure   sort_h(l,r:longint);
var i,j,p1,p2,t:longint;
begin
    if l >= r then exit;
    i:=id[l+random(r-l)];
    p1:=h[i];   p2:=w[i];
    i:=l;   j:=r;
    repeat
        while (h[id[i]] > p1) or ((h[id[i]] = p1) and (w[id[i]] > p2)) do inc(i);
        while (h[id[j]] < p1) or ((h[id[j]] = p1) and (w[id[j]] < p2)) do dec(j);
        if i <= j then begin
            t:=id[i];   id[i]:=id[j];   id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort_h(l,j);
    sort_h(i,r);
end;


procedure   init();
var i,j:longint;
begin
    for i:=1 to n do begin
        id[i]:=i;
        ok[i]:=true;
    end;
    randomize;
    sort_w(1,n);
    sort_h(1,n);

    i:=1;   j:=n;
    while (i <= n) and (j > 0) do begin
        while (i <= n) and (not ok[i]) do inc(i);
        if i > n then break;

        while (j > 0) and (id[j] <= i) do dec(j);
        if j = 0 then break;

        if h[id[j]] > h[i] then inc(i)
        else begin
            ok[id[j]]:=false;
            dec(j);
        end;
    end;

    j:=0;
    for i:=1 to n do
        if not ok[i] then inc(j)
        else begin
            w[i-j]:=w[i];
            h[i-j]:=h[i];
        end;
    n:=n-j;
end;


procedure   solve_1();
var i,j:longint;
begin
    f[0]:=0;
    for i:=1 to n do begin
        f[i]:=f[0] + w[1]*h[i];
        for j:=1 to i-1 do
            f[i]:=min(f[i],f[j] + w[j+1]*h[i]);
    end;
    writeln(fo,f[n]);
end;


function    is_bad(x,y,z:recLine):boolean;
begin
    //p1 la giao diem theo toa do x cua 2 duong thang x va y
    //p2 la giao diem theo toa do x cua 2 duong thang y va z
    //bad <--> p1 >= p2
    exit((y.a-z.a)*(y.b-x.b) >= (x.a-y.a)*(z.b-y.b));
end;


procedure   push(aa,bb:ll);
begin
    inc(top);
    lines[top].a:=aa;
    lines[top].b:=bb;
end;


procedure   solve();
var i,j,k,l:longint;
    tmp:ll;
begin
    f[0]:=0;
    l:=1;   top:=0;
    push(w[1],0);
    for i:=1 to n do begin
        l:=1;
        f[i]:=lines[l].a*h[i] + lines[l].b;
        for j:=l+1 to top do begin
            tmp:=lines[j].a*h[i] + lines[j].b;
            if tmp < f[i] then begin
                f[i]:=tmp;
                l:=j;
            end
            else break;
        end;

        if i < n then begin
            push(w[i+1],f[i]);
            while (top-l >= 2) and (is_bad(lines[top-2],lines[top-1],lines[top])) do begin
                lines[top-1]:=lines[top];
                dec(top);
            end;
        end;
    end;
    writeln(fo,f[n]);
end;


begin
    assign(fi,'acquire.in');    reset(fi);
    assign(fo,'acquire.out');   rewrite(fo);
    enter();
    init();
    //solve_1();
    solve();
    close(fo);
    close(fi);
end.
