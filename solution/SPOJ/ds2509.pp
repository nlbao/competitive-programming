const   n = 10010;

var fi,fo:text;
    q,x,y,i,t,r1,r2:longint;
    p:array[0..n] of longint;

function    get_root(u:longint):longint;
begin
    if (p[u] < 0) or (p[u] = u) then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

begin
    assign(fi,'ds2509.in');    reset(fi);
    assign(fo,'ds2509.out');    rewrite(fo);
    for i:=1 to n do p[i]:=-1;
    readln(fi,q);
    for i:=1 to q do begin
        readln(fi,x,y,t);
        r1:=get_root(x);
        r2:=get_root(y);
        if t = 2 then writeln(fo,longint(r1 = r2))
        else if r1 <> r2 then begin
            p[r1]:=p[r1]+p[r2];
            p[r2]:=r1;
        end;
    end;
    close(fo);
    close(fi);
end.