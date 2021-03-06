const
    INPUT = 'MPrime.inp';
    OUTPUT = 'MPrime.out';
    MAX_K = 500;
    MAX_N = 1000000;

var
    N,M,K:longint;
    Res:real;
    is_prime:array[2..MAX_N] of boolean;
    prime:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,K);
    close(fi);
end;

procedure   Eratosthenes(N:longint);
var
    i,j:longint;
begin
    for i:=2 to N do is_prime[i]:=true;
    for i:=2 to (N div 2) do
        if is_prime[i] then
            begin
                inc(M);
                prime[M]:=i;
                j:=i+i;
                while j <= N do
                    begin
                        is_prime[j]:=false;
                        j:=j+i;
                    end;
            end;
end;

function    isPrime(X:int64):boolean;
var
    i:longint;
begin
    if X < 2 then exit(false)
    else
        if X = 2 then exit(true);
    for i:=1 to M do
        if sqr(prime[i]) > X then break
        else
            if X mod prime[i] = 0 then
                begin
                    writeln(prime[i]);
                    exit(false);
                end;
    exit(true);
end;

function    power(a,x,p:real):real;
var
   k:int64;
begin
    if x = 0 then exit(1);
    k:=trunc(x) div 2;
    k:=trunc(sqr(power(a,k,p))) mod trunc(p);
    if (trunc(x) mod 2) = 0 then exit(k)
    else exit(trunc(k*a) mod trunc(p));
end;

function    MillerRabin_test(P:real):boolean;
var
    i,k,s:longint;
    m,a,b:real;
    check:boolean;
begin
    if P = 2 then exit(true);
    if (P < 2) or ((trunc(P) mod 2) = 0) then exit(false);
    m:=P-1;
    s:=0;
    while (trunc(m) mod 2) = 0 do
        begin
            m:=trunc(m) div 2;
            inc(s);
        end;
    writeln(P:0:0);
    for i:=1 to 5 do
        begin
            check:=false;
            a:=0;
            while (a = 0) or (a >= P) do a:=random(trunc(P)-1);
            {write(a,' ');}
            b:=power(a,m,P);
            {writeln(b);}
            if b = 1 then check:=true
            else
                begin
                    for k:=0 to s-1 do
                        begin
                            if (trunc((b+1)) mod trunc(P)) = 0 then
                                begin
                                    check:=true;
                                    break;
                                end;
                            b:=trunc(sqr(b)) mod trunc(P);
                        end;
                    if check = false then exit(false);
                end;
        end;
    exit(true);
end;


procedure   Find;
var
    i,count,err:longint;
    s1,s2,s:string;
begin
    Res:=1000000000000000000000;
    writeln(Res);
    readln;
    randomize;
    count:=0;
    i:=1;
    {for count:=2 to 100000 do
        begin
            i:=count;
            if is_prime[i] <> MillerRabin_test(i) then writeln(i);
        end;}
    repeat
        str(prime[i],s1);
        str(prime[i+1],s2);
        s:=s1+s2;
        val(s,Res,err);
        if MillerRabin_test(Res) = true then inc(count);
        inc(i,2);
    until (i >= M) or (count = K);
    {writeln(isPrime(trunc(Res)));}
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res:0:0);
    close(fo);
end;

begin
    Enter;
    Eratosthenes(MAX_N);
    Find;
    Print_result;
end.        
