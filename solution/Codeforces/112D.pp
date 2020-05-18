const
    INPUT = '112D.inp';
    OUTPUT = '112D.out';
    MAX_N = 100000;
    MAX_X = 100000;
    MAX_nD = 200;

var
    fi,fo:text;
    N,i,x,y:longint;
    d:array[0..MAX_X,0..MAX_nD] of longint;
    pos:array[0..MAX_X] of longint;

procedure   init;
var
    i,j:longint;
begin
    for i:=1 to MAX_X do d[i,0]:=0;
    for i:=1 to MAX_X do begin
        j:=i;
        while j <= MAX_X do begin
            inc(d[j,0]);
            d[j,d[j,0]]:=i;
            j:=j+i;
        end;
    end;
    pos[1]:=N+1;
    for i:=2 to MAX_X do pos[i]:=0;
end;

procedure   solve(id:longint);
var
    i,j,k,count:longint;
begin
    if id = 1 then count:=1
    else count:=0;
    j:=id-y;
    for i:=1 to d[x,0] do begin
        k:=d[x,i];
        if pos[k] < j then inc(count);
        pos[k]:=id;
    end;
    writeln(fo,count);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,N);
    for i:=1 to N do begin
        readln(fi,x,y);
        solve(i);
    end;
    close(fo);
    close(fi);
end.