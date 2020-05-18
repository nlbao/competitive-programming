const
    INPUT = 'I.inp';
    OUTPUT = 'I.out';
    MAX_H = 110;
    MAX_W = 110;
    MAX_N = 10010;

var
    fi,fo:text;
    H,W,N:longint;
    i,j,cPage,cLine,cWord:longint;
    s:string;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,H,W,N);
    cPage:=1;   cLine:=1;   cWord:=-1;
    for i:=1 to N do begin
        readln(fi,s);
        j:=length(s);
        if cWord+1+j <= W then
            cWord:=cWord+1+j
        else begin
            inc(cLine);
            cWord:=j;
            if cLine > H then begin
                inc(cPage);
                cLine:=1;
            end;
        end;
    end;
    if N = 0 then cPage:=0;
    writeln(fo,cPage);
    close(fo);
    close(fi);
end.