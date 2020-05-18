const   INPUT = 'NAPOR.in';
        OUTPUT = 'NAPOR.out';
        MAX_N = 110;
        MAX_M = 510;
        digits:set of char = ['0','1','2','3','4','5','6','7','8','9'];

type    str = ansiString;

var fi,fo:text;
    n,m,i:longint;
    s:str;
    res:array[0..MAX_M] of str;

procedure   solve(var s:str);
var i,j,len:longint;
begin
    len:=length(s);
    i:=1;
    while i <= len do begin
        while (i <= len) and (not (s[i] in digits)) do inc(i);
        if i > len then break;
        j:=i;
        while (j < len) and (s[j+1] in digits) do inc(j);
        inc(m);
        res[m]:=copy(s,i,j-i+1);
        while (length(res[m]) > 1) and (res[m][1] = '0') do delete(res[m],1,1);
        i:=j+2;
    end;
end;

function    compare(var s1,s2:str):longint;
var i:longint;
begin
    if length(s1) < length(s2) then exit(-1);
    if length(s1) > length(s2) then exit(1);
    for i:=1 to length(s1) do
        if s1[i] < s2[i] then exit(-1)
        else if s1[i] > s2[i] then exit(1);
    exit(0);
end;

procedure   quick_sort(l,r:longint);
var i,j,len:longint;
    p,tmp:str;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=res[(i+j) shr 1];
    len:=length(p);
    repeat
        while compare(res[i],p) = -1 do inc(i);
        while compare(res[j],p) = 1 do dec(j);
        if i <= j then begin
            tmp:=res[i];    res[i]:=res[j]; res[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    m:=0;
    readln(fi,n);
    while n > 0 do begin
        readln(fi,s);
        solve(s);
        dec(n);
    end;
    quick_sort(1,m);
    for i:=1 to m do writeln(fo,res[i]);
    close(fo);
    close(fi);
end.
