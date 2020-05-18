const
    INPUT = '106D.inp';
    OUTPUT = '106D.out';
    MAX_N = 1001;
    MAX_M = 1001;
    MAX_K = 100001;

var
    fi,fo:text;
    N,M,K,nRes:longint;
    map:array[0..MAX_N,0..MAX_M] of char;
    dir:array[0..MAX_K] of char;
    len:array[0..MAX_K] of longint;
    north,south,west,east:array[0..MAX_N,0..MAX_M] of longint;
    res:array[0..100] of char;

procedure   enter;
var
    i,j:longint;
    s:ansiString;
begin
    fillchar(map,sizeof(map),'#');
    readln(fi,N,M);
    for i:=1 to N do begin
        readln(fi,s);
        for j:=1 to M do map[i,j]:=s[j];
    end;
    readln(fi,K);
    for i:=1 to K do
        readln(fi,dir[i],len[i]);
end;

procedure   init;
var
    i,j,t:longint;
begin
    for i:=1 to N do
        for j:=1 to M do
            if map[i,j] <> '#' then begin
                if map[i-1,j] <> '#' then begin
                    north[i,j]:=north[i-1,j]+1;
                    south[i,j]:=south[i-1,j]-1;
                end
                else begin
                    south[i,j]:=0;
                    t:=i+1;
                    while map[t,j] <> '#' do begin
                        inc(south[i,j]);
                        inc(t);
                    end;
                end;

                if map[i,j-1] <> '#' then begin
                    west[i,j]:=west[i,j-1]+1;
                    east[i,j]:=east[i,j-1]-1;
                end
                else begin
                    east[i,j]:=0;
                    t:=j+1;
                    while map[i,t] <> '#' do begin
                        inc(east[i,j]);
                        inc(t);
                    end;
                end;
            end;
end;

function    check(x,y:longint):boolean;
var
    i:longint;
begin
    for i:=1 to K do begin
        case dir[i] of
            'N': begin
                if north[x,y] < len[i] then exit(false);
                x:=x-len[i];
            end;
            'S': begin
                if south[x,y] < len[i] then exit(false);
                x:=x+len[i];
            end;
            'W': begin
                if west[x,y] < len[i] then exit(false);
                y:=y-len[i];
            end;
            'E': begin
                if east[x,y] < len[i] then exit(false);
                y:=y+len[i];
            end;
        end;
    end;
    exit(true);
end;

procedure   solve;
var
    i,j:longint;
begin
    nRes:=0;
    for i:=1 to N do
        for j:=1 to M do
            if (map[i,j] <> '#') and (map[i,j] <> '.') then
                if check(i,j) = true then begin
                    inc(nRes);
                    res[nRes]:=map[i,j];
                end;
end;

procedure   print_result;
var
    i,j:longint;
    tmp:char;
begin
    if nRes = 0 then writeln(fo,'no solution');
    for i:=1 to nRes-1 do
        for j:=i+1 to nRes do
            if res[i] > res[j] then begin
                tmp:=res[i];
                res[i]:=res[j];
                res[j]:=tmp;
            end;
    for i:=1 to nRes do write(fo,res[i]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    print_result;
    close(fo);
    close(fi);
end.
