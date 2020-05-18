const
    INPUT = 'Integer7.inp';
    OUTPUT = 'Integer7.out';

var
    A1,B1,A2,B2:longint;
    X1,X2:int64;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,A1,B1,A2,B2);
    close(fi);
end;

procedure   Swap(var x,y:int64);
var
    tmp:int64;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

function    UCLN(x,y:int64):int64;
var
    r:int64;
begin
    r:=x mod y;
    while r <> 0 do
        begin
            x:=y;
            y:=r;
            r:=x mod y;
        end;
    exit(abs(y));
end;

procedure   Find;
var
    a,b,c,d,x,y,t,pre_a:int64;
begin
    a:=A1;
    b:=-A2;
    c:=B2-B1;
    d:=UCLN(a,b);
    a:=a div d;
    b:=b div d;
    c:=c div d;
    pre_a:=a;
    a:=0;
    x:=0;   y:=0;
    repeat
        a:=a+pre_a;
        if ((c-a) mod b) = 0 then
            begin
                x:=a div pre_a;
                y:=(c-a) div b;
            end;
    until x <> 0;
    a:=pre_a;
    d:=x div b;
    if (x*b > 0) then inc(d);
    if d < (y div a) then
        begin
            d:=y div a;
            if y mod a = 0 then dec(d);
        end;
    if b = a then t:=0
    else
        if b > a then t:=d
        else
            begin
                t:=0;
                repeat
                    X1:=x+b*t;  X2:=y-a*t;
                    if (X1 > 0) and (X2 > 0) then exit;
                    inc(t);
                until t > d;
            end;
    X1:=x+b*t;  X2:=y-a*t;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,X1,' ',X2);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.
