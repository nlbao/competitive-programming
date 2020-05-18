{$M 16777216}
uses    math;

const   MAX_N = 500005;
        oo = 1000000000000000000;

type    ll = int64;

var fi,fo:text;
    n,pos,u,v:longint;
    t,p:array[0..MAX_N] of longint;
    f:array[0..4*MAX_N] of ll;
    value:ll;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,t[i],p[i]);
end;

procedure   update(k,l,r:longint);
var mid:longint;
begin
    if (l > v) or (r < u) then exit;
    if (u <= l) and (r <= v) then begin
        f[k]:=min(f[k],value);
        exit;
    end;
    mid:=(l+r) shr 1;
    update(k shl 1,l,mid);
    update((k shl 1)+1,mid+1,r);
end;

function    get(k,l,r:longint):ll;
var mid:longint;
begin
    if (l > pos) or (r < pos) then exit(oo);
    if l = r then exit(f[k]);
    mid:=(l+r) shr 1;
    if pos > mid then exit(min(get((k shl 1)+1,mid+1,r), f[k]))
    else exit(min(get(k shl 1,l,mid), f[k]));
end;

procedure   solve();
var i:longint;
begin
    for i:=1 to 4*n do f[i]:=oo;
    value:=p[1];
    u:=1;   v:=t[1];
    update(1,1,n);

    for i:=2 to n do begin
        pos:=i-1;
        value:=get(1,1,n) + int64(p[i]);
        u:=i;   v:=t[i];
        update(1,1,n);
    end;
    pos:=n;
    writeln(fo,get(1,1,n));
end;

begin
    assign(fi,'HIRE.inp');   reset(fi);
    assign(fo,'HIRE.out');   rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.