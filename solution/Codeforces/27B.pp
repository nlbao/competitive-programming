const   INPUT = '27B.in';
        OUTPUT = '27B.out';
        MAX_N = 60;

var fi,fo:text;
    n:longint;
    w:array[0..MAX_N,0..MAX_N] of longint;

procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n);
    for u:=1 to n do begin
        for v:=1 to n do w[u,v]:=-1;
        w[u,u]:=0;
    end;
    for i:=1 to n*(n-1) div 2 do begin
        readln(fi,u,v);
        w[u,v]:=1;
        w[v,u]:=0;
    end;
end;

procedure   solve;
var i,j,u,v:longint;
begin
    for u:=1 to n do begin
        for v:=1 to n do
            if w[u,v] = -1 then break;
        if w[u,v] = -1 then break;
    end;
    j:=-1;
    for i:=1 to n do
        if (w[u,i] = 1) and (w[i,v] = 1) then begin
            j:=i;
            break;
        end;
    if j = -1 then writeln(fo,v,' ',u)
    else writeln(fo,u,' ',v);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.