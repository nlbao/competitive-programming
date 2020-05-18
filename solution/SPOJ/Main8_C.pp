const
    INPUT = 'Main8_C.inp';
    OUTPUT = 'Main8_C.out';
    MAX_N = 50010;

var
    fi,fo:text;
    nTest,N,K:longint;
    a,id:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,K);
    for i:=1 to N do begin
        read(fi,a[i]);
        id[i]:=i;
    end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[id[(i+j) div 2]];
    repeat
        while a[id[i]] < p do inc(i);
        while a[id[j]] > p do dec(j);
        if i <= j then begin
            tmp:=id[i];
            id[i]:=id[j];
            id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,count:longint;
begin
    for i:=N downto 1 do begin
        count:=0;
        for j:=N downto i do begin
            count:=count+(a[id[j]] div a[id[i]]);
            if count >= K then begin
                writeln(fo,a[id[i]]);
                exit;
            end;
        end;
    end;
    writeln(fo,0);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        quick_sort(1,N);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.