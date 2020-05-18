const
    INPUT = 'KDTuyen.inp';
    OUTPUT = 'KDTuyen.out';
    MAX_N = 1000000;

var
    fi,fo:text;
    X:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,X);
    case X of
        0,1: writeln(fo,1);
        2: writeln(fo,2);
        3,4: writeln(fo,6);
        5: writeln(fo,3)
        else writeln(fo,9);
    end;
    close(fo);
    close(fi);
end.