const
    INPUT = 'CNMarble.inp';
    OUTPUT = 'CNMarble.out';
    MAX_N = 500000;

var
    N,M,S,P:longint;
    A,next:array[1..MAX_N] of longint;
    R:array[1..MAX_N] of ansiString;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    S:=0;
    for i:=1 to N do
        begin
            read(fi,A[i]);
            S:=S+A[i];
        end;
    close(fi);
    P:=S div M;
    for i:=1 to P-1 do next[i]:=i+1;
    next[P]:=1;
end;

procedure   Find;
var
    i,j,k:longint;
    tmp:ansiString;
begin
    k:=1;
    for i:=1 to N do
        begin
            str(i,tmp);
            for j:=1 to A[i] do
                begin
                    R[k]:=R[k]+tmp+' ';
                    k:=next[k];
                end;
        end;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to P do
        writeln(fo,R[i]);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.
