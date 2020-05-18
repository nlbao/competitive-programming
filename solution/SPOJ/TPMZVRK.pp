{$N+}

const
    INPUT = 'TPMZVRK.inp';
    OUTPUT = 'TPMZVRK.out';
    MAX_P2 = 202;
    modun = 15111992;

var
    fi,fo:text;
    A,B,Res,Res2:extended;
    p2:array[0..MAX_P2] of extended;

{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    p2[0]:=1;
    for i:=1 to MAX_P2 do
        p2[i]:=p2[i-1]*2;
end;
{---------------------------------------------------------------------------}
procedure   Enter(var X:extended);
var
    i,j:longint;
    s:string;
begin
    readln(fi,s);
    X:=0;
    j:=0;
    for i:=length(s) downto 1 do
        begin
            X:=X+(ord(s[i])-48)*p2[j];
            inc(j);
        end;
end;
{---------------------------------------------------------------------------}
{function    Rdiv(x,k:extended):extended;
var
    tmp:extended;
begin
    tmp:=x/k;
    exit(tmp-frac(tmp));
end;}
function    Rdiv(x,k:extended):extended;
begin
    exit(int(x/k));
end;
{---------------------------------------------------------------------------}
{function    Rmod(x,k:extended):extended;
begin
    exit(x-Rdiv(x,k)*k);
end;}
function    Rmod(x,k:extended):extended;
begin
    exit(x-Rdiv(x,k)*k);
end;
{---------------------------------------------------------------------------}
function    S(N:extended):extended;
var
    i:longint;
    l,r,mid,c:extended;
    tmp:extended;
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
                        mid:=Rdiv(l+r,2);
                        tmp:=p2[i];
                        tmp:=tmp*mid;
                        if tmp = N then break
                        else
                            if tmp < N then l:=mid+1
                            else r:=mid-1;
                    end;
                if tmp > N then mid:=mid-1;
                if Rmod(mid,2) = 0 then mid:=mid-1;
                c:=Rdiv(mid-1,2)+1;
                S:=S+Rmod(p2[i]*c,modun);
                S:=Rmod(S,modun);
                writeln(S:0:6);
            end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Init;
    Enter(A);
    Enter(B);
    Res:=S(B)-S(A);
    Res2:=Rdiv(Res,modun)*modun;
    writeln(Rmod(10000000000000000,9):0:0);
    writeln(Res);
    writeln(Res2);
    writeln(Res < Res2);
    writeln(Res-Res2);
    writeln(fo,{Rmod(S(B)-S(A),modun)}Rmod(Res,modun):0:0);
    close(fo);
    close(fi);
end.