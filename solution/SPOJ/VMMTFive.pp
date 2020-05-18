const
    INPUT = 'VMMTFive.inp';
    OUTPUT = 'VMMTFive.out';

var
    fi,fo:text;
    N,M:longint;
    sRow,sColumn,crrRow,crrColumn:array[0..5] of longint;
    W:array[0..5,0..5] of longint;
    avail:array[0..25] of boolean;
    found:boolean;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    N:=5;   M:=sqr(N);
    for i:=1 to N do
        read(fi,sRow[i]);
    for i:=1 to N do
        read(fi,sColumn[i]);
end;
{---------------------------------------------------------------------------}
procedure   try_W(i,j:longint);
var
    x:longint;
begin
    {writeln(i,' ',j); readln;}
    if i > N then found:=true;
    if found = true then exit;
    if j > N then begin
        if crrRow[i] = sRow[i] then
            try_W(i+1,1);
        exit;
    end;
        writeln(W[4,5]);
    for x:=1 to M do
        if avail[x] then begin
            avail[x]:=false;
            W[i,j]:=x;
            crrRow[i]:=crrRow[i]+x;
            crrColumn[j]:=crrColumn[j]+x;
            if (i <> N) or (crrColumn[j] = sColumn[j]) then
                try_W(i,j+1);
            crrColumn[j]:=crrColumn[j]-x;
            crrRow[i]:=crrRow[i]-x;
            avail[x]:=true;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    found:=false;
    for i:=1 to N do begin
        crrRow[i]:=0;
        crrColumn[i]:=0;
    end;
    for i:=1 to M do avail[i]:=true;
    try_W(1,1);
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,j:longint;
begin
    for i:=1 to N do begin
        for j:=1 to N do
            write(fo,W[i,j],' ');
        writeln(fo);
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    print_result;
    close(fo);
    close(fi);
end.