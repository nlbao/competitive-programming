const   INPUT = 'TTrip.in';
        OUTPUT = 'TTrip.out';
        MAX_N = 110;
        MAX_INT = 1000000000;

var fi,fo:text;
    n:longint;
    w:array[0..MAX_N,0..MAX_N] of longint;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,w[i][j]);
            if w[i][j] = 0 then w[i][j]:=MAX_INT;
        end;
end;

procedure   floyd;
var i,j,k:longint;
begin
    for k:=1 to n do
        for i:=1 to n do
            for j:=1 to n do
                if w[i][k]+w[k][j] < w[i][j] then
                    w[i][j]:=w[i][k]+w[k][j];
end;

procedure   solve;
var i,j,u,v,d,res:longint;
    avail:array[0..MAX_N] of boolean;
begin
    res:=0;
    u:=1;   avail[1]:=false;
    for i:=2 to n do avail[i]:=true;
    for i:=1 to n do begin
        d:=MAX_INT;
        for j:=1 to n-1 do
            if (avail[j]) and (w[u][j] < d) then begin
                d:=w[u][j];
                v:=j;
            end;
        if d < MAX_INT then begin
            res:=res+d;
            avail[v]:=false;
            u:=v;
        end
        else break;
    end;
    writeln(fo,res+w[u][n]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    floyd;
    solve;
    close(fo);
    close(fi);
end.