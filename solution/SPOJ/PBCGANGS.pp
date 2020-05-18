const
    INPUT = 'PBCGANGS.inp';
    OUTPUT = 'PBCGANGS.out';
    MAX_N = 1000;
    MAX_M = 5000;

var
    N,M,Count:longint;
    W:array[1..MAX_N,1..MAX_N] of longint;
    headF,headE:array[1..MAX_N+1] of longint;
    adjF,adjE:array[1..2*MAX_M] of longint;

procedure   Enter;
var
    fi:text;
    i,j,k:longint;
    ch:char;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        for j:=1 to N do
            W[i,j]:=0;
    readln(fi,M);
    for k:=1 to M do
        begin
            readln(fi,ch,i,j);
            if ch = 'F' then
                begin
                    W[i,j]:=1;
                    W[j,i]:=1;
                end
            else
                begin
                    W[i,j]:=-1;
                    W[j,i]:=-1;
                end;
        end;
    close(fi);
    headF[1]:=0;
    headE[1]:=0;
    for i:=1 to N do
        begin
            headF[i+1]:=headF[i];
            headE[i+1]:=headE[i];
            for j:=1 to N do
                if W[i,j] = 1 then
                    begin
                        inc(headF[i+1]);
                        adjF[headF[i+1]]:=j;
                    end
                else
                    if W[i,j] = -1 then
                        begin
                            inc(headE[i+1]);
                            adjE[headE[i+1]]:=j;
                        end;
        end;
end;

procedure   Find;
var
    i,j,k,u,QSize:longint;
    avail:array[1..MAX_N] of boolean;
    Q:array[1..MAX_N] of longint;
    procedure   Add(i:longint);
    begin
        inc(QSize);
        Q[QSize]:=i;
        avail[i]:=false;
    end;
begin
    for i:=1 to N do
        avail[i]:=true;
    Count:=1;
    QSize:=1;
    Q[1]:=1;
    avail[1]:=false;
    i:=0;
    repeat
        inc(i);
        u:=Q[i];
        for j:=headF[u]+1 to headF[u+1] do
            if avail[adjF[j]] then
                Add(adjF[j]);
        for j:=headE[u]+1 to headE[u+1] do
            for k:=headE[adjE[j]]+1 to headE[adjE[j]+1] do
                if avail[adjE[k]] then
                    Add(adjE[k]);
        if i = QSize then
            for j:=1 to N do
                if avail[j] then
                    begin
                        Add(j);
                        inc(Count);
                        break;
                    end;
    until i = QSize;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Count);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.