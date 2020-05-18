const   INPUT = 'IGRA.in';
        OUTPUT = 'IGRA.out';
        MAX_N = 100010;

type    str = ansiString;

var fi,fo:text;
    n:longint;
    s:str;
    id:array[0..MAX_N] of longint;

procedure   enter;
begin
    readln(fi,n);
    readln(fi,s);
end;

procedure   quick_sort(l,r:longint);
var i,j,pos,tmp:longint;
    p:char;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=s[id[(i+j) shr 1]];
    pos:=id[(i+j) shr 1];
    repeat
        while (s[id[i]] > p) or ((s[id[i]] = p) and (id[i] < pos)) do inc(i);
        while (s[id[j]] < p) or ((s[id[j]] = p) and (id[j] > pos)) do dec(j);
        if i <= j then begin
            tmp:=id[i]; id[i]:=id[j];   id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   solve;
var i,j,k:longint;
    avail:array[0..MAX_N] of boolean;
    s1,s2,res:str;
begin
    for i:=1 to n do begin
        id[i]:=i;
        avail[i]:=true;
    end;
    quick_sort(1,n);
    s1:=''; s2:='';
    j:=n;   k:=n;
    for i:=1 to (n shr 1) do begin
        while (j > 0) and (not avail[j]) do dec(j);
        s1:=s1+s[j];    avail[j]:=false;
        while (k > 0) and (not avail[id[k]]) do dec(k);
        s2:=s2+s[id[k]];    avail[id[k]]:=false;
    end;
    res:='NE';
    for i:=1 to (n shr 1) do
        if s2[i] <> s1[i] then begin
            if s2[i] < s1[i] then res:='DA';
            break;
        end;
    writeln(fo,res);
    writeln(fo,s2);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
