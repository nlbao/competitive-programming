const   MAX_N = 300010;

type    pNode = ^recNode;
        recNode = record
            link:array['a'..'z'] of pNode;
            w:boolean;
        end;

var fi,fo:text;
    n,m,maxL:longint;
    s:ansiString;
    root:pNode;
    ok:array[0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   new_node(var p:pNode);
var ch:char;
begin
    new(p);
    p^.w:=false;
    for ch:='a' to 'z' do p^.link[ch]:=nil;
end;

procedure   add_node(var s:ansiString);
var p:pNode;
    i:longint;
begin
    p:=root;
    for i:=1 to length(s) do begin
        if p^.link[s[i]] = nil then
            new_node(p^.link[s[i]]);
        p:=p^.link[s[i]];
    end;
    p^.w:=true;
end;

procedure   enter;
var i:longint;
    a:ansiString;
begin
    new_node(root);
    readln(fi,n);
    readln(fi,s);
    readln(fi,m);
    for i:=1 to m do begin
        readln(fi,a);
        add_node(a);
        maxL:=max(maxL, length(a));
    end;
end;

procedure   solve;
var i,j,k,res:longint;
    p:pNode;
begin
    fillchar(ok, sizeof(ok), false);
    for i:=1 to n do begin
        j:=-1;
        p:=root;
        for k:=i to min(i+maxL-1, n) do
            if p^.link[s[k]] = nil then break
            else begin
                p:=p^.link[s[k]];
                if p^.w then j:=k;
            end;
        for k:=i to j do ok[k]:=true;
    end;
    res:=0;
    for i:=1 to n do
        if not ok[i] then inc(res);
    writeln(fo,res);
end;


begin
    assign(fi,''{'poplocavanje.in'});   reset(fi);
    assign(fo,''{'poplocavanje.out'});  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
