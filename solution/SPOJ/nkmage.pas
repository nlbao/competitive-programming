{$M 16777216}
uses    math;

const   MAX_N = 1160;
        MAX_M = 1560;
        MAX_K = 16;
        oo = 1000000000000000000;

type    ll = qword;
        recEdge = record
            x,y:longint;
            w:ll;
        end;

var fi,fo:text;
    n,m,k:longint;
    a,p:array[0..MAX_N] of longint;
    e:array[0..MAX_M] of recEdge;
    f,g:array[0..(1 shl MAX_K)] of ll;


procedure   enter();
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
    read(fi,m);
    for i:=1 to m do with e[i] do
        readln(fi,x,y,w);
end;


procedure   sort(l,r:longint);
var i,j:longint;
    p,t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=e[i];
    i:=l;   j:=r;
    repeat
        while e[i].w < p.w do inc(i);
        while e[j].w > p.w do dec(j);
        if i <= j then begin
            t:=e[i];
            e[i]:=e[j];
            e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


function    get_root(u:longint):longint;
begin
    if p[u] < 1 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   union(u,v:longint);
begin
    p[u]:=p[u]+p[v];
    p[v]:=u;
end;


procedure   cal_g();
var i,c,s,mask,r1,r2:longint;
begin
    c:=(1 shl k)-1;
    g[0]:=0;
    for mask:=1 to c do begin
        s:=0;
        for i:=1 to n do
            if (mask shr (a[i]-1)) and 1 = 1 then begin
                p[i]:=-1;
                inc(s);
            end
            else p[i]:=0;

        g[mask]:=0;
        for i:=1 to m do with e[i] do begin
            if (p[x] = 0) or (p[y] = 0) then continue;
            r1:=get_root(x);
            r2:=get_root(y);
            if r1 <> r2 then begin
                g[mask]:=g[mask] + w;
                dec(s);
                if s = 1 then break;
                if p[r1] < p[r2] then union(r1,r2)
                else union(r2,r1);
            end;
        end;
        if s > 1 then g[mask]:=oo;
    end;
end;


procedure   solve();
var i,c,mask:longint;
    tmp:ll;
begin
    cal_g();
    c:=(1 shl k)-1;
    f[0]:=0;
    for mask:=1 to c do begin
        f[mask]:=oo;
        i:=mask;
        while i > 0 do begin
            i:=(i-1) and mask;
            tmp:=f[i] + g[mask xor i];
            if tmp < f[mask] then f[mask]:=tmp;
        end;
    end;
    writeln(fo,f[c]);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'NKMAGE.in');    reset(fi);
    assign(fo,'NKMAGE.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    sort(1,m);
    solve();
    close(fo);
    close(fi);
end.