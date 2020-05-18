const
    INPUT = 'Coins.inp';
    OUTPUT = 'Coins.out';
    MAX_N = 1000000010;

var
    fi,fo:text;
    N:longint;
    g:array[0..1000000] of longint;

{---------------------------------------------------------------------------}
function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    for i:=0 to 4 do g[i]:=i;
    for i:=5 to 1000000 do
        g[i]:=max(i,g[trunc(i div 2)]+g[trunc(i div 3)]+g[trunc(i div 4)]);
end;
{---------------------------------------------------------------------------}
function    f(n:longint):int64;
begin
    if n < 1000001 then exit(g[n]);
    exit(max(n,f(trunc(n div 2))+f(trunc(n div 3))+f(trunc(n div 4))));
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    while not eof(fi) do begin
        readln(fi,N);
        writeln(fo,f(N));
    end;
    close(fo);
    close(fi);
end.