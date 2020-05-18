const
    INPUT = ''{'jabuke.inp'};
    OUTPUT = ''{'jabuke.out'};
    MAX_N = 15;

var
    fi,fo:text;
    N,M,J,i,pos,res,x:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,M);
    pos:=1;
    res:=0;
    readln(fi,J);
    for i:=1 to J do begin
        readln(fi,x);
        if x >= pos+M then begin
            res:=res+x-pos-M+1;
            pos:=x-M+1;
        end
        else
            if x < pos then begin
                res:=res+pos-x;
                pos:=x;
            end;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.