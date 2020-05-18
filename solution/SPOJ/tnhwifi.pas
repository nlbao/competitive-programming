uses    math;

const   MAX_N = 1003;
        MAX_M = 30004;
        MAX_A = 1003;
        oo = 1000000000;

var fi,fo:text;
    n,m,nA,u,v,value,maxF,cF:longint;
    x,y,r,p:array[0..MAX_A] of longint;
    f:array[0..4*MAX_M] of longint;


procedure   enter();
var i:longint;
begin
    read(fi,m,n,nA);
    for i:=1 to nA do begin
        read(fi,x[i],y[i],r[i],p[i]);
        r[i]:=sqr(r[i]);
    end;
end;


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


procedure   get_res(k,l,r,s:longint);
var mid:longint;
begin
    if l > r then exit;
    s:=s+f[k];
    if l = r then begin
        if s > maxF then begin
            maxF:=s;
            cF:=1;
        end
        else if s = maxF then inc(cF);
        exit;
    end;
    mid:=(l+r) shr 1;
    get_res(k shl 1,l,mid,s);
    get_res((k shl 1)+1,mid+1,r,s);
end;


procedure   solve();
var i,h:longint;
    d,tmp:double;
begin
    maxF:=0;    cF:=0;
    for h:=1 to n do begin
        fillchar(f,sizeof(f),0);
        for i:=1 to nA do begin
            d:=sqr(x[i]-h);
            if r[i] < d then continue;
            tmp:=sqrt(r[i]-d);
            u:=max(trunc(y[i]-tmp),1);
            v:=min(trunc(y[i]+tmp+1),m);
            if d+sqr(y[i]-u) > r[i] then inc(u);
            if d+sqr(y[i]-v) > r[i] then dec(v);
            if u > v then continue;
            value:=p[i];
            update(1,1,m);
        end;
        get_res(1,1,m,0);
    end;
    writeln(fo,maxF);
    writeln(fo,cF);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'TNHWIFI.in');    reset(fi);
    assign(fo,'TNHWIFI.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.