const
    INPUT = '116B.inp';
    OUTPUT = '116B.out';
    MAX_N = 11;
    MAX_M = 11;

var
    fi,fo:text;
    N,M:longint;
    map:array[0..MAX_N,0..MAX_M] of char;

procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N,M);
    for i:=0 to N+1 do
        for j:=0 to M+1 do
            map[i,j]:='.';
    for i:=1 to N do begin
        for j:=1 to M do read(fi,map[i,j]);
        readln(fi);
    end;
end;

procedure   solve;
var
    i,j,count:longint;
begin
    count:=0;
    for i:=1 to N do
        for j:=1 to M do
            if map[i,j] = 'W' then
                if (map[i-1,j] = 'P') or (map[i+1,j] = 'P') or (map[i,j-1] = 'P') or (map[i,j+1] = 'P') then
                    inc(count);
    writeln(fo,count);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.