{
    ID: storm59061
    PROB: numgrid
    LANG: PASCAL
}

const   INPUT = 'numgrid.in';
        OUTPUT = 'numgrid.out';
        N = 5; M = 5;
        K = 6;
        dx:array[1..4] of longint =  (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

type    pTrie = ^recTrie;
        recTrie = record
            link:array['0'..'9'] of pTrie;
            word:boolean;
        end;

var fi,fo:text;
    root:pTrie;
    a:array[0..N+1,0..M+1] of char;
    s:string;
    res:longint;

{---------------------------------------------------------------------------}
procedure   new_node(var p:pTrie);
var ch:char;
begin
    new(p);
    for ch:='0' to '9' do p^.link[ch]:=nil;
    p^.word:=false;
end;
{---------------------------------------------------------------------------}
procedure   add(var s:string);
var i:longint;
    p:pTrie;
begin
    p:=root;
    for i:=1 to length(s) do begin
        if p^.link[s[i]] = nil then
            new_node(p^.link[s[i]]);
        p:=p^.link[s[i]];
    end;
    p^.word:=true;
end;
{---------------------------------------------------------------------------}
function    search(var s:string):boolean;
var i:longint;
    p:pTrie;
begin
    p:=root;
    for i:=1 to length(s) do
        if p^.link[s[i]] = nil then exit(false)
        else p:=p^.link[s[i]];
    exit(p^.word);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
begin
    for i:=0 to N+1 do
        for j:=0 to M+1 do a[i,j]:='.';
    for i:=1 to N do begin
        read(fi,a[i,1]);
        for j:=2 to M do begin
            read(fi,a[i,j]);
            read(fi,a[i,j]);
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   sinh(x,y,i:longint);
var j,x1,y1:longint;
begin
    if i > K then begin
        if search(s) = false then begin
            add(s);
            inc(res);
        end;
        exit;
    end;
    for j:=1 to 4 do begin
        x1:=x+dx[j]; y1:=y+dy[j];
        if a[x1,y1] <> '.' then begin
            s:=s+a[x1,y1];
            sinh(x1,y1,i+1);
            delete(s,i,1);
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j:longint;
begin
    new_node(root);
    res:=0;
    for i:=1 to N do
        for j:=1 to M do begin
            s:='';
            sinh(i,j,1);
        end;
    writeln(fo,res);
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