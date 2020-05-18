const
    INPUT = 'BaseH.inp';
    OUTPUT = 'BaseH.out';
    MAX_N = 1000000000;
    MAX_H = 2008;

var
    N,H:longint;
    Res:string;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N,H);
    close(fi);
end;

procedure   Find;
begin
    if H < 2 then
        begin
            if N = 1 then Res:='1'
            else Res:='0';
        end;
    Res:='';
    repeat
        if (N mod 2) = 0 then Res:='0'+Res
        else Res:='1'+Res;
        N:=N div 2;
    until N = 0;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.