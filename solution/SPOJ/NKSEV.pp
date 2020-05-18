const   MAX_N = 300010;

type    myStr = ansiString;
        pNode = ^recNode;
        recNode = record
            link:array['a'..'z'] of pNode;
            ok:boolean;
        end;

var fi,fo:text;
    n,m:longint;
    s:myStr;
    root:pNode;
    f:array[0..MAX_N] of longint;

procedure   new_node(var p:pNode);
var ch:char;
begin
    new(p);
    with p^ do begin
        for ch:='a' to 'z' do link[ch]:=nil;
        ok:=false;
    end;
end;

procedure   add(var s:myStr);
var i:longint;
    p:pNode;
begin
    p:=root;
    for i:=length(s) downto 1 do begin
        if p^.link[s[i]] = nil then
            new_node(p^.link[s[i]]);
        p:=p^.link[s[i]];
    end;
    p^.ok:=true;
end;

procedure   enter;
var i:longint;
    t:myStr;
begin
    new_node(root);
    readln(fi,s);   n:=length(s);
    readln(fi,m);
    for i:=1 to m do begin
        readln(fi,t);
        add(t);
    end;
end;

procedure   solve;
var i,j:longint;
    p:pNode;
begin
    f[0]:=1;
    for i:=1 to n do begin
        f[i]:=0;
        p:=root;
        for j:=i downto 1 do begin
            if p^.link[s[j]] = nil then break;
            p:=p^.link[s[j]];
            if p^.ok then
                f[i]:=(f[i]+f[j-1]) mod 1337377;
        end;
    end;
    writeln(fo,f[n]);
end;

begin
    assign(fi,'nksev.in');  reset(fi);
    assign(fo,'nksev.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.