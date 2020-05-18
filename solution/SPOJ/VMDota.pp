uses math;

const   MAX_N = 40;

type    arr = array[0..MAX_N] of longint;

var fi,fo:text;
    nTest,n,c0,c1,c2,i:longint;
    a,res:arr;
    h,g:array[0..MAX_N,0..MAX_N] of longint;
    ok:boolean;


procedure   init();
var i,j,k:longint;
begin
    fillchar(h,sizeof(h),0);
    fillchar(g,sizeof(g),0);
    for i:=2 to MAX_N do
        if (i mod 2 = 1) then h[1][i]:=i
        else g[1][i]:=i;
    for i:=2 to MAX_N do
        for j:=2*i to MAX_N do begin
            for k:=j downto 2 do
                if (k mod 2 = 1) and (h[i-1][j-k] > 0) then begin
                    h[i][j]:=k;
                    break;
                end;
            for k:=j downto 2 do
                if (k mod 2 = 0) and (g[i-1][j-k] > 0) then begin
                    g[i][j]:=k;
                    break;
                end;
        end;
end;

procedure   enter();
var i:longint;
    s:string;
begin
    c0:=0;  c1:=0;  c2:=0;
    readln(fi,s);
    n:=length(s);
    while (s[n] <> '0') and (s[n] <> '+') and (s[n] <> '-') do n:=n-1;
    for i:=1 to n do
        if s[i] = '0' then begin    a[i]:=0;    inc(c0);    end
        else if s[i] = '+' then begin   a[i]:=1;    inc(c1);    end
        else begin  a[i]:=-1;   inc(c2);    end;
end;

procedure   sets12(n:longint;   var s1,s2:longint);
begin
    if n mod 2 = 0 then begin   s1:=2;  s2:=1;  end
    else begin s1:=1;   s2:=2;  end;
end;

procedure   up(var x,y:longint);    begin   x:=y;   y:=y+2; end;

function    solve1():boolean;
var i,s1,s2:longint;
begin
    if c1-c2 <> (n mod 2) then exit(false);
    sets12(n,s1,s2);
    for i:=1 to n do
        if a[i] = 1 then up(res[i],s1)
        else up(res[i],s2);
    exit(true);
end;

function    check(var b:arr):boolean;
var i,j,c:longint;
begin
    for i:=1 to n do begin
        if b[i] = 0 then exit(false);
        c:=1;
        for j:=1 to n do
            if j <> i then
                if b[j] = b[i] then c:=0
                else
                    if b[j] > b[i] then c:=-c;
        //if (c <> a[i]) then writeln('Err: ',i,' ',b[i],'       ',c,' ',a[i]);
        if c <> a[i] then exit(false);
    end;
    exit(true);
end;

function    solve2(c0:longint):boolean;
var i,j,x,y,t,s1,s2,limit:longint;
begin
    if c0 = 1 then exit(false);
    x:=MAX_N;   y:=MAX_N;
    limit:=c0 div 2;
    for i:=0 to limit do
        for j:=0 to limit-i do begin
            t:=i+j;
            if (t = 0) or (t >= x+y) then continue;
            if h[t][c0] < 2 then continue;
            if (c1+i)-(c2+j) <> (n-c0+t) mod 2 then continue;
            x:=i;   y:=j;
        end;
    if x = MAX_N then exit(false);


    fillchar(res,sizeof(res),0);
    sets12(n-c0+x+y,s1,s2);
    for i:=1 to n do begin
        if res[i] > 0 then continue;
        if a[i] = 1 then up(res[i],s1)
        else if a[i] = -1 then up(res[i],s2)
        else begin
            t:=h[x+y][c0];
            c0:=c0-t;
            if ((s1 < s2) and (x > 0)) or (y = 0) then begin
                for j:=i to n do
                    if (a[j] = 0) and (res[j] = 0) then begin
                        res[j]:=s1;
                        t:=t-1;
                        if t = 0 then break;
                    end;
                s1:=s1+2;
                x:=x-1;
            end
            else begin
                for j:=i to n do
                    if (a[j] = 0) and (res[j] = 0) then begin
                        res[j]:=s2;
                        t:=t-1;
                        if t = 0 then break;
                    end;
                s2:=s2+2;
                y:=y-1;
            end;
        end;
    end;
    if check(res) = false then begin
        res[1]:=MAX_N;
        exit(false);
    end;
    exit(true);
end;

function    solve3(c0:longint):boolean;
var i,j,k,t,r,x,y,z,limit,s1,s2:longint;
    first:boolean;
    b:arr;
