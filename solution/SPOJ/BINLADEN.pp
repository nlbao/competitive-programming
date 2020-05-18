const
    INPUT = 'BINLADEN.inp';
    OUTPUT = 'BINLADEN.out';
    MAX_M = 2222;
    MAX_N = 10;

type
    recA = record
        left,right,down:longint;
    end;


var
    M,N,minF:longint;
    A:array[0..MAX_M,1..MAX_N] of recA;
    F:array[0..MAX_M,1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i,j:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,M,N);
    if N = 1 then
        begin
            minF:=0;
            while not eof(fi) do
                begin
                    read(fi,j);
                    minF:=minF+j;
                end;
            exit;
        end;
    for i:=1 to M do
        begin
            for j:=1 to N do
                read(fi,A[i-1,j].down);
            read(fi,A[i,1].right);
            for j:=2 to N-1 do
                begin
                    read(fi,A[i,j].right);
                    A[i,j].left:=A[i,j-1].right;
                end;
            A[i,N].left:=A[i,N-1].right;
        end;
    close(fi);
end;

function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;

procedure   Find;
var
    i,j,k,tmp:longint;
begin
    for j:=1 to N do F[0,j]:=0;
    for i:=1 to M do
        for j:=1 to N do
            begin
                tmp:=F[i-1,1]+A[i-1,1].down;
                for k:=2 to j do
                    tmp:=min(tmp+A[i,k].left,F[i-1,k]+A[i-1,k].down);
                F[i,j]:=tmp;
                tmp:=F[i-1,N]+A[i-1,N].down;
                for k:=N-1 downto j do
                    tmp:=min(tmp+A[i,k].right,F[i-1,k]+A[i-1,k].down);
                F[i,j]:=min(F[i,j],tmp);
            end;
    minF:=F[M,N];
    {for i:=1 to M do
        begin
            for j:=1 to N do
                writeln(i,' ',j,' ',A[i,j].left,' ',A[i,j].right,' ',A[i,j].down);

        end; }
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
    if N <> 1 then Find;
    Print_result;
end.