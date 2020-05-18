const
    INPUT = 'V8Score.inp';
    OUTPUT = 'V8Score.out';
    MAX_S = 200;
    MAX_N = 20;
    MAX_K = 20;

var
    N,K,S:longint;
    A:array[1..MAX_N,1..MAX_K] of longint;
    F:array[1..MAX_K,1..MAX_S] of longint;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,S,K,N);
    for i:=1 to N do
        for j:=1 to K do
            read(fi,A[i,j]);
    close(fi);
end;

function    min(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   Find;
var
    i,j,t,tmp:longint;
begin
    for i:=1 to S do
        F[1,i]:=MAXLONGINT;
    for i:=1 to N do
        F[1,A[i,1]]:=A[i,1];
    for j:=2 to K do
        begin
            for i:=1 to S do F[j,i]:=MAXLONGINT;
            for i:=1 to N do
                for t:=1 to S do
                    if F[j-1,t] <= A[i,j] then
                        begin
                            tmp:=t+A[i,j];
                            if tmp > S then break;
                            if A[i,j] < F[j,tmp] then
                                begin
                                    F[j,tmp]:=A[i,j];
                                end;
                        end;
        end;
end;

procedure   Print_result;
var
    fo:text;
    j,tmp,count:longint;
    P:array[1..MAX_K] of longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    if F[K,S] = MAXLONGINT then write(fo,'NO')
    else
        begin
            writeln(fo,'YES');
            count:=0;
            j:=K;
            tmp:=S;
            while F[j,tmp] <> MAXLONGINT do
                begin
                    inc(count);
                    P[count]:=F[j,tmp];
                    tmp:=tmp-F[j,tmp];
                    dec(j);
                    if (tmp < 1) or (j < 1) then break;
                end;
            for j:=count downto 1 do
                write(fo,P[j],' ');
        end;

    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.