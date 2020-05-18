const   MAX_N = 210;
        eps = 0.00001;

var fi,fo:text;
    n:longint;
    x,y:array[0..MAX_N] of double;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
begin
    n:=0;
    while not eof(fi) do begin
        inc(n);
        readln(fi,x[n],y[n]);
    end;
end;

function    check(i,j:double):longint;
var k,c:longint;
begin
    c:=0;
    for k:=1 to n do
        if (sqr(i-x[k])+sqr(j-y[k])-6.25 <= eps) then inc(c);
    exit(c);
end;

procedure   solve;
var res:longint;
    i,j:double;
begin
    res:=0;
    i:=0;
    while i-50 <= eps do begin
        j:=0;
        while j-50 <= eps do begin
            res:=max(res,check(i,j));
            j:=j+0.1;
        end;
        i:=i+0.1;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'100004C.in');    reset(fi);
    assign(fo,'100004C.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
