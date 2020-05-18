const   MAX_N = 2229290;
        MODUN = 500009;
        LIMIT = 2229282;

var fi,fo:text;
    nTest,n:longint;
    is_prime:array[0..MAX_N] of boolean;
    p,d,a,g,c,f:array[0..MAX_N] of longint;

procedure   init;
var i,j,k:longint;
begin
    fillchar(is_prime,sizeof(is_prime),true);
    for i:=2 to MAX_N do
        if is_prime[i] then begin
            p[i]:=i;    d[i]:=i;
            a[i]:=1;
            j:=i;
            for k:=2 to MAX_N do begin
                j:=j+i;
                if j > MAX_N then break;
                is_prime[j]:=false;
                p[j]:=i;    d[j]:=i;
                if (p[k] = i) then begin
                    d[j]:=d[j]*d[k];
                    a[j]:=a[k]+1;
                end;
            end;
        end;

    fillchar(c, sizeof(c), 0);
    g[1]:=1;    c[1]:=1;    f[1]:=1;
    for i:=2 to LIMIT do begin
        if is_prime[i] then g[i]:=2
        else
            if d[i] = i then g[i]:=a[i]+1
            else g[i]:=g[d[i]]*g[i div d[i]];
        inc(c[g[i]]);
        f[i]:=(int64(f[i-1])*int64(c[g[i]])) mod MODUN;
    end;
end;

function    solve(n:longint):longint;
begin
    if n > LIMIT then exit(0)
    else exit(f[n]-1);
end;

begin
    assign(fi,'BBSYSTEM.in');   reset(fi);
    assign(fo,'BBSYSTEM.out');  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,n);
        writeln(fo,solve(n));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.