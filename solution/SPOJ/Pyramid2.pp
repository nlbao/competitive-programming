const
    INPUT = 'Pyramid2.inp';
    OUTPUT = 'Pyramid2.out';
    MAX_N = 1000010;

var
    fi,fo:text;
    N:longint;
    a:array[0..MAX_N] of char;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,a[i]);
end;

procedure   solve;
var
    i,l,r,res,wait:longint;
begin
    l:=1;   r:=N;
    while (l < N) and (a[l] = '<') do inc(l);
    while (r > 1) and (a[r] = '>') do dec(r);
    res:=0;
    if l > r then wait:=0
    else wait:=-1;
    for i:=l to r do
        if a[i] = '<' then inc(wait)
        else begin
            inc(res);
            if wait > -1 then dec(wait);
        end;
    writeln(fo,res+wait);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.