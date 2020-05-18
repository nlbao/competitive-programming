const
    INPUT = 'J.inp';
    OUTPUT = 'J.out';
    MAX_N = 310;
    MAX_M = 310;

var
    fi,fo:text;
    time:array['a'..'z'] of longint = (1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4);


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init(root);
    readln(fi,N);
    for i:=1 to N do begin
        readln(fi,s);
        writeln(fo,add(s));
    end;
    close(fo);
    close(fi);
end.