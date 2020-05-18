const
    INPUT = 'HelpPM.inp';
    OUTPUT = 'HelpPM.out';
    MAX_M = 500;
    MAX_N = 500;

var
    M,N,K,minS,x1,y1,x2,y2:longint;
    row:array[1..MAX_M,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i,j,tmp:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,M,N,K);
    for i:=1 to M do
        begin
            row[i,0]:=0;
            for j:=1 to N do
                begin
                    read(fi,tmp);
                    row[i,j]:=row[i,j-1]+tmp;
                end;
        end;
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    l,r,i,j,S,tong:longint;
    T:array[1..MAX_M] of longint;
begin
    minS:=MAXLONGINT;
    for l:=1 to N do
        for r:=l to N do
            begin
                i:=1;   j:=1;
                T[1]:=row[1,r]-row[1,l-1];
                tong:=t[1];
                while (i <= j) and (j <= N) do
                    if tong >= K then
                        begin
                            S:=(r-l+1)*(j-i+1);
                            if S < minS then
                                begin
                                    minS:=S;
                                    x1:=i;  y1:=l;
                                    x2:=j;  y2:=r;
                                end;
                            tong:=tong-T[i];
                            i:=i+1;
                        end
                    else
                        begin
                            j:=j+1;
                            T[j]:=row[j,r]-row[j,l-1];
                            tong:=tong+T[j];
                        end;
            end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    if minS = MAXLONGINT then writeln(fo,-1)
    else
        begin
            writeln(fo,minS);
            writeln(fo,x1,' ',y1,' ',x2,' ',y2);
        end;
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Solve;
    Print_result;
end.