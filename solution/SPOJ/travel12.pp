const   MAX_N = 10010;
        MAX_M = 200010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,turn,f:array[0..MAX_N] of longint;

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
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        if u = v then continue;
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   solve;
var i,j,p,q:longint;
begin
    for i:=1 to n do turn[i]:=0;
    for i:=1 to n do begin
        p:=head[i];
        while p <> 0 do with e[p] do begin
            j:=y;
            q:=head[j];
            while q <> 0 do with e[q] do begin
                if y <> i then
                    if turn[y] <> i then begin
                        turn[y]:=i;
                        f[y]:=j;
                    end
                    else if f[y] <> j then begin
                        writeln(fo,i,' ',j,' ',y,' ',f[y]);
                        exit;
                    end;
                q:=link;
            end;
            p:=link;
        end;
    end;
    writeln(fo,-1);
end;

begin
    assign(fi,'travel12.in');   reset(fi);
    assign(fo,'travel12.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.