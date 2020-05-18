uses    math;

const   MAX_N = 100010;
        MAX_M = 200010;

var fi,fo:text;
    ch:char;
    n,m,i,j,k,t,pos,value:longint;
    a:array[0..MAX_N] of char;
    s:array[0..MAX_N] of longint;
    f,g:array[0..4*MAX_N] of longint;

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

procedure   update(k,l,r:longint);
var mid,left,right:longint;
begin
    if (l > r) or (r < pos) then exit;
    if pos <= l then begin
        g[k]:=g[k]+value;
        f[k]:=f[k]+value;
        exit;
    end;
    mid:=(l+r) shr 1;
    update(k shl 1,l,mid);
    update((k shl 1)+1,mid+1,r);
    f[k]:=min(f[k shl 1], f[(k shl 1)+1])+g[k];
end;


function    get(k,l,r:longint):longint;
var mid,left,right,t:longint;
begin
    if (l > r) or (r < pos) then exit(MAX_N);
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
    if f[left] < value then t:=get(left,l,mid);
    if (t = MAX_N) and (f[right] < value) then t:=get(right,mid+1,r);
    exit(t);
end;


function    sub_get(k,l,r:longint):longint;
var mid:longint;
begin
    if pos < 1 then exit(0);
    if (l > r) or (l > pos) or (r < pos) then exit(0);
    if l = r then exit(f[k]);
    mid:=(l+r) shr 1;
    exit(sub_get(k shl 1,l,mid) + sub_get((k shl 1)+1,mid+1,r) + g[k]);
end;


function    check(i,j:longint):longint;
var x,y:longint;
begin
    if (j-i+1) mod 2 = 1 then exit(0);
    if (a[i] = ')') or (a[j] = '(') then exit(0);
    pos:=i-1;   x:=sub_get(1,1,n);
    pos:=j;     y:=sub_get(1,1,n);
    if x <> y then exit(0);
    pos:=i; value:=x;
    if get(1,1,n) > j then exit(1);
    exit(0);
end;


begin
    assign(fi,'nkbracke20.in');     reset(fi);
    assign(fo,'nkbracke20.out');    rewrite(fo);

    readln(fi,n,m);
    s[0]:=0;
    for i:=1 to n do begin
        read(fi,a[i]);
        if a[i] = '(' then s[i]:=s[i-1]+1
        else s[i]:=s[i-1]-1;
    end;
    init(1,1,n);

    for i:=1 to m do begin
        read(fi,t);
        if t = 0 then begin
            read(fi,pos,ch);
            readln(fi,ch);
            if ch <> a[pos] then begin
                if ch = '(' then value:=2
                else value:=-2;
                update(1,1,n);
                a[pos]:=ch;
            end;
        end
        else begin
            read(fi,j,k);
            write(fo,check(j,k));
        end;
    end;

    close(fo);
    close(fi);
end.
