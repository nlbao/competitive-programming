const
    INPUT = 'ILSMath.inp';
    OUTPUT = 'ILSMath.out';
    MAX_N = 2000000;

var
    N,M:longint;
    X:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    close(fi);
end;


function    log(a,b:longint):real;
begin
    exit(ln(b)/ln(a));
end;

procedure   Find;
var
    i:longint;
    S:real;
begin
    if N < 1 then exit;
    if N = 1 then
        begin
            M:=4;
            X[1]:=0;    X[2]:=1;
            X[3]:=2;    X[4]:=3;
            exit;
        end;
    M:=0;
    S:=0;
    for i:=1 to MAX_N do
        begin
            S:=S+log(10,i);
            if S > N then break
            else
                if S > N-1 then
                    begin
                        inc(M);
                        X[M]:=i;
                    end;
        end;
    S:=0;
    for i:=1 to 100000 do
        begin
            S:=S+log(10,i);
        end;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    if M = 0 then
        write(fo,'NO')
    else
        begin
            writeln(fo,M);
            for i:=1 to M do
                writeln(fo,X[i]);
        end;
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.
