const   MAX_N = 100010;
        MAX_M = 100010;

var fi,fo:text;
    n,m,pos,types,d:longint;
    a:array[0..MAX_N] of longint;
    f,g:array[0..4*MAX_M] of longint;

procedure   enter();
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   update(k,l,r:longint);
var mid,left,right:longint;
begin
    if (l > r) or (l > pos) or (r < pos) then exit;
    if l = r then begin
        if types = 0 then f[k]:=f[k]+d
        else g[k]:=g[k]+d;
        exit;
    end;
    mid:=(l+r) shr 1;
    left:=k shl 1; right:=(k shl 1)+1;
    update(left,l,mid);
    update(right,mid+1,r);

    f[k]:=f[right];
    g[k]:=g[left];
    if g[right] >= f[left] then g[k]:=g[k]+g[right]-f[left]
    else f[k]:=f[k]+f[left]-g[right];
end;

procedure   up(pp,tt,dd:longint);
begin
    pos:=pp;    types:=tt;  d:=dd;
    update(1,1,m);
end;

function    solve():longint;
var i,mid,res:longint;
begin
    if n = 1 then exit(-1);
    fillchar(f,sizeof(f),0);
    fillchar(g,sizeof(g),0);
    res:=-1;
    up(a[1],0,1);
    up(a[2],1,1);
    if f[1] = 0 then res:=1;
    for i:=2 to (n div 2) do begin
        up(a[i],0,1);
        up(a[i],1,-1);
        up(a[2*i-1],1,1);
        up(a[2*i],1,1);
        if f[1] = 0 then res:=i;
    end;
    exit(res);

    {mid:=n div 2;
    for i:=1 to mid do up(a[i],0,1);
    for i:=mid+1 to 2*mid do up(a[i],1,1);
    if f[1] = 0 then exit(mid);
    for i:=mid-1 downto 1 do begin
        up(a[i+1],0,-1);
        up(a[i+1],1,1);
        up(a[2*i+1],1,-1);
        up(a[2*i+2],1,-1);
        if f[1] = 0 then exit(i);
    end;
    exit(-1);}
end;

begin
    assign(fi,'c11doll.in');    reset(fi);
    assign(fo,'c11doll.out');   rewrite(fo);
    enter();
    writeln(fo,solve());
    close(fo);
    close(fi);
end.