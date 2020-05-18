const   INPUT = 'Profesor.in';
        OUTPUT = 'Profesor.out';
        MAX_N = 100010;

var fi,fo:text;
    n:longint;
    a,b:array[0..MAX_N] of longint;
    f:array[0..MAX_N,1..5] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do readln(fi,a[i],b[i]);
end;

procedure   solve;
var i,j,c,g:longint;
begin
    c:=0;   g:=6;
    for j:=1 to 5 do f[0][j]:=0;
    for i:=1 to n do begin
        for j:=1 to 5 do f[i][j]:=0;
        f[i][a[i]]:=f[i-1][a[i]]+1;
        f[i][b[i]]:=f[i-1][b[i]]+1;
        for j:=1 to 5 do
            if (f[i][j] > c) or ((f[i][j] = c) and (j < g)) then begin
                c:=f[i][j];
                g:=j;
            end;
    end;
    if c = 0 then g:=0;
    writeln(fo,c,' ',g);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.