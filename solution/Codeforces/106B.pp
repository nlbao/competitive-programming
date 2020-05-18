const
    INPUT = '106B.inp';
    OUTPUT = '106B.out';
    MAX_N = 110;

var
    fi,fo:text;
    N:longint;
    speed,ram,hdd,cost:array[0..MAX_N] of longint;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do
        readln(fi,speed[i],ram[i],hdd[i],cost[i]);
end;

procedure   solve;
var
    i,j,minCost:longint;
    outdated:array[0..MAX_N] of boolean;
begin
    for i:=1 to N do outdated[i]:=false;
    for i:=1 to N do
        for j:=1 to N do
            if (speed[i] < speed[j]) and (ram[i] < ram[j]) and (hdd[i] < hdd[j]) then begin
                outdated[i]:=true;
                break;
            end;
    minCost:=MAXLONGINT;
    for i:=1 to N do
        if (not outdated[i]) and (cost[i] < minCost) then begin
            minCost:=cost[i];
            j:=i;
        end;
    writeln(fo,j);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.