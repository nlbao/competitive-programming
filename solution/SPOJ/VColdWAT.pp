const
    INPUT = 'VColdWAT.inp';
    OUTPUT = 'VColdWAT.out';
    MAX_N = 99999;
    MAX_C = 99999;

type
    recA = record
        left,right:longint;
    end;

var
    N,C:longint;
    A:array[1..MAX_C] of recA;
    idx,F:array[1..MAX_N] of longint;


procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,C);
    for i:=1 to N do idx[i]:=0;
    for i:=1 to C do
        begin
            read(fi,j,A[i].left,A[i].right);
            idx[j]:=i;
        end;
    close(fi);
end;

procedure   Find;
var
    i,j,QSize:longint;
    avail:array[1..MAX_N] of boolean;
    Q:array[1..MAX_N] of longint;

    procedure   Add(x,pre:longint);
    begin
        if not avail[x] then exit;
        inc(QSize);
        Q[QSize]:=x;
        avail[x]:=false;
        F[x]:=F[pre]+1;
    end;

begin
    F[1]:=1;
    Q[1]:=1;
    QSize:=1;
    avail[1]:=false;
    for i:=2 to N do avail[i]:=true;
    i:=0;
    repeat
        inc(i);
        j:=idx[Q[i]];
        if j > 0 then
            begin
                Add(A[j].left,Q[i]);
                Add(A[j].right,Q[i]);
            end;
    until QSize = i;
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to N do
        writeln(fo,F[i]);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.