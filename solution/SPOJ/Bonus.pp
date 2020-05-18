const
    INPUT = 'Bonus.inp';
    OUTPUT = 'Bonus.out';
    MAX_N = 1000;

var
    N,K,maxF:longint;
    S:array[0..MAX_N,0..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i,j,v:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,K);
    for i:=1 to N do
        for j:=1 to N do
            begin
                read(fi,v);
                S[i,j]:=S[i-1,j]+S[i,j-1]-S[i-1,j-1]+v;
            end;
    close(fi);
end;

procedure   Find;
var
    i,j,F,i1,j1:longint;
begin
    maxF:=0;
    for i:=K to N do
        for j:=K to N do
            begin
                i1:=i-K;
                j1:=j-K;
                F:=S[i,j]-S[i,j1]-S[i1,j]+S[i1,j1];
                if F > maxF then maxF:=F;
            end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,maxF);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.