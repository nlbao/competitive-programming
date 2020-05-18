{$M+ 16777216}

uses    math;

const   MAX_N = 100005;
        MAX_F = 100005;
        oo = 1000000000;

var fi,fo:text;
    n,i,x,y,t1,t2,u,v,value:longint;
    f:array[0..4*MAX_F] of longint;


procedure   update(k,l,r:longint);
var mid:longint;
begin
    if (l > r) or (l > v) or (r < u) then exit;
    if (u <= l) and (r <= v) then begin
        f[k]:=f[k]+value;
        exit;
    end;
    mid:=(l+r) shr 1;
    update(k shl 1,l,mid);
    update((k shl 1)+1,mid+1,r);
end;

function    get(k,l,r,pos:longint):longint;
var mid:longint;
begin
    if (l > r) or (l > pos) or (r < pos) then exit(0);
    if l = r then exit(f[k]);
    mid:=(l+r) shr 1;
    exit(get(k shl 1,l,mid,pos) + get((k shl 1)+1,mid+1,r,pos) + f[k]);
end;


procedure   up(x,y,t:longint);
begin
    if x > y then exit;
    u:=x;   v:=y;
    value:=t;
    update(1,1,MAX_F);
end;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'cvjetici.in');    reset(fi);
    assign(fo,'cvjetici.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    fillchar(f,sizeof(f),0);
    for i:=1 to n do begin
        read(fi,x,y);
        t1:=get(1,1,MAX_F,x);
        t2:=get(1,1,MAX_F,y);
        writeln(fo,t1+t2);
        up(x,x,-t1);
        up(y,y,-t2);
        up(x+1,y-1,1);
    end;
    close(fi);
    close(fo);
end.