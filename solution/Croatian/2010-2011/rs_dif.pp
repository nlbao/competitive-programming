const   INPUT = 'dif.in';
        OUTPUT = 'dif.out';
        MAX_N = 300010;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of int64;
    IT:array[0..8*MAX_N,0..1] of int64;
    smax,smin:int64;

function    maxID(i,j:longint):longint; begin   if a[i] > a[j] then exit(i) else exit(j);   end;

function    minID(i,j:longint):longint; begin   if a[i] < a[j] then exit(i) else exit(j);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   update(i,k,l,r:longint);
var mid:longint;
begin
    if (l > i) or (r < i) then exit;
    if l = r then begin
        IT[k][0]:=i;    IT[k][1]:=i;
        exit;
    end;
    mid:=(l+r) shr 1;
    update(i,k shl 1,l,mid);
    update(i,(k shl 1)+1,mid+1,r);
    IT[k][0]:=maxID(IT[k shl 1][0],IT[(k shl 1)+1][0]);
    IT[k][1]:=minID(IT[k shl 1][1],IT[(k shl 1)+1][1]);
end;

function    get_IT(u,v,k,l,r,types:longint):longint;
var i,j,mid:longint;
begin
    if (l > v) or (r < u) then exit(-1);
    if (u <= l) and (r <= v) then exit(IT[k][types]);
    mid:=(l+r) shr 1;
    i:=get_IT(u,v,k shl 1,l,mid,types);
    j:=get_IT(u,v,(k shl 1)+1,mid+1,r,types);
    if i = -1 then exit(j);
    if j = -1 then exit(i);
    if types = 0 then exit(maxID(i,j))
    else exit(minID(i,j));
end;

procedure   cal_max(l,r:int64);
var i:int64;
begin
    if l >= r then exit;
    i:=get_IT(l,r,1,1,n,0);
    smax:=smax+a[i]*(i-l+(i-l+1)*(r-i));
    cal_max(l,i-1);
    cal_max(i+1,r);
end;

procedure   cal_min(l,r:int64);
var i:int64;
begin
    if l >= r then exit;
    i:=get_IT(l,r,1,1,n,1);
    smin:=smin+a[i]*(i-l+(i-l+1)*(r-i));
    cal_min(l,i-1);
    cal_min(i+1,r);
end;

procedure   solve;
var i:longint;
begin
    for i:=1 to n do update(i,1,1,n);
    smax:=0;    smin:=0;
    cal_max(1,n);
    cal_min(1,n);
    writeln(fo,smax-smin);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
