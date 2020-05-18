const
    INPUT = '110A.inp';
    OUTPUT = '110A.out';

var
    fi,fo:text;
    N:int64;
    i,count:longint;
    s,res:string;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    str(N,s);
    count:=0;
    for i:=1 to length(s) do
        if (s[i] = '4') or (s[i] = '7') then
            inc(count);
    res:='YES';
    str(count,s);
    for i:=1 to length(s) do
        if (s[i] <> '4') and (s[i] <> '7') then begin
            res:='NO';
            break;
        end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
