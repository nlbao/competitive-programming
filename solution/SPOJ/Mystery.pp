const
    INPUT = 'Mystery.inp';
    OUTPUT = 'Mystery.out';
    Q = 20122007;

var
    N:longint;
    R:int64;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    close(fi);
end;

function    power(x,p,q:int64):int64;
var
    t:int64;
begin
    if p = 1 then exit(x mod q)
    else
        begin
            t:=power(x,p div 2,q);
            if odd(p) then exit((x*t*t) mod q)
            else exit((t*t) mod q);
        end;
end;

procedure   Find;
var
    i,j,t:longint;
begin
    R:=1;
    t:=round(sqrt(N))+1;
    for i:=1 to t do
        if (N mod i) = 0 then
            begin
                R:=(R*(power(3,i,Q)-1)) mod Q;
                j:=N div i;
                if j <> i then
                    R:=(R*(power(3,j,Q)-1)) mod Q;
            end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,R);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.