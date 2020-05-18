const
    INPUT = 'MNERED.inp';
    OUTPUT = 'MNERED.out';
    MAX_N = 100;
    MAX_M = 10000;

type
    recA = record
        c,w:longint;
    end;
    recB = record
        x,y:longint;
    end;

var
    N,M:longint;
    A:array[1..MAX_N,1..MAX_N] of recA;
    B:array[1..sqr(MAX_N)] of recB;
    S:array[1..sqr(MAX_N),1..sqr(MAX_N)] of byte;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    close(fi);
end;

procedure   Init;
var
    i,j,k,t:longint;
begin
    k:=0;
    for i:=1 to N do
        for j:=1 to N do
            begin
                inc(k);
                B[k].x:=i;
                B[k].y:=j;
            end;
    S[1,1]:=A[1,1].w;
    for j:=2 to N do S[1,j]:=S[1,j-1]+A[1,j].w;
    for i:=2 to N do S[i,1]:=S[i-1,1]+A[i,1].w;
    for i:=2 to N do
        for j:=2 to N do
            if i = j then S[i,j]:=A[i,j].w
            else
                begin
                    S[i,j]:=S[i,j-1]
                end;

end;

begin
    Enter;
    Init;
end.