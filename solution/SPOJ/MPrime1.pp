const
    INPUT = 'MPrime1.inp';
    OUTPUT = 'MPrime1.out';
    MAX_N = 11010;

var
    fi,fo:text;
    N,nPrime:longint;
    is_prime:array[0..MAX_N] of boolean;
    prime,f,s:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Eratosthene;
var
    i,j:longint;
begin
    nPrime:=0;
    is_prime[1]:=false;
    for i:=2 to MAX_N do is_prime[i]:=true;
    for i:=1 to MAX_N do
        if is_prime[i] then begin
            inc(nPrime);
            prime[nPrime]:=i;
            j:=i+i;
            while j <= MAX_N do begin
                is_prime[j]:=false;
                inc(j,i);
            end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j,l,r,tmp:longint;
begin
    Eratosthene;
    s[0]:=0;
    for i:=1 to nPrime do
        s[i]:=s[i-1]+prime[i];
    for i:=1 to MAX_N do begin
        f[i]:=0;
        j:=nPrime;
        while prime[j] > i do dec(j);
        for r:=j-1 downto 1 do begin
            tmp:=i-prime[r];
            l:=1;
            while s[r-1]-s[l-1] > tmp do inc(l);
            if s[r-1]-s[l-1] = tmp then inc(f[i]);
        end;
        if is_prime[i] then inc(f[i]);
        {writeln(i,' ',f[i]);
        readln;}
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
begin
    repeat
        readln(fi,N);
        if N = 0 then break;
        writeln(fo,f[N]);
    until N = 0;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    solve;
    close(fo);
    close(fi);
end.