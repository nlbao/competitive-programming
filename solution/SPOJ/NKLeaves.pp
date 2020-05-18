const
    INPUT = 'NKLeaves.inp';
    OUTPUT = 'NKLeaves.out';
    MAX_N = 100000;
    MAX_K = 10;

var
    N,K:longint;
    W:array[1..MAX_N] of longint;
    F,L:array[1..MAX_N,1..MAX_K] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,K);
    for i:=1 to N do
        read(fi,W[i]);
    close(fi);
end;

procedure   Find;
var
    i,j,F0:longint;
begin
    for j:=2 to K do
        begin
            F[1,j]:=-1;
            L[1,j]:=0;
        end;
    F[1,1]:=0;
    L[1,1]:=1;
    for i:=2 to N do
        begin
            F[i,1]:=F[i-1,1]+W[i]*(i-1);
            L[i,1]:=1;
        end;
    writeln;
    for i:=2 to N do
        for j:=2 to K do
            begin
            if i < j then
                begin
                    F[i,j]:=-1;
                    L[i,j]:=0;
                end
            else
                if i = j then
                    begin
                        F[i,j]:=0;
                        L[i,j]:=i;
                    end
                else
                    begin
                        F[i,j]:=F[i-1,j-1];
                        L[i,j]:=i;
                        if F[i-1,j] > -1 then
                            begin
                                F0:=F[i-1,j]+W[i]*(i-L[i-1,j]);
                                if F0 < F[i,j] then
                                    begin
                                        F[i,j]:=F0;
                                        L[i,j]:=L[i-1,j];
                                    end;
                            end;
                    end;
                writeln(i,' ',j,' ',F[i,j],' ',L[i,j]);
            end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,F[N,K]);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.