const   MAX_N = 100010;
        oo = 1000000;

var fi,fo:text;
    s:ansiString;
    n:longint;
    ok:array['a'..'z','a'..'z'] of boolean;
    f:array[0..MAX_N,'a'..'z'] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   enter;
var i,k:longint;
    c1,c2:char;
begin
    readln(fi,s);
    n:=length(s);
    fillchar(ok,sizeof(ok),true);
    readln(fi,k);
    for i:=1 to k do begin
        readln(fi,c1,c2);
        ok[c1][c2]:=false;
        ok[c2][c1]:=false;
    end;
end;

procedure   solve;
var i,res:longint;
    j:char;
begin
    for i:=1 to n do
        for j:='a' to 'z' do f[i][j]:=oo;
    f[1][s[1]]:=0;
    for i:=2 to n do begin
        f[i][s[i]]:=i-1;
        for j:='a' to 'z' do begin
            f[i][j]:=min(f[i][j],f[i-1][j]+1);
            if ok[j][s[i]] then
                f[i][s[i]]:=min(f[i][s[i]],f[i-1][j]);
        end;
    end;
    res:=n;
    for j:='a' to 'z' do res:=min(res,f[n][j]);
    writeln(fo,res);
end;


begin
    assign(fi,'155C.in');   reset(fi);
    assign(fo,'155C.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
