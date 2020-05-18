const   MAX_N = 510;
        MAX_M = sqr(MAX_N) div 2;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,s,t:longint;
    head,d,trace:array[0..MAX_N] of longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    ok:array[-MAX_M..MAX_M] of boolean;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,u,v,w:longint;
begin
    readln(fi,n,j,s,t);
    m:=0;
    fillchar(head, sizeof(head), 0);
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;

procedure   print(u:longint);
begin
    if u < 1 then exit;
    print(trace[u]);
    write(fo,u,' ');
end;


procedure   solve;
var i,u:longint;
    stop:boolean;
begin
    for i:=1 to n do begin
        d[i]:=oo;
        trace[i]:=-1;
    end;
    d[s]:=0;
    repeat
        stop:=true;
        for u:=1 to n do begin
            i:=head[u];
            while i <> 0 do with e[i] do begin
                if d[u]+w < d[y] then begin
                    d[y]:=d[u]+w;
                    trace[y]:=u;
                    stop:=false;
                end;
                i:=link;
            end;
        end;
    until stop;
    writeln(fo,d[t]);
    print(t);
end;


begin
    assign(fi,'minpath.in');      reset(fi);
    assign(fo,'minpath.out');     rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
