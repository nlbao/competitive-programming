uses    math;

const   MAX_N = 100010;


var fi,fO:text;
    n,q,i,j,id:longint;
    t,base,a1,b1,a2,b2:int64;
    x,y:array[0..MAX_N] of int64;


begin
    assign(fi,'bubba1.in');     reset(fi);
    assign(fo,'bubba1.out');    rewrite(fo);
    readln(fi,n,q,base);
    for i:=1 to n do read(fi,x[i],y[i]);
    x[0]:=0;    y[0]:=0;
    t:=0;
    for id:=1 to q do begin
        read(fi,j);
        if j = 0 then begin
            read(fi,i,a1,b1,a2,b2);
            x[i]:=(a1*T+b1) mod base;
            y[i]:=(a2*T+b2) mod base;
        end
        else begin
            read(fi,a1,b1,a2,b2);
            x[0]:=(a1*T+b1) mod base;
            y[0]:=(a2*T+b2) mod base;
            t:=2*(n-1);
            for i:=1 to n do t:=t+2*max(abs(x[i]-x[0]),abs(y[i]-y[0]));
            writeln(fo,t);
        end;
    end;
    close(fo);
    close(fi);
end.