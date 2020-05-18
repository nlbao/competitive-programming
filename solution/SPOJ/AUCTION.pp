const
    INPUT = 'AUCTION.inp';
    OUTPUT = 'AUCTION.out';
    MAX_N = 1000;
    MAX_M = 1000;

var
    N,M,maxS,minX:longint;
    P:array[1..MAX_M] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    for i:=1 to M do read(fi,P[i]);
    close(fi);
end;

procedure   Quick_sort(l,r:longint);
var
    i,j,mid,tmp:longint;
begin
    i:=l;   j:=r;
    mid:=P[(i+j) div 2];
    repeat
        while P[i] < mid do inc(i);
        while P[j] > mid do dec(j);
        if i <= j then
            begin
                tmp:=P[i];
                P[i]:=P[j];
                P[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;

procedure   Find;
var
    i,j,X,S:longint;
begin
    minX:=0;    maxS:=0;
    for i:=1 to M do
        begin
            X:=P[i];
            j:=(M-i+1);
            if j > N then j:=N;
            S:=j*X;
            if S > maxS then
                begin
                    maxS:=S;
                    minX:=X;
                end;
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,minX,' ',maxS);
    close(fo);
end;

begin
    Enter;
    Quick_sort(1,M);
    Find;
    Print_result;
end.