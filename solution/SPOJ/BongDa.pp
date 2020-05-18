const
    INPUT = 'BongDa.inp';
    OUTPUT = 'BongDa.out';
    MAX_N  = 30;

var
    N:longint;
    A:array[1..MAX_N,1..MAX_N] of byte;
    d,T,idx,F:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        for j:=1 to N do
            read(fi,A[i,j]);
    close(fi);
    for i:=1 to N do
        begin
            d[i]:=0;
            for j:=1 to N do
                if A[i,j] <> 0 then
                    d[i]:=d[i]+3;
        end;
end;

procedure   Swap(var x,y:longint);
var
    t:longint;
begin
    t:=x;
    x:=y;
    y:=t;
end;

procedure   Quick_sort(l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=T[(l+r) div 2];
    repeat
        while T[i] > p do inc(i);
        while T[j] < p do dec(j);
        if i <=j then
            begin
                Swap(T[i],T[j]);
                Swap(idx[i],idx[j]);
                inc(i);
                dec(j);
            end;
    until i >= j;
    if i < r then Quick_sort(i,r);
    if l < j then Quick_sort(l,j);
end;

function    check(X:longint):boolean;
var
    i,j:longint;
begin
    check:=true;
    j:=0;
    for i:=1 to N do
        if i <> X then
            begin
                inc(j);
                T[j]:=d[i];
                if A[i,X] = 2 then
                    T[j]:=T[j]-3;
                idx[j]:=i;
            end;
    Quick_sort(1,N-1);
    {writeln(X,' ',D[X]);
    for i:=1 to N-1 do
        writeln(idx[i],' ',T[i]);}
    for i:=1 to N-1 do
        begin
            j:=N;
            while (T[i] > d[X]) and (j > i+1) do
                begin
                    dec(j);
                    if A[idx[i],idx[j]] = 2 then
                        {begin
                            writeln('  ',idx[i],' ',idx[j]);}
                        T[i]:=T[i]-3;
                        {end;}
                end;
            if T[i] > d[X] then
                {begin
                    writeln('!!! ',idx[i]);}
                    exit(false);
                {end;}
        end;
    {writeln;}
end;

procedure   Find;
var
    i:longint;
begin
    for i:=1 to N do
        begin
            if check(i) = true then F[i]:=1
            else F[i]:=0;
        end;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to N do
        write(fo,F[i]);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.
