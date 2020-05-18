const
    INPUT = '1086.inp';
    OUTPUT = '1086.out';
    MAX_N = 200000;

var
    fi,fo:text;
    N,K,nPrime:longint;
    is_prime:array[0..MAX_N] of boolean;
    prime:array[0..MAX_N] of longint;

procedure   prime_sieve;
var
    i,j:longint;
begin
    nPrime:=0;
    for i:=2 to MAX_N do is_prime[i]:=true;
    for i:=2 to MAX_N do
        if is_prime[i] then begin
            inc(nPrime);
            prime[nPrime]:=i;
            j:=i+i;
            while j <= MAX_N do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    prime_sieve;
    readln(fi,K);
    while K > 0 do begin
        readln(fi,N);
        writeln(fo,prime[N]);
        dec(K);
    end;
    close(fo);
    close(fi);
end.