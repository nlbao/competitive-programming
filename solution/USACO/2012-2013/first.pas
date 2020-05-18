{$M 16777216}
uses    math;

const   MAX_N = 30004;
        oo = 1000000000;

type    mStr = ansiString;
        pNode = ^recNode;
        recNode = record
            ok:boolean;
            link:array['a'..'z'] of pNode;
        end;


var fi,fo:text;
    n:longint;
    s:array[0..MAX_N] of mStr;
    cmp:array['a'..'z','a'..'z'] of longint;
    root:pNode;


procedure   new_node(var p:pNode);
var x:char;
begin
    new(p);
    for x:='a' to 'z' do p^.link[x]:=nil;
    p^.ok:=false;
end;


procedure   enter();
var i,j,m:longint;
    x:char;
    p:pNode;
begin
    new_node(root);
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s[i]);
        p:=root;
        m:=length(s[i]);
        for j:=1 to m do begin
            x:=s[i][j];
            if p^.link[x] = nil then
                new_node(p^.link[x]);
            p:=p^.link[x];
        end;
        p^.ok:=true;
    end;
end;


procedure   push(x,y:char);
begin
    cmp[x][y]:=-1;
    cmp[y][x]:=1;
end;


function    check(var s:mStr):boolean;
var i,m:longint;
    x,y,z:char;
    p:pNode;
begin
    fillchar(cmp,sizeof(cmp),0);
    p:=root;
    m:=length(s);
    for i:=1 to m do begin
        x:=s[i];
        for y:='a' to 'z' do
            if (y = x) or (p^.link[y] = nil) then continue
            else if cmp[y][x] = -1 then exit(false)
            else push(x,y);
        p:=p^.link[x];
        if (i < m) and (p^.ok) then exit(false);
    end;

    for x:='a' to 'z' do
        for y:='a' to 'z' do
            for z:='a' to 'z' do
                if (cmp[x][y] = -1) and (cmp[y][z] = -1) then
                    if cmp[x][z] = 1 then exit(false)
                    else push(x,z);
    exit(true);
end;


procedure   solve();
var i,c:longint;
    a:array[0..MAX_N] of longint;
begin
    c:=0;
    for i:=1 to n do
        if check(s[i]) then begin
            inc(c);
            a[c]:=i;
        end;
    writeln(fo,c);
    for i:=1 to c do writeln(fo,s[a[i]]);
end;


begin
    assign(fi,'first.in');    reset(fi);
    assign(fo,'first.out');   rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.