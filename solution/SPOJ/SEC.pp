const
    INPUT = 'SEC.inp';
    OUTPUT = 'SEC.out';
    MAX_M = 50010;
    MAX_N = 50010;
    MAX_B = 10010;

type
    pTrie = ^recTrie;
    recTrie = record
        adj:array[0..1] of pTrie;
        cw,cpre:longint;
    end;
    arrData = array[0..MAX_B] of longint;

var
    fi,fo:text;
    S:arrData;
    M,N:longint;
    root:pTrie;

{---------------------------------------------------------------------------}
procedure   new_node(var p:pTrie);
var
    i:longint;
begin
    new(p);
    with p^ do begin
        cw:=0;
        cpre:=0;
        for i:=0 to 1 do adj[i]:=nil;
    end;
end;
{---------------------------------------------------------------------------}
procedure   add_trie;
var
    p:pTrie;
    i:longint;
begin
    p:=root;
    for i:=1 to s[0] do
        with p^ do begin
            if adj[s[i]] = nil then
                new_node(adj[s[i]]);
            p:=adj[s[i]];
            inc(p^.cpre);
        end;
    inc(p^.cw);
end;
{---------------------------------------------------------------------------}
function    search_trie:longint;
var
    p:pTrie;
    i,sum:longint;
begin
    p:=root;
    sum:=0;
    for i:=1 to s[0] do begin
        p:=p^.adj[s[i]];
        if p = nil then break
        else inc(sum,p^.cw);
    end;
    if p <> nil then inc(sum,p^.cpre-p^.cw);
    exit(sum);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    new_node(root);
    for i:=1 to M do begin
        read(fi,s[0]);
        for j:=1 to s[0] do read(fi,s[j]);
        add_trie;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
begin
    for i:=1 to N do begin
        read(fi,s[0]);
        for j:=1 to s[0] do read(fi,s[j]);
        writeln(fo,search_trie);
    end;
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