const
    INPUT = '110E.inp';
    OUTPUT = '110E.out';
    MAX_N = 100010;
    MAX_M = 2*MAX_N;

function    check(w:longint):boolean;
var
    s:string;
    i:longint;
begin
    str(w,s);
    for i:=1 to length(s) do
        if (s[i] <> '4') and (s[i] <> '7') then exit(false);
    exit(true);
end;

procedure   add_edge(u,v,weight:longint);   inline;
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        is_lucky:=check(weight);
        next[M]:=head[u];
        head[u]:=M;
    end;
end;

procedure   enter;
var
    i,u,v,w:longint;
begin
    readln(fi,N);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to N-1 do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
    end;
end;

procedure   DFS(u:longint);
begin
    i:=head[u];
    while i <> 0 do begin
        v:=e[i].y;
        if parent[v] = -1 then begin
            parent[v]:=u;
            inc(nChildren[u]);
            DFS(v);
        end;
        i:=next[i];
    end;
    top[u]:=0;


end;

procedure   solve;
begin
    for i:=1 to N do begin
        parent[i]:=-1;
        nChildren[i]:=0;
    end;
    parent[1]:=0;
    res:=0;
    DFS(1);
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.