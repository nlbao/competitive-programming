uses    math;

const   MAX_N = 400010;
        MAX_M = 200010;
        oo = 1000000000;

var fi,fo:text;
    ch:char;
    n,m,i,j,k,t,x,y,c:longint;
    a:array[0..MAX_N] of char;
    s,res,rr:array[0..MAX_N] of longint;
    f,g:array[0..4*MAX_N] of longint;


function    check(l,r:longint):longint;
var i,s:longint;
begin
    s:=0;
    for i:=l to r do begin
        if a[i] = '(' then s:=s+1
        else s:=s-1;
        if s < 0 then exit(0);
    end;
    if s <> 0 then exit(0);
    exit(1);
end;

procedure   init(k,l,r:longint);
var mid:longint;
begin
    if l > r then exit;
    g[k]:=0;
    if l = r then begin
        f[k]:=s[l];
        exit;
    end;
    mid:=(l+r) shr 1;
    init(k shl 1,l,mid);
    init((k shl 1)+1,mid+1,r);
    f[k]:=min(f[k shl 1],f[(k shl 1)+1]);
end;

procedure   update(k,l,r,u,v,value:longint);
var mid,left,right:longint;
begin
    if (l > r) or (l > v) or (r < u) then exit;
    if (u <= l) and (r <= v) then begin
        g[k]:=g[k]+value;
        f[k]:=f[k]+value;
        exit;
    end;
    mid:=(l+r) shr 1;
    left:=k shl 1;  right:=left+1;
    if g[k] <> 0 then begin
        g[left]:=g[left]+g[k];      f[left]:=f[left]+g[k];
        g[right]:=g[right]+g[k];    f[right]:=f[right]+g[k];
        g[k]:=0;
    end;
    update(k shl 1,l,mid,u,v,value);
    update((k shl 1)+1,mid+1,r,u,v,value);
    f[k]:=min(f[k shl 1], f[(k shl 1)+1]);
end;


function    get(k,l,r,i,value:longint):longint;
var mid,left,right,t:longint;
begin
    if (l > r) or (r < i) then exit(MAX_N);
    if l = r then
        if f[k] < value then exit(l)
        else exit(MAX_N);

    mid:=(l+r) shr 1;
    left:=k shl 1;  right:=left+1;
    if g[k] <> 0 then begin
        g[left]:=g[left]+g[k];      f[left]:=f[left]+g[k];
        g[right]:=g[right]+g[k];    f[right]:=f[right]+g[k];
        g[k]:=0;
    end;

    t:=MAX_N;
    if f[left] < value then t:=get(left,l,mid,i,value);
    if (t = MAX_N) and (f[right] < value) then t:=get(right,mid+1,r,i,value);
    exit(t);
end;


function    sub_get(k,l,r,i:longint):longint;
var mid:longint;
begin
    if i < 1 then exit(0);
    if (l > r) or (l > i) or (r < i) then exit(0);
    if l = r then exit(f[k]);
    mid:=(l+r) shr 1;
    exit(sub_get(k shl 1,l,mid,i) + sub_get((k shl 1)+1,mid+1,r,i) + g[k]);
end;


begin
    assign(fi,'nkbracket6.in');  reset(fi);
    assign(fo,'nkbracket6.out'); rewrite(fo);

    readln(fi,n,m);
    fillchar(f,sizeof(f),0);
    fillchar(g,sizeof(g),0);
    s[0]:=0;
    for i:=1 to n do begin
        read(fi,a[i]);
        if a[i] = '(' then s[i]:=s[i-1]+1
        else s[i]:=s[i-1]-1;
    end;
    init(1,1,n);

    c:=0;
    for i:=1 to m do begin
        read(fi,t);
        if t = 0 then begin
            read(fi,j,ch);
            readln(fi,ch);
            if ch <> a[j] then
                if ch = '(' then update(1,1,n,j,n,+2)
                else update(1,1,n,j,n,-2);
            a[j]:=ch;
        end
        else begin
            read(fi,j,k);
            inc(c); rr[c]:=0;
            //res[c]:=check(j,k);
            x:=sub_get(1,1,n,j-1);
            y:=sub_get(1,1,n,k);
            if x <> y then continue;
            t:=get(1,1,n,j,x);
            if t > k then rr[c]:=1;
        end;
    end;

    {for i:=1 to c do write(fo,res[i]);
    writeln(fo);}
    for i:=1 to c do write(fo,rr[i]);
    {writeln(fo);
    for i:=1 to c do
        if res[i] <> rr[i] then begin
            writeln(fo,'WA!');
            break;
        end;}
    close(fo);
    close(fi);
end.
