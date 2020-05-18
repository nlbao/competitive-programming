const   INPUT = 'B.in';
        OUTPUT = 'B.out';
        MAX_N = 10010;

type    pNode = ^recNode;
        recNode = record
            value:longint;
            left,right:pNode;
        end;

var fi,fo:text;
    root:pNode;

procedure   add_node(v:longint);
var p,q,q0:pNode;
begin
    new(p);
    p^.value:=v;
    p^.left:=nil;   p^.right:=nil;
    if root = nil then begin
        root:=p;
        exit;
    end;
    q:=root;
    repeat
        q0:=q;
        if v < q^.value then q:=q^.left
        else q:=q^.right;
    until q = nil;
    if v < q0^.value then q0^.left:=p
    else q0^.right:=p;
end;

procedure   enter;
var value:longint;
begin
    root:=nil;
    while not eof(fi) do begin
        readln(fi,value);
        add_node(value);
    end;
end;

procedure   DFS(p:pNode);
begin
    if p^.left <> nil then DFS(p^.left);
    if p^.right <> nil then DFS(p^.right);
    writeln(fo,p^.value);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    if root <> nil then DFS(root);
    close(fo);
    close(fi);
end.