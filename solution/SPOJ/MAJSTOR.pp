var fi,fo:text;n,r:longint;s:string;a:array[0..60,0..60] of char;
function    max(x,y:longint):longint; begin if x > y then exit(x) else exit(y);end;
procedure   enter;
var i,j:longint;
begin readln(r);readln(s);readln(n); for i:=1 to n do begin for j:=1 to r do read(a[i][j]);readln;end;end;
function    score(c1,c2:char):longint;
begin
    if c1 = c2 then exit(1);
    case c1 of
        'S':if c2 = 'R' then exit(0)    else exit(2);
        'R':if c2 = 'P' then exit(0)    else exit(2);
        'P':if c2 = 'S' then exit(0)    else exit(2);
    end;
end;
function    cal(i:longint;  ch:char):longint;
var j,sum:longint;
begin sum:=0; for j:=1 to n do sum:=sum+score(ch,a[j][i]); exit(sum); end;

procedure   solve;
var i,t,res:longint;
begin
    res:=0;for i:=1 to r do res:=res+cal(i,s[i]);writeln(res);res:=0;
    for i:=1 to r do begin t:=cal(i,'S');t:=max(t,cal(i,'R'));t:=max(t,cal(i,'P'));res:=res+t; end;
    writeln(res);
end;
begin enter;solve;end.