const
    INPUT = 'MaxArr1.inp';
    OUTPUT = 'MaxArr1.out';
    MAX_N = 100000;

var
    fi,fo:text;
    T,N,i:longint;
    A,F:array[0..MAX_N] of longint;

begin
    A[0]:=0;    A[1]:=1;
    F[0]:=0;    F[1]:=1;
    for i:=2 to MAX_N do
        begin
            if (i mod 2) = 0 then
                A[i]:=A[i div 2]
            else
                A[i]:=A[i div 2] + A[(i div 2)+1];
            if A[i] > F[i-1] then F[i]:=A[i]
            else F[i]:=F[i-1];
        end;
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            readln(fi,N);
            writeln(fo,F[N]);
        end;
    close(fo);
    close(fi);
end.