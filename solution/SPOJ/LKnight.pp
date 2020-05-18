const   MAX_N = 1010;
        MAX_K = 1010;
        dx:array[1..8] of longint = (+1,+2,+2,+1,-1,-2,-2,-1);
        dy:array[1..8] of longint = (+2,+1,-1,-2,-2,-1,+1,+2);

var fi,fo:text;
    n,k:longint;
    s:ansiString;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    solve:longint;
var i,j,x,y,x1,y1,x2,y2:longint;
begin
    x:=0;   y:=0;
    x1:=0;  y1:=0;
    x2:=0;  y2:=0;
    for i:=1 to k do begin
        j:=ord(s[i])-ord('0');
        x:=x+dx[j]; y:=y+dy[j];
        x1:=min(x1,x);  y1:=min(y1,y);
        x2:=max(x2,x);  y2:=max(y2,y);
    end;
    x1:=1+abs(x1);  y1:=1+abs(y1);
    x2:=n-x2;       y2:=n-y2;
    if (x2 < x1) or (y2 < y1) then exit(0);
    exit((x2-x1+1)*(y2-y1+1));
end;

begin
    assign(fi,'LKnight.in');    reset(fi);
    assign(fo,'LKnight.out');   rewrite(fo);
    readln(fi,n,k);
    readln(fi,s);
    writeln(fo,solve);
    close(fo);
    close(fi);
end.