{
    ID: storm59061
    PROB: namenum
    LANG: PASCAL
}

const
    INPUT = 'namenum.in';
    OUTPUT = 'namenum.out';
    DICT = 'dict.txt';
    MAX_N = 13;
    key:array['A'..'Z'] of char = ('2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9');

var
    fi,fo:text;
    s,a,b:string;
    i,count:longint;

begin
    assign(fi,INPUT);    reset(fi);
    readln(fi,a);
    close(fi);
    assign(fi,DICT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    count:=0;
    while not eof(fi) do begin
        readln(fi,s);
        b:='';
        for i:=1 to length(s) do b:=b+key[s[i]];
        if b = a then begin
            writeln(fo,s);
            inc(count);
        end;
    end;
    if count = 0 then writeln(fo,'NONE');
    close(fo);
    close(fi);
end.
