const
    INPUT = 'BCDIV.inp';
    OUTPUT = 'BCDIV.out';
    MAX_N = 21;

var
    fi,fo:text;
    T,N,K,i:longint;
    C:array[0..MAX_N,0..MAX_N] of longint;
    Kq:int64;

procedure   Prepare;
var
    i,j:longint;
begin
    for i:=0 to MAX_N do
        C[0,i]:=1;
    C[1,1]:=1;
    for i:=2 to MAX_N do
        C[i,1]:=0;
    for i:=2 to MAX_N do
        for j:=1 to i do
            C[j,i]:=C[j-1,i-1]+C[j,i-1];
end;

procedure   Find;
var
    i,j,S:longint;
    t:int64;
    a:array[1..MAX_N] of byte;
    check:boolean;
begin
    Kq:=0;
    for i:=1 to K-1 do
        a[i]:=1;
    a[K]:=N-K+1;
    repeat
        S:=N;
        t:=1;
        for i:=1 to K do
            begin
                t:=t*C[a[i],S];
                S:=S-a[i];
            end;
        Kq:=Kq+t;
        check:=true;
        t:=K-1;
        repeat
            for i:=t downto 1 do
                if a[i] <= a[i+1] then
                    begin
                        inc(a[i]);
                        for j:=i+1 to K do a[j]:=a[i];
                        break;
                    end;
            S:=0;
            for i:=1 to K do S:=S+a[i];
            if S > N then
                begin
                    check:=false;
                    dec(t);
                end
            else
                if S < N then a[K]:=a[K]+N-S;
        until (check = true) or (a[1]*K > N);
    until check = false;
    writeln(C[1,4],' ',C[3,3],' ',C[2,4],' ',C[2,2]);
end;

begin
    Prepare;
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            readln(fi,N,K);
            Find;
            writeln(fo,Kq);
        end;
    close(fo);
    close(fi);
end.