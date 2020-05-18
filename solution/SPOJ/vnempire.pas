{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 100010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:longint;
        end;

var fi,fo:text;
    n,m,i,r1,r2:longint;
    a,b,c,x,id,p:array[0..MAX_N] of longint;
    e:array[0..4*MAX_N] of recEdge;
    res:ll;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=x[i];
    i:=l;   j:=r;
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            swap(x[i],x[j]);
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


procedure   sort_e(l,r:longint);
var i,j,p:longint;
    t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=e[i].w;
    i:=l;   j:=r;
    repeat
        while e[i].w < p do inc(i);
        while e[j].w > p do dec(j);
        if i <= j then begin
            t:=e[i];
            e[i]:=e[j];
            e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort_e(l,j);
    sort_e(i,r);
end;


procedure   add_edge(u,v,ww:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        w:=ww;
    end;
end;


function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VNEMPIRE.in');    reset(fi);
    assign(fo,'VNEMPIRE.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    for i:=1 to n do read(fi,a[i],b[i],c[i]);

    m:=0;
    randomize;
    for i:=1 to n do begin  id[i]:=i;   x[i]:=a[i]; end;
    sort(1,n);
    for i:=1 to n-1 do add_edge(id[i],id[i+1],abs(x[i]-x[i+1]));


    for i:=1 to n do begin  id[i]:=i;   x[i]:=b[i]; end;
    sort(1,n);
    for i:=1 to n-1 do add_edge(id[i],id[i+1],abs(x[i]-x[i+1]));


    for i:=1 to n do begin  id[i]:=i;   x[i]:=c[i]; end;
    sort(1,n);
    for i:=1 to n-1 do add_edge(id[i],id[i+1],abs(x[i]-x[i+1]));


    //for i:=1 to n do write(x[i],' ');   writeln;
    //for i:=1 to n do write(id[i],' ');  writeln;


    sort_e(1,m);
    res:=0;
    for i:=1 to n do p[i]:=-1;
    for i:=1 to m do with e[i] do begin
        r1:=get_root(x);
        r2:=get_root(y);
        if r1 <> r2 then begin
            res:=res + int64(w);
            p[r1]:=p[r1]+p[r2];
            p[r2]:=r1;
        end;
    end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.

