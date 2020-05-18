const
    INPUT = 'CatGo.inp';
    OUTPUT = 'CatGo.out';
    MAX_N = 51;
    MAX_M = 51;
    MAX_L = 51;
    MAX_nC = MAX_N*MAX_L;

var
    fi,fo:text;
    N,M:longint;
    l,nC:array[0..MAX_N] of longint;
    value:array[0..MAX_L] of longint;
    g:array[0..MAX_L,0..MAX_nC] of longint;
    f:array[0..MAX_N,0..MAX_nC] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N);
    l[0]:=0;
    for i:=1 to N do read(fi,l[i]);
    readln(fi,M);
    for i:=0 to MAX_L do value[i]:=0;
    for i:=1 to M do
        readln(fi,j,value[j]);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   tinh_g;
var
    i,j,k:longint;
begin
    for j:=0 to MAX_L-1 do g[0,j]:=0;
    for i:=0 to MAX_L do g[i,0]:=value[i];
    for i:=1 to MAX_L do
        for j:=1 to i-1 do begin
            g[i,j]:=0;
            for k:=j to i-1 do
                g[i,j]:=max(g[i,j],g[k,j-1]+value[i-k]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   tinh_f;
var
    i,j,k:longint;
begin
    for j:=0 to nC[N] do f[0,j]:=0;
    f[0,0]:=0;
    for i:=1 to N do
        f[i,0]:=f[i-1,0]+value[l[i]];
    for i:=1 to N do
        for j:=1 to nC[i] do begin
            f[i,j]:=0;
            for k:=max(j-l[i]+1,0) to j do
                f[i,j]:=max(f[i,j],f[i-1,k]+g[l[i],j-k]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,res:longint;
begin
    nC[0]:=0;
    for i:=1 to N do
        nC[i]:=nC[i-1]+l[i]-1;
    tinh_g;
    tinh_f;
    res:=0;
    for i:=0 to nC[N] do
        res:=max(res,f[N,i]-(i*(i+1)) div 2);
    writeln(fo,res);
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