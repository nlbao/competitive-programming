{$M 16777216}
uses    math;

const   MAX_N = 100005;
        MAX_M = 200005;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,d,f:array[0..MAX_N] of longint;
    l,r:array[0..1] of longint;
    q:array[0..1,0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;


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
var i,u,v,w:longint;
begin
    read(fi,n,m);
    nE:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,w);
        if u = v then continue;
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;


procedure   empty(i:longint);   begin   l[i]:=1;    r[i]:=0;    end;

procedure   push(i,u:longint);
begin
    inc(r[i]);
    q[i][r[i]]:=u;
end;

procedure   pop(i:longint;  var u:longint);
begin
    u:=q[i][l[i]];
    inc(l[i]);
end;

procedure   solve();
var i,j,k,u,t,tt,minW:longint;
begin
    for i:=1 to n do d[i]:=oo;
    d[n]:=0;
    empty(0);
    push(0,n);
    while l[0] <= r[0] do begin
        pop(0,u);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if d[y] = oo then begin
                d[y]:=d[u]+1;
                push(0,y);
            end;
            i:=link;
        end;
    end;

    empty(0);
    push(0,1);
    t:=0;   m:=0;
    for i:=1 to n do ok[i]:=true;
    for k:=1 to d[1] do begin
        tt:=t;
        t:=1-t;

        minW:=oo;
        for j:=l[tt] to r[tt] do begin
            u:=q[tt][j];
            i:=head[u];
            while i <> 0 do with e[i] do begin
                if (ok[y]) and (d[y]+1 = d[u]) then
                    minW:=min(minW,w);
                i:=link;
            end;
        end;

        inc(m);
        f[m]:=minW;

        empty(t);
        for j:=l[tt] to r[tt] do begin
            u:=q[tt][j];
            i:=head[u];
            while i <> 0 do with e[i] do begin
                if (ok[y]) and (w = minW) and (d[y]+1 = d[u]) then begin
                    push(t,y);
                    ok[y]:=false;
                end;
                i:=link;
            end;
        end;
    end;

    writeln(fo,m);
    for i:=1 to m do write(fo,f[i],' ');
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'100084I.in');    reset(fi);
    assign(fo,'100084I.out');   rewrite(fo);
{$ELSE}
    assign(fi,'ideal.in');     reset(fi);
    assign(fo,'ideal.out');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.