uses    math;

const   MAX_N = 111;
        MAX_M = 10004;
        oo = 1000000010;
        eps = 0.001;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:double;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE:longint;
    c:array[0..MAX_N,0..MAX_N] of double;
    e:array[0..MAX_M] of recEdge;
    head,trace:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of double;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i,u,v,cc:longint;
begin
    nE:=0;
    read(fi,n,m);
    for u:=1 to n do
        for v:=1 to n do c[u][v]:=oo;
    fillchar(head,sizeof(head),0);

    for i:=1 to m do begin
        read(fi,u,v,cc);
        c[u][v]:=min(c[u][v],cc);
    end;

    for u:=1 to n do
        for v:=1 to n do
            if c[u][v] < oo then add_edge(u,v);
end;


function    is_circle(u,v:longint):boolean;
begin
    while (u <> v) and (u <> 0) do u:=trace[u];
    exit(u = v);
end;


function    check(value:double):boolean;
var i,u,v:longint;
    tmp:double;
    stop:boolean;
begin
    for i:=1 to nE do with e[i] do
        w:=c[x][y]-value;

    for i:=1 to n do begin
        d[i]:=oo;
        trace[i]:=0;
    end;
    d[1]:=0;

    repeat
        stop:=true;
        for u:=1 to n do begin
            i:=head[u];
            while i <> 0 do with e[i] do begin
                tmp:=d[u] + w;
                if  tmp < d[y] then begin
                    d[y]:=tmp;
                    if is_circle(u,y) then exit(true);
                    trace[y]:=u;
                    stop:=false;
                end;
                i:=link;
            end;
        end;
    until stop;
    exit(false);
end;


procedure   solve();
var i:longint;
    l,r,mid,res:double;
begin
    res:=-1;
    l:=0;   r:=10000000;
    //for i:=1 to 40 do begin
    while r-l > eps do begin
        mid:=(l+r)/2;
        if check(mid) then begin
            res:=mid;
            r:=mid;
        end
        else l:=mid;
    end;
    if res < 0 then writeln(fo,-1)
    else writeln(fo,res:0:2);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'QBTRANS.in');   reset(fi);
    assign(fo,'QBTRANS.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.