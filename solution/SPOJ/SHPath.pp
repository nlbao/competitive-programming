const   MAX_N = 10010;
        MAX_nNode = 100010;
        MAX_INT = 1000000000;

type    myStr = ansiString;
        pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            w:longint;
            link:pEdge;
        end;
        recTrie = record
            id:longint;
            link:array['A'..'z'] of longint;
        end;

var fi,fo:text;
    nTest,n,nNode,h_size:longint;
    node:array[0..MAX_nNode] of recTrie;
    head:array[0..MAX_N] of pEdge;
    h,pos,d:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   new_node(var p:longint);
var ch:char;
begin
    inc(nNode);
    p:=nNode;
    node[p].id:=-1;
    for ch:='A' to 'z' do node[p].link[ch]:=-1;
end;

procedure   add(var s:myStr;    j:longint);
var i,p:longint;
begin
    p:=0;
    for i:=1 to length(s) do begin
        if node[p].link[s[i]] = -1 then
            new_node(node[p].link[s[i]]);
        p:=node[p].link[s[i]]
    end;
    node[p].id:=j;
end;

function    find(var s:mySTr):longint;
var i,p:longint;
begin
    p:=0;
    for i:=1 to length(s) do
        if node[p].link[s[i]] = -1 then exit(-1)
        else p:=node[p].link[s[i]];
    exit(node[p].id);
end;

procedure   add_edge(u,v,w0:longint);
var p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u;   y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=p;
    end;
end;

procedure   enter;
var i,j,k,m,w:longint;
    s:myStr;
begin
    nNode:=-1;
    new_node(nNode);
    readln(fi,n);
    for i:=1 to n do head[i]:=nil;
    for i:=1 to n do begin
        readln(fi,s);
        readln(fi,m);
        add(s,i);
        for j:=1 to m do begin
            readln(fi,k,w);
            add_edge(i,k,w);
        end;
    end;
end;

procedure   up_heap(i:longint);
var r:longint;
begin
    r:=i shr 1;
    if (r < 1) or (d[h[r]] <= d[h[i]]) then exit;
    swap(pos[h[r]],pos[h[i]]);
    swap(h[r],h[i]);
    up_heap(r);
end;

procedure   down_heap(i:longint);
var c:longint;
begin
    c:=i shl 1;
    if (c < h_size) and (d[h[c+1]] < d[h[c]]) then inc(c);
    if (c > h_size) or (d[h[c]] >= d[h[i]]) then exit;
    swap(pos[h[c]],pos[h[i]]);
    swap(h[c],h[i]);
    down_heap(c);
end;

procedure   push(u:longint);
begin
    inc(h_size);
    h[h_size]:=u;
    pos[u]:=h_size;
    up_heap(h_size);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    pos[u]:=-1;
    h[1]:=h[h_size];
    pos[h[1]]:=1;
    dec(h_size);
    if h_size > 0 then down_heap(1);
end;

procedure   Dijkstra(s,t:longint);
var i,u,tmp:longint;
    p:pEdge;
begin
    for i:=1 to n do begin
        avail[i]:=true;
        d[i]:=MAX_INT;  pos[i]:=-1;
    end;
    d[s]:=0;
    h_size:=0;  push(s);
    repeat
        pop(u);
        avail[u]:=false;
        p:=head[u];
        while p <> nil do with p^ do begin
            tmp:=d[u]+w;
            if (avail[y]) and (tmp < d[y]) then begin
                d[y]:=tmp;
                if pos[y] = -1 then push(y)
                else begin
                    i:=pos[y];
                    up_heap(i);
                    down_heap(i);
                end;
            end;
            p:=link;
        end;
    until (u = t) or (h_size = 0);
end;

procedure   solve;
var i,j,q:longint;
    s1,s2:myStr;
begin
    readln(fi,q);
    while q > 0 do begin
        readln(fi,s1);
        i:=1;
        while (s1[i] <> ' ') do inc(i);
        s2:=copy(s1,i+1,length(s1)-i);
        delete(s1,i,length(s2)+1);
        i:=find(s1);    j:=find(s2);
        Dijkstra(i,j);
        if d[j] = MAX_INT then writeln(fo,-1)
        else writeln(fo,d[j]);
        dec(q);
    end;
end;

begin
    assign(fi,'SHPath.in');     reset(fi);
    assign(fo,'SHPath.out');    rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        readln(fi);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.