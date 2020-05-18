const   MAX_N = 310;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
            link:longint;
        end;
        arr = array[0..MAX_N] of longint;

var fi,fo:text;
    n,m,nRes:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,res:arr;
    g:array[0..MAX_N,0..MAX_N,0..1] of boolean;
    a:array[0..MAX_N,0..MAX_N] of longint;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n);
    m:=0;
    for i:=1 to n do head[i]:=0;
    while not eof(fi) do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   init;
var i,j,l,r,d:longint;
    qx,qd:arr;
begin
    fillchar(g,sizeof(g),false);
    for i:=1 to n do begin
        l:=1;   r:=1;
        qx[1]:=i;   qd[1]:=0;
        repeat
            j:=head[qx[l]];
            d:=(qd[l]+1) mod 2;
            inc(l);
            while j <> 0 do with e[j] do begin
                if not g[i][y][d] then begin
                    g[i][y][d]:=true;
                    inc(r);
                    qx[r]:=y;   qd[r]:=d;
                end;
                j:=link;
            end;
        until l > r;
        g[i][i][0]:=true;
    end;
end;

procedure   update(var s:arr;   n:longint);
var i:longint;
begin
    for i:=1 to n do begin
        inc(nRes);
        res[nRes]:=s[i];
    end;
end;

procedure   sort;
var i,j,t:longint;
begin
    for i:=1 to nRes-1 do
        for j:=i+1 to nRes do
            if res[i] > res[j] then begin
                t:=res[i];
                res[i]:=res[j];
                res[j]:=t;
            end;
end;

procedure   solve;
var i,j,n1,n2:longint;
    s1,s2:arr;
    ok:array[0..MAX_N] of boolean;
begin
    fillchar(a,sizeof(a),0);
    for i:=1 to n do
        for j:=1 to n do begin
            if (g[i][j][0]) and (g[i][j][1]) then begin
                writeln(fo,'YES');
                exit;
            end;
            if g[i][j][1] then a[i][j]:=1
            else if g[i][j][0] then a[i][j]:=2
            else a[i][j]:=0;
        end;





    writeln(fo,'NO');
    writeln(fo,nRes);
    for i:=1 to nRes do write(fo,res[i],' ');
end;

begin
    assign(fi,'NKParity.in');   reset(fi);
    assign(fo,'NKParity.out');  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.