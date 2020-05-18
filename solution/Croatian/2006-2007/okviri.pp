const   dx:array[1..8] of longint = (-2,-1,0,+1,+2,+1,0,-1);
        dy:array[1..8] of longint = (0,+1,+2,+1,0,-1,-2,-1);

var fi,fo:text;
    s:ansiString;
    y:array[0..100] of longint;
    f:array[0..6,0..100] of char;
    n,i,j,k,xx,yy:longint;
begin
    assign(fi,'okviri.in');     reset(fi);
    assign(fo,'okviri.out');    rewrite(fo);
    readln(fi,s);
    n:=length(s);
    y[1]:=3;
    for i:=2 to n do y[i]:=y[i-1]+4;
    for i:=1 to 5 do
        for j:=1 to y[n]+2 do f[i][j]:='.';
    for i:=1 to n do begin
        f[3][y[i]]:=s[i];
        for k:=1 to 8 do begin
            xx:=3+dx[k];
            yy:=y[i]+dy[k];
            if i mod 3 = 0 then f[xx][yy]:='*'
            else if f[xx][yy] = '.' then f[xx][yy]:='#';
        end;
    end;
    for i:=1 to 5 do begin
        for j:=1 to y[n]+2 do write(fo,f[i][j]);
        writeln(fo);
    end;
    close(fo);
    close(fi);
end.