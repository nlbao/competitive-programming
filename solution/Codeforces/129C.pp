const   INPUT = '129C.in';
        OUTPUT = '129C.out';
        N = 8; M = 8;
        dx:array[1..9] of longint = (0,0,-1,+1,-1,-1,+1,+1,0);
        dy:array[1..9] of longint = (-1,+1,0,0,-1,+1,-1,+1,0);

var fi,fo:text;
    a:array[0..N+1,0..M+1] of char;
    f,t:array[0..N+1,0..M+1] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
begin
    for i:=0 to N+1 do
        for j:=0 to M+1 do
            a[i][j]:='S';
    for i:=1 to N do begin
        for j:=1 to M do read(fi,a[i][j]);
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k,x,y:longint;
    check:boolean;
begin
    for i:=0 to N+1 do
        for j:=0 to M+1 do
            f[i][j]:=0;
    f[N][1]:=1;
    repeat
        check:=false;
        t:=f;
        for i:=0 to N+1 do
            for j:=0 to M+1 do
                f[i][j]:=0;
        for x:=1 to N do
            for y:=1 to M do
                if t[x][y] = 1 then begin
                    for k:=1 to 9 do begin
                        i:=x+dx[k]; j:=y+dy[k];
                        if a[i][j] <> 'S' then f[i][j]:=1;
                    end;
                    check:=true;
                end;
        if f[1][M] > 0 then break;
        for i:=N downto 1 do
            for j:=1 to M do
                if a[i][j] = 'S' then begin
                    if f[i+1][j] > 0 then f[i+1][j]:=0;
                    a[i+1][j]:='S'; a[i][j]:='.';
                end;
    until (check = false) or (f[1][M] > 0);
    if f[1][M] > 0 then writeln(fo,'WIN')
    else writeln(fo,'LOSE');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.