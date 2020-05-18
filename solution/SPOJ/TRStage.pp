uses    math;

const   MAX_N = 50;
        MAX_M = sqr(MAX_N);
        eps = 0.00001;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            w:double;
            link:longint;
        end;

var fi,fo:text;
    n,m,nT,a,b:longint;
    e:array[0..2*MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    t:array[0..10] of double;
    d:array[0..MAX_N,0..260] of double;


procedure   add_edge(u,v:longint;   w0:double);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,u,v,w:longint;
begin
    for i:=1 to nT do read(fi,t[i]);
    j:=m;   m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   solve;
var i,j,jj,k,u:longint;
    res:double;
begin
    res:=oo;
    for i:=1 to n do
        for j:=0 to (1 shl nT)-1 do
            d[i][j]:=oo;
    d[a][0]:=0;
    for j:=0 to (1 shl nT)-1 do
        for u:=1 to n do
            if d[u][j] < oo-100 then
                for k:=1 to nT do
                    if (j shr (k-1)) and 1 = 0 then begin
                        jj:=j or (1 shl (k-1));
                        i:=head[u];
                        while i <> 0 do with e[i] do begin
                            d[y][jj]:=min(d[y][jj],d[u][j]+w/t[k]);
                            i:=link;
                        end;
                    end;
    for i:=0 to (1 shl nT)-1 do
        res:=min(res,d[b][i]);
    if res >= oo-100 then writeln(fo,'Impossible')
    else writeln(fo,res:0:6);
end;

begin
    assign(fi,'TRStage.in');    reset(fi);
    assign(fo,'TRStage.out');   rewrite(fo);
    read(fi,nT,n,m,a,b);
    while n > 0 do begin
        enter;
        solve;
        read(fi,nT,n,m,a,b);
    end;
    close(fo);
    close(fi);
end.