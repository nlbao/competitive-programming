{$M 16777216}
uses    math;

const   MAX_N = 102;
        MAX_M = 102;
        oo = 1000000000;

var fi,fo:text;
    n,m,top:longint;
    deg,d,h:array[0..MAX_N] of longint;


procedure   enter();
var i:longint;
begin
    read(fi,m,n);
    for i:=1 to n do read(fi,deg[i]);
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

function    cmp(i,j:longint):longint;   begin   exit(d[h[i]]-d[h[j]]);  end;

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
    inc(top);
    h[top]:=u;
    up_heap(top);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    swap(h[1],h[top]);
    dec(top);
    down_heap(1);
end;


function    check():boolean;
var i,u,v:longint;
begin
    top:=0;
    for i:=1 to n do begin
        d[i]:=deg[i];
        if d[i] > 0 then push(i);
    end;

    while top > 1 do begin
        pop(u); dec(d[u]);
        pop(v); dec(d[v]);
        if d[u] > 0 then push(u);
        if d[v] > 0 then push(v);
    end;
    exit(top = 0);
end;


procedure   solve();
var i,res,tmp,pre,nA:longint;
    a,c:array[0..MAX_N] of longint;
    stop:boolean;
begin
    res:=0;
    tmp:=deg[1];
    for i:=0 to tmp-1 do begin
        deg[1]:=i;
        if check() then begin
            res:=tmp-i;
            break;
        end;
    end;
    if res = 0 then begin
        writeln(fo,'NO');
        exit;
    end;

    deg[0]:=0;
    deg[1]:=tmp-res;
    m:=m-res;
    for i:=1 to n do c[i]:=deg[i];

    nA:=0;  pre:=0;
    repeat
        stop:=true;
        for i:=1 to n do if (deg[i] > 0) and (c[i] > 0) then
            if (pre = 0) or (pre = i) then begin
                if check() then begin
                    inc(nA);    a[nA]:=i;
                    pre:=i;
                    dec(c[i]);
                    stop:=false;
                    break;
                end;
            end
            else begin
                dec(deg[i]);
                dec(deg[pre]);
                if check() then begin
                    inc(nA);    a[nA]:=i;
                    dec(c[i]);
                    stop:=false;
                    break;
                end;
                inc(deg[pre]);
                inc(deg[i]);
            end;
        if deg[pre] = 0 then pre:=0;
    until stop;

    writeln(fo,'YES');
    writeln(fo,res);
    for i:=1 to nA do writeln(fo,a[i]);
    for i:=1 to res do writeln(fo,1);
end;


begin
    assign(fi,'gangs.in');    reset(fi);
    assign(fo,'gangs.out');   rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.