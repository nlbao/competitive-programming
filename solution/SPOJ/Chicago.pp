const
    INPUT = 'Chicago.inp';
    OUTPUT = 'Chicago.out';
    MAX_N = 110;

var
    fi,fo:text;
    N,M:longint;
    w,f:array[0..MAX_N,0..MAX_N] of double;

procedure   enter;
var
    i,u,v:longint;
begin
    for u:=1 to N do
        for v:=1 to N do w[u,v]:=0;
    for i:=1 to M do begin
        readln(fi,u,v,w[u,v]);
        w[u,v]:=w[u,v]/100;
        w[v,u]:=w[u,v];
    end;
end;


procedure   floyd;
var
    i,j,k:longint;
begin
    for i:=1 to N do
        for j:=1 to N do
            f[i,j]:=w[i,j];
    for k:=1 to N do
        for i:=1 to N do
            for j:=1 to N do
                if f[i,j] < f[i,k]*f[k,j] then
                    f[i,j]:=f[i,k]*f[k,j];
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,M);
    while N <> 0 do begin
        enter;
        floyd;
        writeln(fo,f[1,N]*100:0:6,' percent');
        readln(fi,N,M);
    end;
    close(fo);
    close(fi);
end.