begin
    if c0 < 2 then exit(false);

    x:=MAX_N; y:=MAX_N; z:=0;
    for k:=c0 downto 2 do begin
        limit:=(c0-k) div 2;
        for i:=0 to limit do
            for j:=0 to limit-i do begin
                t:=i+j;
                if (t = 0) or (t >= x+y) then continue;
                if (h[i+j][c0-k] < 2) then continue;
                r:=(n-c0+i+j+1) mod 2;
                if (r = 0) and ((c1+i)-(c2+j+1) <> r) then continue;
                if (r = 1) and ((c1+i+1)-(c2+j) <> r) then continue;
                x:=i; y:=j; z:=k;
                first:=(r = 1);
            end;
        if z > 0 then break;
    end;

    r:=(n-c0+1) mod 2;
    if (r = 0) and (c1-(c2+1) = r) then begin   x:=0;   y:=0;   z:=c0;  end;
    if (r = 1) and ((c1+1)-c2 = r) then begin   x:=0;   y:=0;   z:=c0;  end;
    first:=(r = 1);

    if x = MAX_N then exit(false);

    fillchar(b,sizeof(b),0);
    sets12(n-c0+x+y+1,s1,s2);
    c0:=c0-z;
    for i:=1 to n do
        if a[i] = 0 then begin
            if (first) then b[i]:=s1
            else b[i]:=s2;
            z:=z-1;
            if z = 0 then break;
        end;
    if (first) then s1:=s1+2
    else s2:=s2+2;

    for i:=1 to n do begin
        if b[i] > 0 then continue;
        if a[i] = 1 then up(b[i],s1)
        else if a[i] = -1 then up(b[i],s2)
        else begin
            t:=h[x+y][c0];
            c0:=c0-t;
            if ((s1 < s2) and (x > 0)) or (y = 0) then begin
                for j:=i to n do
                    if (a[j] = 0) and (b[j] = 0) then begin
                        b[j]:=s1;
                        t:=t-1;
                        if t = 0 then break;
                    end;
                s1:=s1+2;
                x:=x-1;
            end
            else begin
                for j:=i to n do
                    if (a[j] = 0) and (b[j] = 0) then begin
                        b[j]:=s2;
                        t:=t-1;
                        if t = 0 then break;
                    end;
                s2:=s2+2;
                y:=y-1;
            end;
        end;
    end;

    //for i:=1 to n do write(b[i],' ');
    //writeln; writeln;

    if check(b) = false then exit(false);
    if check(res) = false then res[1]:=MAX_N;
    for i:=1 to n do
        if b[i] < res[i] then break
        else if b[i] > res[i] then exit(false);
    res:=b;
    exit(true);
end;


function    solve4(c0:longint):boolean;
var i,j,k,t,r,x,y,z,limit,s1,s2:longint;
    first:boolean;
    b:arr;
begin
    if c0 < 2 then exit(false);
    x:=MAX_N; y:=MAX_N; z:=0;
    for k:=c0 downto 2 do begin
        if k mod 2 = 1 then continue;
        limit:=(c0-k) div 2;
        for i:=0 to limit do
            for j:=0 to limit-i do begin
                t:=i+j;
                if (t = 0) or (t >= x+y) then continue;
                if (h[i+j][c0-k] < 2) then continue;
                r:=(n-c0+i+j) mod 2;
                if (c1+i)-(c2+j) <> r then continue;
                x:=i; y:=j; z:=k;
                first:=(r = 1);
            end;
        if z > 0 then break;
    end;

    if c0 mod 2 = 0 then begin
        r:=(n-c0) mod 2;
        if c1-c2 = r then begin   x:=0;   y:=0;   z:=c0;  end;
        first:=(r = 1);
    end;

    if x = MAX_N then exit(false);

    fillchar(b,sizeof(b),0);
    sets12(n-c0+x+y,s1,s2);
    t:=n-c0+x+y+1;
    c0:=c0-z;
    for i:=1 to n do
        if a[i] = 0 then begin
            b[i]:=t;
            z:=z-1;
            if z = 0 then break;
        end;

    for i:=1 to n do begin
        if b[i] > 0 then continue;
        if a[i] = 1 then up(b[i],s1)
        else if a[i] = -1 then up(b[i],s2)
        else begin
            t:=h[x+y][c0];
            c0:=c0-t;
            if ((s1 < s2) and (x > 0)) or (y = 0) then begin
                for j:=i to n do
                    if (a[j] = 0) and (b[j] = 0) then begin
                        b[j]:=s1;
                        t:=t-1;
                        if t = 0 then break;
                    end;
                s1:=s1+2;
                x:=x-1;
            end
            else begin
                for j:=i to n do
                    if (a[j] = 0) and (b[j] = 0) then begin
                        b[j]:=s2;
                        t:=t-1;
                        if t = 0 then break;
                    end;
                s2:=s2+2;
                y:=y-1;
            end;
        end;
    end;

    //for i:=1 to n do write(b[i],' ');
    //writeln; writeln;

    if check(b) = false then exit(false);
    if check(res) = false then res[1]:=MAX_N;
    for i:=1 to n do
        if b[i] < res[i] then break
        else if b[i] > res[i] then exit(false);
    res:=b;
    exit(true);
end;


begin
    assign(fi,'VMDota.in');     reset(fi);
    assign(fo,'VMDota.out');    rewrite(fo);
    init();
    readln(fi,nTest);
    while nTest > 0 do begin
        enter();
        fillchar(res,sizeof(res),0);
        if c0 = 0 then ok:=solve1()
        else begin
            ok:=solve2(c0);
            ok:=solve3(c0) or ok;
            ok:=solve4(c0) or ok;
        end;
        if (ok) then ok:=check(res);
        if (not ok) then writeln(fo,'TIDAK MUNGKIN')
        else begin
            for i:=1 to n do write(fo,res[i],' ');
            writeln(fo);
        end;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
