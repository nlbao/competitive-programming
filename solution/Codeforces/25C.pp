const
    INPUT = '25C.inp';
    OUTPUT = '25C.out';
    MAX_N = 310;
    MAX_K = 310;

var
    fi,fo:text;
    N:longint;
    w:array[0..MAX_N,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N);
    for i:=1 to N do
        for j:=1 to N do read(fi,w[i,j]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,K,u,v,c:longint;
    res:int64;
begin
    res:=0;
    for i:=1 to N-1 do
        for j:=i+1 to N do
            res:=res+w[i,j];
    readln(fi,K);
    while K > 0 do begin
        readln(fi,u,v,c);
        if c < w[u,v] then begin
            res:=0;
            w[u,v]:=c;  w[v,u]:=c;
            for i:=1 to N-1 do
                for j:=i+1 to N do begin
                    w[i,j]:=min(w[i,j],w[i,u]+c+w[v,j]);
                    w[i,j]:=min(w[i,j],w[i,v]+c+w[u,j]);
                    w[j,i]:=w[i,j];
                    res:=res+w[i,j];
                end;
        end;
        writeln(fo,res);
        dec(K);
    end;
end;
{---------------------------------------------------------------------------}
begin
    assign(fi,INPUT);  reset(fi);
    assign(fo,OUTPUT); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.