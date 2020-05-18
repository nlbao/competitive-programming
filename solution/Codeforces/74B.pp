const   INPUT = '74B.in';
        OUTPUT = '74B.out';
        MAX_N = 60;

var fi,fo:text;
    n,m,a,b,d:longint;
    s:string;

function    modn(x:longint):longint;
begin
    while x < 0 do x:=x+n;
    exit(x mod n);
end;

procedure   enter;
begin
    readln(fi,n,b,a);
    dec(a); dec(b);
    readln(fi,s);
    if s[4] = 'h' then d:=-1
    else d:=1;
    readln(fi,s);   m:=length(s);
end;

procedure   solve;
var i:longint;
begin
    for i:=1 to m do begin
        if (a+d < 0) or (a+d > n-1) then d:=-d;
        a:=modn(a+d);
        if s[i] = '0' then begin
            if (b+d > -1) and (b+d < n) then b:=modn(b+d);
        end
        else
            if d = -1 then b:=n-1
            else b:=0;
        if a = b then begin
            writeln(fo,'Controller ',i);
            exit;
        end;
    end;
    writeln(fo,'Stowaway');
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.