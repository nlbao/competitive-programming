const
    INPUT = 'Binary2.inp';
    OUTPUT = 'Binary2.out';
    MAX_N = 1000001;
    MAX_K = MAX_N;
    MODULO = 1000000000;

type
    int = longint;

var
    fi,fo:text;
    N,K,front,rear:longint;
    f:array[0..MAX_N+MAX_K,0..1] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    rear:=N+K+1;
    front:=rear-K;
    f[front,0]:=1;  f[front,1]:=1;
    for i:=front+1 to rear do begin
        f[i,0]:=0; f[i,1]:=0;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
    sum1,sum0,res:int;
begin
    sum0:=0;    sum1:=0;
    for i:=2 to N do begin
{tinh tien doan 1..K-1 -> 2..K}
        sum0:=(sum0-f[rear,0]+f[front,0]) mod MODULO;
        if sum0 < 0 then sum0:=sum0+MODULO;
        sum1:=(sum1-f[rear,1]+f[front,1]) mod MODULO;
        if sum1 < 0 then sum1:=sum1+MODULO;
        dec(rear);
{tinh f[1] moi}
        dec(front);
        f[front,0]:=sum1;   f[front,1]:=sum0;
    end;

    res:=0;
    for i:=1 to min(K,N) do begin
        res:=(res+(f[front,0]+f[front,1]) mod MODULO) mod MODULO;
        inc(front);
    end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    init;
    solve;
    close(fo);
    close(fi);
end.