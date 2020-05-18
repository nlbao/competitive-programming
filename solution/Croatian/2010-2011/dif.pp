const   INPUT = 'dif.in';
        OUTPUT = 'dif.out';
        MAX_N = 300010;
        MAX_INT = 9000000000000000000;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of int64;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   solve;
var i,top:longint;
    l,r,k,smax,smin:int64;
    stack:array[0..MAX_N] of longint;
begin
    smax:=0;
    stack[0]:=0;    a[0]:=MAX_INT;   a[n+1]:=MAX_INT-1;
    top:=1; stack[1]:=1;
    for i:=2 to n+1 do begin
        while a[i] > a[stack[top]] do begin
            l:=stack[top-1]+1;  r:=i-1;
            k:=stack[top];
            smax:=smax+a[k]*(k-l+(k-l+1)*(r-k));
            dec(top);
        end;
        inc(top);   stack[top]:=i;
    end;

    smin:=0;
    stack[0]:=0;    a[0]:=-2;  a[n+1]:=-1;
    top:=1; stack[1]:=1;
    for i:=2 to n+1 do begin
        while a[i] < a[stack[top]] do begin
            l:=stack[top-1]+1;  r:=i-1;
            k:=stack[top];
            smin:=smin+a[k]*(k-l+(k-l+1)*(r-k));
            dec(top);
        end;
        inc(top);   stack[top]:=i;
    end;
    writeln(fo,smax-smin);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
