const   MAX_N = 1000;
        MAX_M = (MAX_N*MAX_N) div 2;


var fi,fo:text;
    n,m,i,res:longint;
    head,deg:array[0..MAX_N] of longint;
    a,b,adj:array[0..MAX_M] of longint;
    ok:array[0..MAX_N] of boolean;

procedure   dfs(u:longint);
var i:longint;
begin
    ok[u]:=false;
    for i:=head[u]+1 to head[u+1] do
        if ok[adj[i]] then dfs(adj[i]);
end;

begin
    assign(fi,'message.in');    reset(fi);
    assign(fo,'message.out');   rewrite(fo);
    read(fi,n,m);
    fillchar(head,sizeof(head),0);
    fillchar(deg,sizeof(deg),0);
    for i:=1 to m do begin
        read(fi,a[i],b[i]);
        inc(head[a[i]]);
        inc(deg[b[i]]);
    end;
    for i:=2 to n+1 do head[i]:=head[i-1]+head[i];
    for i:=1 to m do begin
        adj[head[a[i]]]:=b[i];
        dec(head[a[i]]);
    end;

    res:=0;
    fillchar(ok,sizeof(ok),true);
    for i:=1 to n do
        if deg[i] = 0 then begin
            writeln(i);
            inc(res);
            dfs(i);
        end;
    for i:=1 to n do
        if ok[i] then begin
            writeln(i);
            inc(res);
            dfs(i);
        end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.