const
    INPUT = 'PALIN.inp';
    OUTPUT = 'PALIN.out';
    MAX_N = 1000010;

var
    fi,fo:text;
    nTest,N:longint;
    a:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    ch:char;
    number:set of char;
begin
    number:=['0','1','2','3','4','5','6','7','8','9'];
    N:=0;
    while not eoln(fi) do begin
        read(fi,ch);
        if ch in number then begin
            inc(N);
            a[N]:=ord(ch)-48;
        end;
    end;
    readln(fi);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,k,count:longint;
    check:boolean;
begin
    i:=1;
    j:=N;
    check:=false;    count:=0;
    while i < j do begin
        if a[j] < a[i] then begin
            a[j]:=a[i];
            check:=true;
        end
        else
            if a[j] > a[i] then inc(count);
        inc(i); dec(j);
    end;
    if (check = true) and (count = 0) then exit;

    i:=(N+1) div 2;
    j:=N-i+1;
    while (i > 1) and (a[i] = 9) do begin
        dec(i);
        inc(j);
    end;
    if a[i] = 9 then begin
        for k:=2 to N do a[k]:=0;
        inc(N);
        a[1]:=1; a[N]:=1;
    end
    else begin
        inc(a[i]); a[j]:=a[i];
        for k:=i+1 to j-1 do a[k]:=0;
        while i > 1 do begin
            dec(i); inc(j);
            a[j]:=a[i];
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i:longint;
begin
    for i:=1 to N do write(fo,a[i]);
    writeln(fo);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        print_result;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.