const   MAX_N = 110;
        MAX_P = 1000;

var fi,fo:text;
    n,nP,i,k:longint;
    a:array[0..MAX_N] of longint;
    is_prime:array[0..MAX_P] of boolean;
    p:array[0..MAX_P] of longint;


procedure   init;
var i,j:longint;
begin
    for i:=2 to MAX_P do is_prime[i]:=true;
    nP:=0;
    for i:=2 to MAX_P do
        if is_prime[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i+i;
            while j < MAX_P do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;

begin
    assign(fi,'66D.in');    reset(fi);
    assign(fo,'66D.out');   rewrite(fo);
    init;
    readln(fi,n);
    if n < 3 then writeln(fo,-1)
    else begin
        for i:=1 to n-1 do a[i]:=p[1];
        a[1]:=a[1]*p[2];
        a[n]:=p[2];
        for i:=2 to n do a[i]:=a[i]*p[3];
        k:=3;
        for i:=2 to n-1 do begin
            inc(k);
            a[i]:=a[i]*p[k];
        end;
        for i:=1 to n do writeln(fo,a[i]);
    end;
    close(fo);
    close(fi);
end.
