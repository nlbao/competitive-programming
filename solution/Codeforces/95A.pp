const   INPUT = '95A.in';
        OUTPUT = '95A.out';
        MAX_N = 110;
        MAX_M = 110;

type    myStr = string[MAX_M];

var fi,fo:text;
    n,m:longint;
    s:array[0..MAX_N] of myStr;
    w:myStr;
    letter:char;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do readln(fi,s[i]);
    readln(fi,w);
    m:=length(w);
    readln(fi,letter);
end;

function    cmp(s1,s2:myStr):boolean;
var i:longint;
begin
    if length(s1) <> length(s2) then exit(false);
    for i:=1 to length(s1) do
        if upcase(s1[i]) <> upcase(s2[i]) then exit(false);
    exit(true);
end;

procedure   solve;
var i,j,k,l:longint;
    avail:array[0..MAX_M] of boolean;
    t1,t2:char;
begin
    for i:=1 to m do avail[i]:=true;
    for i:=1 to n do begin
        j:=1;   l:=length(s[i]);
        while j <= m-l+1 do begin
            if cmp(s[i],copy(w,j,l)) = true then begin
                for k:=j to j+l-1 do avail[k]:=false;
                j:=k;
            end;
            j:=j+1;
        end;
    end;
    t1:=upcase(letter); t2:=chr(ord(t1)+32);
    for i:=1 to m do
        if not avail[i] then
            if w[i] = upcase(w[i]) then begin
                if w[i] <> t1 then w[i]:=t1
                else if w[i] = 'A' then w[i]:='B'
                else w[i]:='A';
            end
            else begin
                if w[i] <> t2 then w[i]:=t2
                else if w[i] = 'a' then w[i]:='b'
                else w[i]:='a';
            end;
    writeln(fo,w);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
