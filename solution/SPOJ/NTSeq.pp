uses    math;

const   MAX_N = 100010;
        MODUN = 1000000007;

type    ll = int64;

var fi,fo:text;
    n,top:longint;
    a,q,f,head:array[0..MAX_N] of longint;
    g:array[0..MAX_N] of ll;


function    mmod(x:ll):ll;
begin
    x:=x mod MODUN;
    while x < 0 do x:=x+MODUN;
    exit(x mod MODUN);
end;



procedure   gen_test();
var i:longint;
begin
    randomize;
    n:=10+random(10000);
    for i:=1 to n do begin
        a[i]:=random(MAX_N);
        if random(MAX_N) mod 2 = 0 then a[i]:=-a[i];
    end;
end;


procedure   init();
var i,l,r,mid,t:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);

    //gen_test();


    top:=0;
    q[0]:=2000000000;
    for i:=1 to n do begin
        t:=0;
        l:=1;   r:=top;
        while l <= r do begin
            mid:=(l+r) shr 1;
            if q[mid] < a[i] then begin
                t:=mid;
                l:=mid+1;
            end
            else r:=mid-1;
        end;
        inc(t); q[t]:=a[i];
        f[i]:=t;
        top:=max(top,t);
    end;
    //writeln(fo,top);
end;


procedure   solve();
var i,j,limit,l,r,u:longint;
    s:ll;
begin
    for i:=0 to n+1 do head[i]:=0;
    for i:=1 to n do inc(head[f[i]]);
    for i:=2 to n+1 do head[i]:=head[i-1]+head[i];
    for i:=n downto 1 do begin
        q[head[f[i]]]:=i;
        dec(head[f[i]]);
    end;

    {for i:=1 to n do begin
        for j:=head[i]+1 to head[i+1] do write(q[j],' ');
        writeln;
    end;}

    for i:=head[1]+1 to head[2] do g[q[i]]:=1;
    for i:=2 to n do begin
        s:=0;
        limit:=head[i-1];
        l:=head[i];   r:=head[i];
        if r > limit then s:=g[q[r]];

        for j:=head[i+1] downto head[i]+1 do begin
            u:=q[j];
            g[u]:=0;
            while (l-1 > limit) and (a[q[l-1]] < a[u]) do begin
                dec(l);
                s:=mmod(s+g[q[l]]);
            end;
            while (r > limit) and (q[r] > u) do begin
                s:=mmod(s-g[q[r]]);
                dec(r);
            end;
            if l <= r then g[u]:=s;
        end;
    end;

    s:=0;
    for i:=1 to n do
        if f[i] = top then s:=mmod(s+g[i]);
    writeln(fo,s);
end;


procedure   solve_1();
var i,j:longint;
    s:ll;
begin
    s:=0;
    for i:=1 to n do begin
        if f[i] = 1 then g[i]:=1
        else begin
            g[i]:=0;
            for j:=1 to i-1 do
                if (a[j] < a[i]) and (f[j]+1 = f[i]) then
                    g[i]:=mmod(g[i]+g[j]);
        end;
        if f[i] = top then s:=mmod(s+g[i]);
    end;
    writeln(fo,s);
end;


begin
    assign(fi,'');  reset(fi);
    assign(fo,''); rewrite(fo);
    init();
    //solve_1();
    solve();
    close(fo);
    close(fi);
end.

