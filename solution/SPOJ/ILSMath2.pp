{$N+}
const
    INPUT = 'ILSMath2.inp';
    OUTPUT = 'ILSMath2.out';
    MAX_N = 1000000000;
    MAX_X = 1000000000;

var
    fi,fo:text;
    N,X,l,r,mid:longint;
    tmp:extended;

function    log(a:longint;  b:extended):extended;
begin
    exit(ln(b)/ln(a));
end;

function    logF(N:longint):real;
var
    i:longint;
    M:int64;
    S:extended;
begin
    if N < 255 then
        begin
            S:=0;
            for i:=1 to N do S:=S+log(10,i);
        end
    else
        begin
            M:=N+1;
            S:=(M-0.5)*ln(M)-M+0.5*ln(2*pi)+1/(12*M);
            S:=S/ln(10);
        end;
    exit(S);
end;

begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    close(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    if N = 1 then
        begin
            writeln(fo,3);
            writeln(fo,1);
            writeln(fo,2);
            writeln(fo,3);
        end;
    if N = 3 then
        begin
            writeln(fo,2);
            writeln(fo,5);
            writeln(fo,6);
        end;
    if (N <> 1) and (N <> 3) then
        begin
            X:=0;
            l:=1;   r:=MAX_X;
            while l <= r do
                begin
                    mid:=(l+r) div 2;
                    tmp:=logF(mid);
                    if tmp < N-1 then l:=mid+1
                    else
                        if tmp > N then r:=mid-1
                        else
                            begin
                                X:=mid;
                                break;
                            end;
                end;
            if X = 0 then writeln(fo,'NO')
            else
                begin
                    writeln(fo,1);
                    writeln(fo,X);
                end;
        end;
    close(fo);
end.