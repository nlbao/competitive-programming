const
    INPUT = 'VRATF.inp';
    OUTPUT = 'VRATF.out';
    MAX_N = 1000000000;

var
    N,K,C:longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,K);
    close(fi);
    C:=0;
end;

procedure   Count(N:longint);
var
    X:longint;
begin
    X:=(N+K) div 2;
    if ((N+K) mod 2 = 0) and (X < N) then
        begin
            Count(X);
            Count(N-X);
        end
    else
        inc(C);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,C);
    close(fo);
end;

begin
    Enter;
    Count(N);
    Print_result;
end.