uses    math;

const   MAX_N = 1000000;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    b,n,m,t1,t2,lim:ll;
    i,res:longint;

begin
    assign(fi,'CALC.inp');   reset(fi);
    assign(fo,'CALC.out');   rewrite(fo);
    readln(fi,b,n);

    res:=0;
    t1:=2*b*n;
    t2:=n*n;
    lim:=2*n;
    for i:=1 to lim do begin
        if i = n then continue;
        m:=i;
        if (m*(t1-b*m)) mod t2 = 0 then inc(res);
    end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.