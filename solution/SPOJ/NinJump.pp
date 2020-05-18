const   MAX_N = 110;
        MAX_INT = 2000000000;

var fi,fo:text;
    n,x,y,u,v,s,res:longint;
    h:array[0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    readln(fi,x,y,u,v);
    for i:=1 to n do read(fi,h[i]);
end;

procedure   tryf2(i:longint);
var j,t:longint;
begin
    if i = 1 then res:=min(res,s);
    if s >= res then exit;
{nhay cao}
    t:=max(h[i-1]-h[i],0)*u;
    s:=s+t;    dec(h[i-1]);
    tryf2(i-1);
    s:=s-t;    inc(h[i-1]);

{nhay xa}
    for j:=i-1 downto 1 do
        if h[j] >= h[i] then break
        else begin
            t:=(i-j)*v;
            s:=s+t;    dec(h[j]);
            tryf2(j);
            s:=s-t;    inc(h[j]);
        end;
end;

procedure   tryf1(i:longint);
var j,t:longint;
begin
    if s >= res then exit;
    if i = n then begin
        dec(h[n]);
        tryf2(n);
        inc(h[n]);
        exit;
    end;
{nhay cao}
    t:=max(h[i+1]-h[i],0)*x;
    s:=s+t;    dec(h[i+1]);
    tryf1(i+1);
    s:=s-t;    inc(h[i+1]);

{nhay xa}
    for j:=i+1 to n do
        if h[j] >= h[i] then break
        else begin
            t:=(j-i)*y;
            s:=s+t;    dec(h[j]);
            tryf1(j);
            s:=s-t;    inc(h[j]);
        end;
end;

procedure   solve;
begin
    res:=MAX_INT;
    s:=0;   dec(h[1]);
    tryf1(1);
    writeln(fo,res);
end;

begin
    assign(fi,'NinJump.in');    reset(fi);
    assign(fo,'NinJump.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.