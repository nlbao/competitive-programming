{
    ID: storm59061
    PROB: friday
    LANG: PASCAL
}

const
    INPUT = 'friday.in';
    OUTPUT = 'friday.out';
    MAX_N = 500;

var
    fi,fo:text;
    n,i,j,d:longint;
    month:array[1..12] of longint = (31,31,31,30,31,30,31,31,30,31,30,31);
    count:array[0..6] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    for i:=0 to 6 do count[i]:=0;
    d:=-1;
    for i:=1900 to 1900+n-1 do begin
        if ((i mod 100 = 0) and (i mod 400 = 0)) or ((i mod 100 <> 0) and (i mod 4 = 0)) then month[2]:=29
        else month[2]:=28;
        for j:=1 to 12 do begin
            inc(count[(d+13) mod 7]);
            d:=(d+month[j]) mod 7;
        end;
    end;
    write(fo,count[5],' ',count[6]);
    for i:=0 to 4 do write(fo,' ',count[i]);
    writeln(fo);
    close(fo);
    close(fi);
end.