const
    INPUT = 'IOIBin.inp';
    OUTPUT = 'IOIBin.out';
    MAX_N = 10000;

var
    fi,fo:text;
    P,i,X,Y,Z:longint;
    parent:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    GetRoot(u:longint):longint;
begin
    if parent[u] < 0 then exit(u)
    else begin
        parent[u]:=GetRoot(parent[u]);
        exit(parent[u])
    end;
end;
{---------------------------------------------------------------------------}
procedure   Union(r1,r2:longint);
begin
    if parent[r1] < parent[r2] then begin
        parent[r1]:=parent[r1]+parent[r2];
        parent[r2]:=r1;
    end
    else begin
        parent[r2]:=parent[r1]+parent[r2];
        parent[r1]:=r2;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve(u,v,types:longint);
var
    r1,r2:longint;
begin
    r1:=GetRoot(u); r2:=GetRoot(v);
    if types = 1 then begin
        if r1 <> r2 then Union(r1,r2);
    end
    else
        if r1 = r2 then writeln(fo,1)
        else writeln(fo,0);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to MAX_N do parent[i]:=-1;
    readln(fi,P);
    for i:=1 to P do begin
        readln(fi,X,Y,Z);
        Solve(X,Y,Z);
    end;
    close(fo);
    close(fi);
end.