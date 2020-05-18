const
    INPUT = 'PCircle.inp';
    OUTPUT = 'PCircle.out';
    MAX_N = 10;
    MAX_M = 2*MAX_N;
    MAX_K = 10000;

var
    fi,fo:text;
    N,M,nRes:longint;
    is_prime,avail:array[0..10*MAX_M] of boolean;
    f:array[0..MAX_M] of longint;
    res:array[0..MAX_K,0..MAX_M] of longint;
    count:array[1..MAX_N] of longint = (1,2,2,4,96,1024,2880,81024,770144,6309300);

{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    readln(fi,N);
    M:=10*N;
    for i:=2 to M do is_prime[i]:=true;
    for i:=2 to M do
        if is_prime[i] then begin
            j:=i+i;
            while j <= M do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
    M:=M div 5;
end;
{---------------------------------------------------------------------------}
procedure   try_f(i:longint);
var
    j:longint;
begin
    if nRes >= MAX_K then exit;
    if i > M then begin
        if is_prime[f[1]+f[M]] then begin
            inc(nRes);
            for j:=1 to M do
                res[nRes,j]:=f[j];
        end;
        exit;
    end;
    for j:=1 to M do begin
        if (avail[j]) and (is_prime[j+f[i-1]]) then begin
            avail[j]:=false;
            f[i]:=j;
            try_f(i+1);
            avail[j]:=true;
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    f[1]:=1;
    for i:=2 to M do avail[i]:=true;
    avail[1]:=false;
    nRes:=0;
    try_f(2);
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,j:longint;
begin
    writeln(fo,count[N]);
    for i:=1 to nRes do begin
        for j:=1 to M do write(fo,res[i,j],' ');
        writeln(fo);
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    solve;
    print_result;
    close(fo);
    close(fi);
end.