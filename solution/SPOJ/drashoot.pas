uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

var fi,fo:text;
    n,m,pos,x,y,posL,posR:longint;
    a:array[0..MAX_N] of longint;
    f,g:array[0..4*MAX_N] of longint;


procedure   init(k,l,r:longint);
var mid,left,right:longint;
begin
    if l > r then exit;
    if l = r then begin
        g[k]:=1;
        f[k]:=a[l];
        exit;
    end;
    mid:=(l+r) shr 1;
    left:=k shl 1;
    right:=left+1;
    init(left,l,mid);
    init(right,mid+1,r);
    g[k]:=g[left]+g[right];
    f[k]:=max(f[left],f[right]);
end;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);
    init(1,1,n);
end;


procedure   update(k,l,r,s:longint);
var mid,left,right,t:longint;
begin
    if (l > r) or (s > pos) then exit;
    if l = r then begin
        g[k]:=0;
        f[k]:=-1;
        exit;
    end;
    mid:=(l+r) shr 1;
    left:=k shl 1;
    right:=left+1;
    t:=s+g[left];
    if t < pos then update(right,mid+1,r,t)
    else update(left,l,mid,s);
    g[k]:=g[left]+g[right];
    f[k]:=max(f[left],f[right]);
end;


function    get(k,l,r:longint):longint;
var mid:longint;
begin
    if (l > r) or (l > y) or (r < x) then exit(-1);
    if (x <= l) and (r <= y) then exit(f[k]);
    mid:=(l+r) shr 1;
    exit(max(get(k shl 1,l,mid),get((k shl 1)+1,mid+1,r)));
end;


procedure   find_left(k,l,r,s:longint);
var mid,left,right,t:longint;
begin
    if l > r then exit;
    if l = r then begin
        s:=s+1-g[k];
        if (x <= s) and (s <= y) then
            posL:=min(posL,l);
        exit;
    end;

    mid:=(l+r) shr 1;
    left:=k shl 1;
    right:=left+1;
    t:=s + (mid-l+1)-g[left];

    if t < x then find_left(right,mid+1,r,t)
    else if t > y then find_left(left,l,mid,s)
    else begin
        posL:=min(posL,mid);
        find_left(left,l,mid,s)
    end;
end;


procedure   find_right(k,l,r,s:longint);
var mid,left,right,t:longint;
begin
    if l > r then exit;
    if l = r then begin
        s:=s+1-g[k];
        if (x <= s) and (s <= y) then
            posR:=max(posR,l);
        exit;
    end;

    mid:=(l+r) shr 1;
    left:=k shl 1;
    right:=left+1;
    t:=s + (mid-l+1)-g[left];

    if t < x then find_right(right,mid+1,r,t)
    else if t > y then find_right(left,l,mid,s)
    else begin
        posR:=max(posR,mid);
        find_right(right,mid+1,r,t)
    end;
end;


procedure   solve();
var i,nQ,res:longint;
    ch:char;
begin
    m:=0;
    readln(fi,nQ);
    for i:=1 to nQ do begin
        read(fi,ch);
        if ch = 'S' then begin
            readln(fi,pos);
            update(1,1,n,0);
            m:=m+1;
        end
        else begin
            readln(fi,x,y);
            posL:=oo;   posR:=-1;
            find_left(1,1,n,0);
            find_right(1,1,n,0);

            if posL <= posR then begin
                x:=posL;    y:=posR;
                res:=get(1,1,n);
            end
            else res:=-1;
            if res = -1 then writeln(fo,'NONE')
            else writeln(fo,res);
        end;
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'DRASHOOT.in');    reset(fi);
    assign(fo,'DRASHOOT.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.