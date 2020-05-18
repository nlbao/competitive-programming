const
    INPUT = 'NKMaxSEQ.inp';
    OUTPUT = 'NKMaxSEQ.out';
    MAX_N = 50000;

var
    N,P,Res:longint;
    A:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,P);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;

procedure   Find;
var
    M,i,j,min_S,l,r,mid:longint;
    S,T:array[1..MAX_N] of longint;
begin
    S[1]:=A[1];
    for i:=2 to N do
        S[i]:=S[i-1]+A[i];
    if S[N] >= P then
        begin
            Res:=N;
            exit;
        end;
    M:=0;
    min_S:=MAXLONGINT;
    for i:=1 to N-1 do
        if S[i] < min_S then
            begin
                min_S:=S[i];
                inc(M);
                T[M]:=i+1;
            end;
    if A[1] >= P  then Res:=1
    else Res:=0;
    for j:=2 to N do
        begin
            l:=1;   r:=M;
            repeat
                mid:=(l+r) div 2;
                i:=T[mid];
                if i >= j then r:=mid-1
                else
                    if S[j]-S[i-1] >= P then
                        begin
                            if (j-i+1) > Res then Res:=j-i+1;
                            r:=mid-1
                        end
                    else l:=mid+1;
            until l > r;
        end;
    if Res = 0 then Res:=-1;
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
