uses    math;

const   MAX_M = 22;
        MAX_N = 110;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,limit,r,nE,res,p,sum,ckn:longint;
    e:array[0..MAX_N*MAX_M] of recEdge;
    head,a,b:array[0..MAX_M] of longint;
    c:array[0..MAX_N] of longint;


procedure   add_edge(u,v,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i,j,x,y,s:longint;
begin
    nE:=0;
    read(fi,limit,r);
    read(fi,m);
    for i:=1 to m do begin
        head[i]:=0;
        read(fi,a[i],b[i]);
    end;

    r:=r*r;
    read(fi,n);
    for i:=1 to n do begin
        read(fi,x,y,s);
        for j:=1 to m do
            if sqr(a[j]-x)+sqr(b[j]-y) <= r then
                add_edge(j,i,s);
    end;
end;


procedure   update(u,d:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        c[y]:=c[y]+d;
        if c[y] = 0 then sum:=sum-w
        else if (d = 1) and (c[y] = 1) then sum:=sum+w;
        i:=link;
    end;
end;


procedure   tryf(i:longint);
begin
    if (p = limit) or (i > m) then begin
        res:=max(res,sum);
        //inc(ckn);
        exit;
    end;

    if m-i >= limit-p then tryf(i+1);

    update(i,1);
    inc(p);
    tryf(i+1);
    dec(p);
    update(i,-1);
end;


procedure   solve();
var i:longint;
begin
    ckn:=0;
    res:=0;
    p:=0;   sum:=0;
    fillchar(c,sizeof(c),0);
    tryf(1);
    //writeln(ckn);
    writeln(fo,res);
end;


begin
    assign(fi,'pizzaloc.in');   reset(fi);
    assign(fo,'pizzaloc.out');  rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.