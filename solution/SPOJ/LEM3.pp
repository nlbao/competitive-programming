const
    INPUT = 'LEM3.inp';
    OUTPUT = 'LEM3.out';
    MAX_N = 15;

var
    N:longint;
    C:array[0..MAX_N,1..MAX_N] of longint;
    minS,S,minSC:longint;
    avail:array[1..MAX_N] of boolean;
    F,minC:array[0..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        for j:=1 to N do
            read(fi,C[i,j]);
    close(fi);
    for j:=1 to N do
        C[0,j]:=0;
end;

procedure   TryF(i:longint);
var
    j:longint;
begin
    if i > N then
        begin
            if S < minS then
                minS:=S;
        end
    else
        for j:=1 to N do
            if avail[j] then
                begin
                    F[i]:=j;
                    avail[j]:=false;
                    S:=S+C[F[i-1],j];
                    minSC:=minSC-minC[j];
                    if S+minSC < minS then
                        TryF(i+1);
                    minSC:=minSC+minC[j];
                    S:=S-C[F[i-1],j];
                    avail[j]:=true;
                    F[i]:=0;
                end;
end;

procedure   Find;
var
    i,j:longint;
begin
    for i:=1 to N do
        begin
            F[i]:=0;
            avail[i]:=true;
        end;
    minSC:=0;
    for j:=1 to N do
        begin
            minC[j]:=MAXLONGINT;
            for i:=1 to N do
                if (C[i,j] < minC[j]) and (i <> j) then
                    minC[j]:=C[i,j];
            minSC:=minSC+minC[j];
        end;
    minS:=MAXLONGINT;
    S:=0;
    F[0]:=0;
    TryF(1);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,minS);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.