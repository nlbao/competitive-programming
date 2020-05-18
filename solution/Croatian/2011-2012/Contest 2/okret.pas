const   INPUT = ''{'okret.in'};
        OUTPUT = ''{'okret.out'};
        MAX_N = 20;
        MAX_M = 20;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

var fi,fo:text;
    n,m:longint;
    a:array[0..MAX_N,0..MAX_M] of char;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=0 to n+1 do
        for j:=0 to m+1 do a[i][j]:='X';
    for i:=1 to n do begin
        for j:=1 to m do read(fi,a[i][j]);
        readln(fi);
    end;
end;

function    solve:longint;
var i,j,k,count:longint;
begin
    for i:=1 to n do
        for j:=1 to m do if a[i][j] = '.' then begin
            count:=0;
            for k:=1 to 4 do
                if a[i+dx[k]][j+dy[k]] = '.' then inc(count);
            if count = 1 then exit(1);
        end;
    exit(0);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.