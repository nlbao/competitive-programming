const
    INPUT = 'I.in';
    OUTPUT = 'I.out';

var
    fi,fo:text;
    s:string;
    row,err:longint;
    column:char;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    val(copy(s,1,length(s)-1),row,err);
    column:=s[length(s)];
    s:='neither';
    if row < 3 then begin
        if (column = 'A') or (column = 'D') then s:='window'
        else if (column = 'B') or (column = 'C') then s:='aisle';
    end
    else if row < 21 then begin
        if (column = 'A') or (column = 'F') then s:='window'
        else if (column = 'B') or (column = 'C') or (column = 'D') or (column = 'E') then s:='aisle';
    end
    else begin
        if (column = 'A') or (column = 'K') then s:='window'
        else if (column = 'C') or (column = 'D') or (column = 'G') or (column = 'H') then s:='aisle';
    end;
    writeln(fo,s);
    close(fo);
    close(fi);
end.