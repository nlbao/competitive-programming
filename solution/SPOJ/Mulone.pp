const
    INPUT = 'Mulone.inp';
    OUTPUT = 'Mulone.out';
    MAX_N = 1000000;

var
    fi,fo:text;
    K,N,i:longint;
    Kq:ansistring;
    S:array[1..MAX_N] of ansistring;

function    ch(x:byte):char;
begin
    exit(chr(ord(x)+48));
end;

procedure   Find;
var
    i,t,r:longint;
begin
    if S[N] <> '' then
        begin
            Kq:=S[N];
            exit;
        end;
    S[N]:='';
    t:=0;
    for i:=1 to N do
        begin
            t:=t+i;
            r:=t mod 10;
            t:=t div 10;
            S[N]:=ch(r)+S[N];
        end;
    for i:=N-1 downto 1 do
        begin
            t:=t+i;
            r:=t mod 10;
            t:=t div 10;
            S[N]:=ch(r)+S[N];
        end;
    Kq:=S[N];
end;

begin
    S[1]:='11';
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,K);
    for i:=1 to K do
        begin
            readln(fi,N);
            Find;
            writeln(fo,N,' ',Kq);
        end;
    close(fo);
    close(fi);
end.