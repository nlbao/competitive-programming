const   INPUT = '129B.in';
        OUTPUT = '129B.out';
        MAX_N = 110;
        MAX_M = sqr(MAX_N);

var fi,fo:text;
    n,m:longint;
    a:array[0..MAX_N,0..MAX_N] of longint;
    deg:array[0..MAX_N] of longint;


procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do begin
        for j:=1 to n do a[i][j]:=0;
        deg[i]:=0;
    end;
    for i:=1 to m do begin
        readln(fi,u,v);
        a[u][v]:=1; a[v][u]:=1;
        inc(deg[u]);    inc(deg[v]);
    end;
end;

procedure   solve;
var i,j,k,res:longint;
    check:boolean;
begin
    res:=0;
    for i:=1 to n do begin
        check:=true;
        for j:=1 to n do
            if deg[j] = 1 then begin
                deg[j]:=0;
                check:=false;
            end;
        if check = true then break
        else inc(res);
        for j:=1 to n do
            if deg[j] = 0 then
                for k:=1 to n do
                    if (deg[k] > 0) and (a[j][k] = 1) then begin
                        dec(deg[k]);
                        a[j][k]:=0; a[k][j]:=0;
                    end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.