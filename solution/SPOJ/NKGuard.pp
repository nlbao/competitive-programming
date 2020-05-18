const
    INPUT = 'NKGuard.inp';
    OUTPUT = 'NKGuard.out';
    MAX_N = 700;
    MAX_M = 700;

type
    recQ = record
        x,y:longint;
    end;

var
    N,M,Count:longint;
    A:array[0..MAX_N+1,0..MAX_N+1] of longint;
    avail,Top:array[0..MAX_N+1,0..MAX_N+1] of boolean;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    for i:=1 to N do
        for j:=1 to M do
            read(fi,A[i,j]);
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j,t,k:longint;
begin
for i:=0 to N+1 do
        begin
            A[i,0]:=-1; A[i,M+1]:=-1;
            avail[i,0]:=false;  avail[i,M+1]:=false;
        end;
    for j:=0 to M+1 do
        begin
            A[0,j]:=-1; A[N+1,j]:=-1;
            avail[0,j]:=false;  avail[N+1,j]:=false;
        end;
    for i:=1 to N do
        for j:=1 to M do
            begin
                avail[i,j]:=true;
                Top[i,j]:=true;
                for t:=i-1 to i+1 do
                    for k:=j-1 to j+1 do
                        if A[i,j] < A[t,k] then
                            begin
                                Top[i,j]:=false;
                                break;
                            end;
            end;

end;
{---------------------------------------------------------------------------}
procedure   Find;
var
    i,j,t,k,p,QSize:longint;
    Q:array[1..sqr(MAX_N)] of recQ;
    crTop,preTop:boolean;

    procedure   Add(i,j:longint);
    begin
        inc(QSize);
        Q[QSize].x:=j;  Q[QSize].y:=i;
        avail[i,j]:=false;
        crTop:=crTop and Top[i,j];
    end;
begin
    Count:=0;
    for i:=1 to N do
        for j:=1 to M do
            if avail[i,j] then
                begin
                    QSize:=1;
                    Q[1].x:=j;  Q[1].y:=i;
                    avail[i,j]:=false;
                    if Top[i,j] then inc(Count);
                    crTop:=Top[i,j];
                    p:=0;
                    repeat
                        inc(p);
                        preTop:=crTop;
                        for t:=Q[p].y-1 to Q[p].y+1 do
                            for k:=Q[p].x-1 to Q[p].x+1 do
                                if (A[t,k] = A[Q[p].y,Q[p].x]) and (avail[t,k]) then Add(t,k);
                        if crTop <> preTop then dec(Count);
                    until QSize = p;
                end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Count);
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Init;
    Find;
    Print_result;
end.