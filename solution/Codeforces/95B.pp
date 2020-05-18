const   INPUT = '95B.in';
        OUTPUT = '95B.out';
        MAX_N = 100010;

type    myStr = ansiString;

var fi,fo:text;
    s:myStr;
    n:longint;

procedure   enter;
begin
    readln(fi,s);
    n:=length(s);
end;

procedure   print(n:longint);
var i:longint;
begin
    for i:=1 to (n shr 1) do write(fo,'4');
    for i:=1 to (n shr 1) do write(fo,'7');
end;

function    check(n:longint):boolean;
var i,j,c4,c7:longint;
begin
    j:=-1;
    c4:=0;  c7:=0;
    for i:=1 to n do begin
        if (s[i] < '4') and ((abs(c7-c4-1) <= n-i) or (abs(c7-c4+1) <= n-i)) then j:=i
        else if (s[i] < '7') and (abs(c7-c4+1) <= n-i) then j:=i;
        if s[i] = '4' then inc(c4)
        else if s[i] = '7' then inc(c7)
        else break;
        if abs(c7-c4) > n-i then break
    end;
    if (i = n) and (c4 = c7) and ((s[n] = '4') or (s[n] = '7')) then begin
        write(fo,s);
        exit(true);
    end;
    if j = -1 then exit(false);
    c4:=0; c7:=0;
    for i:=1 to j-1 do begin
        write(fo,s[i]);
        if s[i] = '4' then inc(c4)
        else inc(c7);
    end;
    if (s[j] < '4') and (abs(c7-c4-1) <= n-j) then begin   write(fo,'4'); inc(c4); end
    else begin  write(fo,'7');  inc(c7);    end;
    for i:=1 to (n shr 1)-c4 do write(fo,'4');
    for i:=1 to (n shr 1)-c7 do write(fo,'7');
    exit(true);
end;

procedure   solve;
begin
    if n mod 2 = 1 then print(n+1)
    else if check(n) = false then print(n+2);
    writeln(fo);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    while not eof(fi) do begin
        enter;
        solve;
    end;
    close(fo);
    close(fi);
end.
