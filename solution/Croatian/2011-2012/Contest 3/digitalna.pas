const   INPUT = ''{'digitalna.in'};
        OUTPUT = ''{'digitalna.out'};
        MAX_N = 110;

var fi,fo:text;
    n,p1,p2:longint;

procedure   enter;
var i:longint;
    s:string;
begin
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s);
        if s = 'BLJTV1' then p1:=i
        else if s = 'BLJTV2' then p2:=i;
    end;
end;

procedure   print(x,j:longint);
var i:longint;
begin   for i:=1 to j do write(fo,x);  end;

procedure   solve;
begin
    print(1,p1-1);
    print(4,p1-1);
    if p1 > p2 then inc(p2);
    print(1,p2-1);
    print(4,p2-2);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.