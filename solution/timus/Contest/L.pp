const
    INPUT = 'L.inp';
    OUTPUT = 'L.out';
    MAX_N = 310;
    MAX_M = 310;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,left[i].d);
    readln(fi,M);
    for i:=1 to M do read(fi,right[i].d);
end;

procedure   init(var x:arr; n:longint);
var
    i:longint;
begin
    x[1].f:=0;
    for i:=1 to n do
        with x[i] do begin
            s:=d*9/50;
            f:=(d+5)*9/50;
        end;
end;



begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init(left,N);
    init(right,M);
    solve;
    close(fo);
    close(fi);
end.