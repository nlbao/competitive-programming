const
    INPUT = 'MZVRK.inp';
    OUTPUT = 'MZVRK.out';
    MAX_B = 1000000000000000;
    MAX_P2 = 50;

var
    fi,fo:text;
    A,B:int64;
    p2:array[0..MAX_P2] of int64;

procedure   Init;
var
    i:longint;
begin
    p2[0]:=1;
    for i:=1 to MAX_P2 do
        p2[i]:=p2[i-1]*2;
end;

function    S(N:int64):int64;
var
    i:longint;
    l,r,mid,c:int64;
    tmp:double;
begin
    S:=0;
    if N = 0 then exit;
    for i:=0 to MAX_P2 do
        if p2[i] > N then break
        else
            begin
                l:=1;   r:=N;
                while l <= r do
                    begin
                        mid:=(l+r) div 2;
                        tmp:=p2[i];
                        tmp:=tmp*mid;
                        if tmp = N then break
                        else
                            if tmp < N then l:=mid+1
                            else r:=mid-1;
                    end;
                if tmp > N then mid:=mid-1;
                if (mid mod 2) = 0 then mid:=mid-1;
                c:=((mid-1) div 2)+1;
                S:=S+p2[i]*c;
            end;
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,A,B);
    Init;
    writeln(fo,S(B)-S(A-1));
    close(fo);
    close(fi);
end.