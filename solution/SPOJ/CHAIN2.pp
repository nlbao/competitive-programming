uses    math;

const   MAX_N = 250010;

type    myStr = ansiString;
        pNode = ^recNode;
        recNode = record
            link:array['a'..'z'] of pNode;
            f:longint;
        end;

var fi,fo:text;
    n,i,res:longint;
    s:array[0..MAX_N] of myStr;
    a,id:array[0..MAX_N] of longint;
    root:pNode;


procedure   new_node(var p:pNode);
var ch:char;
begin
    new(p);
    with p^ do begin
        for ch:='a' to 'z' do link[ch]:=nil;
        f:=0;
    end;
end;

procedure   add(var s:myStr);
var i,t:longint;
    p:pNode;
begin
    p:=root;    t:=0;
    for i:=1 to length(s) do begin
        if p^.link[s[i]] = nil then begin
            new_node(p^.link[s[i]]);
            t:=max(t,p^.f);
        end;
        p:=p^.link[s[i]];
    end;
    p^.f:=max(p^.f,t+1);
    res:=max(res,p^.f);
end;

procedure   qsort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=a[id[l+random(r-l+1)]];
    i:=l;   j:=r;
    repeat
        while a[id[i]] < p do inc(i);
        while a[id[j]] > p do dec(j);
        if i <= j then begin
            t:=id[i];   id[i]:=id[j];   id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s[i]);
        a[i]:=length(s[i]);
        id[i]:=i;
    end;
end;

procedure   solve;
var i:longint;
begin
    res:=0;
    randomize;
    qsort(1,n);
    new_node(root);
    for i:=1 to n do add(s[id[i]]);
    writeln(fo,res);
end;

begin
    assign(fi,'chain2.in');     reset(fi);
    assign(fo,'chain2.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.