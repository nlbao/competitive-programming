const
    INPUT = 'NKDivSEQ.inp';
    OUTPUT = 'NKDivSEQ.out';
    MAX_N = 100000;

var
    N,Res:longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    close(fi);
end;

procedure   Find;
var
    i,j,count,s:longint;
    F:array[1..2*MAX_N] of longint;
begin
    F[1]:=1;
    count:=1;
    i:=1;
    while count < N do
        begin
            inc(i);
            s:=F[count]+1;
            while (s mod i) <> 0 do inc(s);
            for j:=1 to i do
                begin
                    inc(count);
                    F[count]:=s;
                    s:=s+i;
                end;
        end;
    Res:=F[N];
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.