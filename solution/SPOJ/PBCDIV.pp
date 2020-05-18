const
    INPUT = 'PBCDIV.inp';
    OUTPUT = 'PBCDIV.out';
    MAX_T = 100000;

var
    fi,fo:text;
    T,i:longint;
    A,B:int64;

function    f(N:int64):int64;
var
    t1,t2:int64;
begin
    t1:=(N div 12);
    t1:=t1-(t1 div 5);
    t2:=(N div 30);
    t2:=t2-(t2 div 2);
    exit(t1+t2);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,T);
    for i:=1 to T do
        begin
            read(fi,A,B);
            writeln(fo,f(B)-f(A-1));
        end;
    close(fo);
    close(fi);
end.