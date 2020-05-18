const   INPUT = 'znan.in';
        OUTPUT = 'znan.out';
        MAX_N = 1010;
        MAX_M = 1010;

type    pNode = ^recNode;
        recNode = record
            link:array['a'..'z'] of pNode;
        end;

var fi,fo:text;
    n,m:longint;
    a:array[0..MAX_N,0..MAX_M] of char;
    f:array[0..MAX_M] of longint;
    root:pNode;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do begin
        for j:=1 to m do read(fi,a[i][j]);
        readln(fi);
    end;
end;

procedure   new_node(var p:pNode);
var ch:char;
begin
    new(p);
    for ch:='a' to 'z' do p^.link[ch]:=nil;
end;

procedure   add(j:longint);
var p,q:pNode;
    i:longint;
begin
    f[j]:=0;
    p:=root;
    for i:=n downto 1 do begin
        if p^.link[a[i][j]] = nil then
            new_node(p^.link[a[i][j]])
        else inc(f[j]);
        p:=p^.link[a[i][j]];
    end;
end;

procedure   solve;
var j,res:longint;
begin
    new_node(root);
    for j:=1 to m do add(j);
    res:=0;
    for j:=1 to m do
        if f[j] > res then res:=f[j];
    if res = n then dec(res);
    writeln(fo,n-res-1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
