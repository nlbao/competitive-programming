const   MAX_N = 100010;

type    recTrie = record
            id:longint;
            link:array['A'..'z'] of longint;
        end;

var fi,fo:text;
    nTest,n,m,nNode,i:longint;
    f:array[0..MAX_N] of longint;
    t:array[0..30*MAX_N] of recTrie;

procedure   new_node(var p:longint);
var ch:char;
begin
    inc(nNode);
    p:=nNode;
    for ch:='A' to 'z' do t[p].link[ch]:=-1;
end;

function    find(var s:string):longint;
var i,p:longint;
    ok:boolean;
begin
    ok:=true;
    p:=0;
    for i:=1 to length(s) do begin
        if t[p].link[s[i]] < 1 then begin
            new_node(t[p].link[s[i]]);
            ok:=false;
        end;
        p:=t[p].link[s[i]];
    end;
    if not ok then begin
        inc(n);
        t[p].id:=n;
        f[n]:=-1;
    end;
    exit(t[p].id);
end;

function    get_root(u:longint):longint;
begin
    if f[u] < 0 then exit(u);
    f[u]:=get_root(f[u]);
    exit(f[u]);
end;

procedure   solve;
var i,j,r1,r2:longint;
    s,s1,s2:string[30];
begin
    n:=0;   nNode:=-1;
    new_node(nNode);
    readln(fi,m);
    for i:=1 to m do begin
        readln(fi,s);
        j:=1;
        while s[j] <> ' ' do inc(j);
        s1:=copy(s,1,j-1);
        s2:=copy(s,j+1,length(s)-j);
        r1:=get_root(find(s1));
        r2:=get_root(find(s2));
        if r1 <> r2 then begin
            f[r1]:=f[r1]+f[r2];
            f[r2]:=r1;
        end;
        writeln(fo,-f[r1]);
    end;
end;

begin
    assign(fi,'100008A.in');    reset(fi);
    assign(fo,'100008A.out');   rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do solve;
    close(fo);
    close(fi);
end.