{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 30033;
        MAX_M = 130033;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,
    n,m,nA,last:longint;
    e:array[0..MAX_M] of recEdge;
    head,p,f,trace,a:array[0..MAX_N] of longint;


procedure   enter();
var i:longint;
begin
    read(fi,n,m);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do with e[i] do begin
        read(fi,x,y);
        link:=head[x];
        head[x]:=i;
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if f[y] < oo then last:=min(last,f[y])
        else if p[y] = 0 then begin
            p[y]:=u;
            dfs(y);
        end;
        i:=link;
    end;
end;


function    solve():longint;
var i,u,l,r:longint;
begin
    for i:=1 to n do f[i]:=oo;
    f[1]:=0;
    trace[1]:=0;
    l:=1;   r:=1;   p[1]:=1;
    while l <= r do begin
        u:=p[l]; inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if f[u]+1 < f[y] then begin
                f[y]:=f[u]+1;
                trace[y]:=u;
                inc(r); p[r]:=y;
            end;
            i:=link;
        end;
    end;

    for i:=1 to n do begin
        p[i]:=0;
        f[i]:=oo;
    end;
    nA:=0;
    i:=n;
    while i > 0 do begin
        inc(nA);
        a[nA]:=i;
        f[i]:=nA;
        i:=trace[i];
    end;

    last:=nA+1000;
    for i:=nA downto 1 do begin
        u:=a[i];
        if (u <> 1) and (last >= f[u]) then exit(u);
        p[u]:=-1;
        dfs(u);
    end;

    exit(-1);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'en.in');    reset(fi);
    assign(fo,'en.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    while nTest > 0 do begin
        enter();
        writeln(fo,solve());
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.