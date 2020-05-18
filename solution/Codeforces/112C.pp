const
    INPUT = '112C.inp';
    OUTPUT = '112C.out';
    MAX_N = 100000;

var
    fi,fo:text;
    N,y:longint;
    x:int64;
    check:boolean;
    a:array[0..MAX_N] of int64;

procedure   solve;
var
    i,j:longint;
    sum:int64;
begin
    check:=false;
    if y < N then exit;
    j:=y div N;
    for i:=1 to N do a[i]:=1;
    a[1]:=a[1]+y-N;
    sum:=0;
    for i:=1 to N do begin
        sum:=sum+sqr(a[i]);
        if sum >= x then break;
    end;
    if sum >=x then check:=true;
end;

procedure   print_result;
var
    i:longint;
begin
    if check = false then writeln(fo,-1)
    else
        for i:=1 to N do write(fo,a[i],' ');
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,x,y);
    solve;
    print_result;
    close(fo);
    close(fi);
end.