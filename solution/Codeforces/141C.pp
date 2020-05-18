const   MAX_N = 3010;

type    myStr = string[100];

var fi,fo:text;
    n:longint;
    s:array[0..MAX_N] of myStr;
    a,id,h:array[0..MAX_N] of longint;

procedure   enter;
var i,j:longint;
    t:myStr;
begin
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s[i]);
        j:=1;
        while (s[i][j] <> ' ') do inc(j);
        t:=copy(s[i],j+1,length(s[i])-j);
        delete(s[i],j,length(s[i])-j+1);
        val(t,a[i]);
        id[i]:=i;
    end;
end;

procedure   qsort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=a[id[l+random(r-l+1)]];
    i:=l;   j:=r;
    repeat
        while a[id[i]] > p do inc(i);
        while a[id[j]] < p do dec(j);
        if i <= j then begin
            t:=id[i];   id[i]:=id[j];   id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

function    solve:longint;
var i,j:longint;
begin
    randomize;
    qsort(1,n);
    for i:=1 to n do h[i]:=1;
    for i:=n downto 1 do begin
        writeln(s[id[i]],' ',a[id[i]]);
        if a[id[i]] > n-i then exit(-1);
        for j:=1 to a[id[i]] do
            h[i]:=h[i]+1;
    end;
    for i:=n downto 1 do
        writeln(fo,s[id[i]],' ',h[i]);
end;

begin
    assign(fi,'141C.in');   reset(fi);
    assign(fo,'141C.out');  rewrite(fo);
    enter;
    if solve = -1 then writeln(fo,-1);
    close(fo);
    close(fi);
end.