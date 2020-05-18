const
    INPUT = 'NKNumFre.inp';
    OUTPUT = 'NKNumFre.out';
    MAX_N = 30000;

var
    A,B:longint;
    F:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,A,B);
    close(fi);
end;

function    UCLN(x,y:longint):longint;
var
    r:longint;
begin
    r:=x mod y;
    while r <> 0 do
        begin
            x:=y;
            y:=r;
            r:=x mod y;
        end;
    exit(y);
end;

procedure   Count;
var
    i,j,err:longint;
    S1,S2:ansistring;
begin
    F[9]:=0;
    for i:=10 to B do
        begin
            F[i]:=F[i-1];
            str(i,S1);
            S2:='';
            for j:=length(S1) downto 1 do
                S2:=S2+S1[j];
            val(S2,j,err);
            if UCLN(i,j) = 1 then
                inc(F[i]);
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,F[B]-F[A-1]);
    close(fo);
end;

begin
    Enter;
    Count;
    Print_result;
end.