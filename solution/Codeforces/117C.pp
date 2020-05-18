const
    INPUT = '117C.inp';
    OUTPUT = '117C.out';
    MAX_N = 5010;
    MAX_M = sqr(MAX_N) div 2;

var
    fi,fo:text;
    N,M:longint;
    w:array[0..MAX_N,0..MAX_N] of boolean;
    adj,link:array[0..MAX_M] of longint;
    head:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    found:boolean;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(M);
    adj[M]:=v;
    link[M]:=head[u];
    head[u]:=M;
end;
{----------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
    ch:char;
begin
    readln(fi,N);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to N do begin
        for j:=1 to N do begin
            read(fi,ch);
            w[i,j]:=(ord(ch)-ord('0')) = 1;
            if w[i,j] then add_edge(i,j);
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u,parent_u:longint);
var
    i,v:longint;
begin
    avail[u]:=false;
    i:=head[u];
    while i <> 0 do begin
        if found then exit;
        v:=adj[i];
        if (parent_u <> -1) and w[v,parent_u] then begin
            writeln(fo,parent_u,' ',u,' ',v);
            found:=true;
        end;
        if avail[v] then DFS(v,u);
        i:=link[i];
    end;
end;
{---------------------------------------------------------------------------}

procedure   solve;
var
    i:longint;
begin
    found:=false;
    for i:=1 to N do avail[i]:=true;
    for i:=1 to N do
        if avail[i] then DFS(i,-1);
    if not found then writeln(fo,-1);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.