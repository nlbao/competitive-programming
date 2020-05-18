{$R+, $I+}
{$M 16777216}

uses    math;

const
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;


procedure   enter();
var i:longint;
begin
    readln(fi,x0,y0,x1,y1);
    for i:=1 to n do
        read(fi,r[i],a[i],b[i]);
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=r[i];   p2:=a[i];
    i:=l;   j:=r;
    repeat
        while (r[i] < p1) or ((r[i] = p1) and (a[i] < p1)) do inc(i);
        while (r[j] > p2) or ((r[j] = p2) and (a[j] > p1)) do dec(j);
        if i <= j then begin
            swap(r[i],r[j]);
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

procedure   add_edge(u,v:longint);
begin
    if u = v then exit;
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
    inc(deg[u]);
end;


procedure   init();
begin
    randomize;
    sort(1,n);
    m:=0;
    i:=1;
    while i <= n do begin
        j:=i;
        while (j < n) and (r[j+1] = r[i]) and (a[j+1] <= b[i]+1) do begin
            inc(j);
            b[i]:=max(b[i],b[j]);
        end;
        m:=m+j-i;
        r[i-m]:=r[i];
        a[i-m]:=a[i];
        b[i-m]:=b[i];
        i:=j+1;
    end;
    n:=m;

    nE:=0;  m:=0;
    pi:=1;  pj:=0;
    fillchar(head,sizeof(head),0);
    i:=1;
    while i <= n do begin
        j:=i;
        while (j <= n) and (r[j] = r[i]) do begin
            for k:=a[j] to b[j] do begin
                inc(m);
                t:=find(k,pi,pj);
                if t > 0 then begin
                    add_edge(
                end;
            end;
            j:=j+1;
        end;
        last
        pi:=i;  pj:=j-1;
        i:=j;
    end;
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'.in');    reset(fi);
    assign(fo,'.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fi);
    close(fo);
end.

