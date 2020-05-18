const
    INPUT = 'Prime1.inp';
    OUTPUT = 'Prime1.out';
    MAX_N = 1000000010;
    MAX_P = 32000;

var
    fi,fo:text;
    nTest,N,M,nP:longint;
    prime:array[0..MAX_P] of longint;

{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
    is_prime:array[2..MAX_P] of boolean;
begin
    nP:=0;
    for i:=2 to MAX_P do is_prime[i]:=true;
    for i:=2 to MAX_P do
        if is_prime[i] then begin
            inc(nP);
            prime[nP]:=i;
            j:=i+i;
            while j <= MAX_P do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;
{---------------------------------------------------------------------------}
function    is_prime(n:longint):boolean;
var
    i,limit:longint;
begin
    if n < 2 then exit(false);
    limit:=round(sqrt(n));
    for i:=1 to nP do begin
        if prime[i] > limit then exit(true);
        if (n mod prime[i]) = 0 then exit(false);
    end;
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=M to N do
        if is_prime(i) then writeln(fo,i);
    writeln(fo);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,M,N);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.