uses    math;

const   MAX_N = 100010;
        MAX_M = 200010;

var fi,fo:text;
    n,m,i,j,k,d:longint;

begin
    assign(fo,'nkbracke20.in');  rewrite(fo);
    randomize;
    n:=100000;  m:=200000;
    writeln(fo,n,' ',m);
    for i:=1 to n do
        {if random(10000) mod 2 = 0 then write(fo,'(')
        else write(fo,')');}
        {if i mod 2 = 1 then write(fo,'(')
        else write(fo,')');}
        if i <= n div 2 then write(fo,'(')
        else write(fo,')');
        {if i mod 3 = 0 then write(fo,')')
        else write(fo,'(');}
    writeln(fo);

    for i:=1 to m do
        if random(10000) mod 47 = 0 then begin
            j:=random(n)+1;
            if random(10000) mod 2 = 0 then writeln(fo,0,' ',j,' (')
            else writeln(fo,0,' ',j,' )');
        end
        else begin
            d:=1;   j:=n+1;
            while d mod 2 = 1 do d:=min(n,random(n-100)+1);
            while j+d-1 > n do j:=random(n-d)+1;
            k:=j+d-1;
            writeln(fo,1,' ',j,' ',k);
        end;
    close(fo);
end.
