const
    INPUT = 'DTDoi.inp';
    OUTPUT = 'DTDoi.out';
    MAX_N = 100;

var
    N,S,minF:longint;
    A:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,S);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;

function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
procedure   Find(S:longint);
var
    i,j,k,maxA,max_i:longint;
    F:array[1..sqr(MAX_N)] of longint;
begin
    minF:=MAXLONGINT;
    k:=0;
    maxA:=A[1]; max_i:=1;
    for i:=2 to N do
        if A[i] > maxA then
            begin
                maxA:=A[i];
                max_i:=i;
            end;
    i:=sqr(MAX_N);
    if S > i then
        begin
            k:=(S-i) div A[max_i];
            if ((S-i) mod A[max_i]) <> 0 then inc(k);
            S:=S-k*A[max_i];
        end;
    F[1]:=1;
    for i:=2 to S do
        begin
            F[i]:=MAXLONGINT;
            for j:=1 to N do
                if A[j] >= i then
                    begin
                        if A[j] = i then F[i]:=1;
                        break;
                    end
                else F[i]:=min(F[i],F[i-A[j]]+1);
        end;
    minF:=F[S]+k;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,minF);
    close(fo);
end;

begin
    Enter;
    Find(S);
    Print_result;
end.