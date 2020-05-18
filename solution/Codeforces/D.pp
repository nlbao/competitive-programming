const
    INPUT = 'input.txt';
    OUTPUT = 'output.txt';
    MAX_N = 100;
    MAX_M = 100;

var
    fi,fo:text;
    N,M,A,B,C,res:longint;
    map:array[0..MAX_N,0..MAX_M] of longint;

procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N,M);
    for i:=1 to N do
        for j:=1 to M do read(fi,map[i,j]);
    readln(fi,A,B,C);
end;

procedure   count_row;
var
    i,j:longint;
    row:array[0..MAX_N] of longint;
begin
    row[0]:=0;
    for i:=1 to N do begin
        row[i]:=row[i-1];
        for j:=1 to M do inc(row[i],map[i,j]);
    end;
    row[N+1]:=row[N];
    if A+B+C <> row[N] then exit;

    for i:=1 to N-2 do
        for j:=i+1 to N-1 do
            if (row[i] = A) and ((row[j] = A+B) or (row[j] = A+C)) then inc(res)
            else
                if (row[i] = B) and ((row[j] = B+A) or (row[j] = B+C)) then inc(res)
                else
                    if (row[i] = C) and ((row[j] = C+A) or (row[j] = C+B)) then inc(res)
end;

procedure   count_column;
var
    i,j:longint;
    column:array[0..MAX_M] of longint;
begin
    column[0]:=0;
    for i:=1 to M do begin
        column[i]:=column[i-1];
        for j:=1 to N do inc(column[i],map[j,i]);
    end;
    column[M+1]:=column[M];
    if A+B+C <> column[M] then exit;

    for i:=1 to M-2 do
        for j:=i+1 to M-1 do
            if (column[i] = A) and ((column[j] = A+B) or (column[j] = A+C)) then inc(res)
            else
                if (column[i] = B) and ((column[j] = B+A) or (column[j] = B+C)) then inc(res)
                else
                    if (column[i] = C) and ((column[j] = C+A) or (column[j] = C+B)) then inc(res)
end;

procedure   solve;
begin
    res:=0;
    count_row;
    count_column;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.