const   MAX_N = 100010;

var fi,fo:text;
    n,m,fmax:longint;
    c,s,d,h,x,y,id1,id2:array[0..MAX_N] of longint;
    f:array[0..5*MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort1(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=s[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while s[i] < p do inc(i);
        while s[j] > p do dec(j);
        if i <= j then begin
            swap(s[i],s[j]);
            swap(c[i],c[j]);
            swap(id1[i],id1[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort1(l,j); sort1(i,r);
end;

procedure   sort2(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=h[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while h[i] < p do inc(i);
        while h[j] > p do dec(j);
        if i <= j then begin
            swap(h[i],h[j]);
            swap(d[i],d[j]);
            swap(id2[i],id2[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort2(l,j); sort2(i,r);
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,c[i],s[i]);
        id1[i]:=i;
    end;
    readln(fi,m);
    for i:=1 to m do begin
        read(fi,d[i],h[i]);
        id2[i]:=i;
    end;
end;

function    get_max(i,j:longint):longint;
begin
    if c[i] > c[j] then exit(i);
    if (c[i] = c[j]) and (i < j) then exit(i);
    exit(j);
end;

procedure   update(k,l,r,p:longint; x:boolean);
var mid:longint;
begin
    if (l > r) or (l > p) or (r < p) then exit;
    if l = r then begin
        ok[p]:=x;
        if x then f[k]:=p
        else f[k]:=0;
        exit;
    end;
    mid:=(l+r) shr 1;
    update(k shl 1,l,mid,p,x);
    update((k shl 1)+1,mid+1,r,p,x);
    f[k]:=get_max(f[k shl 1], f[(k shl 1)+1]);
end;

procedure   get(k,l,r,u,v,limit:longint);
var mid:longint;
begin
    if (l > r) or (l > v) or (r < u) then exit;
    if (u <= l) and (r <= v) then begin
        if f[k] = 0 then exit;
        if c[f[k]] <= limit then begin
            fmax:=get_max(fmax,f[k]);
            exit;
        end;
    end;
    mid:=(l+r) shr 1;
    get(k shl 1,l,mid,u,v,limit);
    get((k shl 1)+1,mid+1,r,u,v,limit);
end;

procedure   init;
var i:longint;
begin
    randomize;
    sort1(1,n);
    sort2(1,m);
    c[0]:=-1;
    fillchar(f,sizeof(f),0);
    for i:=1 to n do update(1,1,n,i,true);
end;

procedure   find(x:longint;  var a,b:longint);
var l,r,mid:longint;
begin
    l:=1;   r:=n;   a:=n+1;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if (s[mid] = x) or (s[mid] = x+1) then begin
            a:=mid;
            r:=mid-1;
        end
        else if s[mid] < x then l:=mid+1
        else r:=mid-1;
    end;

    l:=1;   r:=n;   b:=0;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if (s[mid] = x) or (s[mid] = x+1) then begin
            b:=mid;
            l:=mid+1;
        end
        else if s[mid] < x then l:=mid+1
        else r:=mid-1;
    end;
end;

procedure   solve;
var i,a,b,q:longint;
    res:int64;
begin
    res:=0;
    q:=0;
    {a:=1;  b:=0;}

    {for i:=1 to n do writeln(s[i]);
    writeln;}

    for i:=1 to m do begin
        find(h[i],a,b);
        {while (a <= n) and ((s[a] < h[i]) or (s[a] > h[i]+1)) do inc(a);
        while (b < n) and ((s[b+1] = h[i]) or (s[b+1] = h[i]+1)) do inc(b);}
        {if a > n then break;}
        {writeln(h[i],'      ',a,' ',b);}
        if a > b then continue;
        fmax:=0;
        get(1,1,n,a,b,d[i]);
        if fmax > 0 then begin
            res:=res+int64(c[fmax]);
            inc(q);
            x[q]:=id2[i];   y[q]:=id1[fmax];
            update(1,1,n,fmax,false);
        end;
    end;
    writeln(fo,res);
    writeln(fo,q);
    for i:=1 to q do writeln(fo,x[i],' ',y[i]);
end;


begin
    assign(fi,'166D.in');   reset(fi);
    assign(fo,'166D.out');  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.