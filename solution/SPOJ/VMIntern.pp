const   MAX_N = 110;

var     fi,fo:text;
        n,pos,i:longint;
        a,b:array[0..MAX_N] of int64;
        id:array[0..MAX_N] of longint;
        s:int64;

function    gcd(x,y:int64):int64;
begin
    if (x = 0) or (y = 0) then exit(x+y);
    exit(gcd(y,x mod y));
end;

function    lcm(x,y:int64):int64;
begin
    exit((x div gcd(x,y))*y);
end;

procedure   solve1();
var i,j:longint;
    ok:boolean;
begin
    if n mod 2 = 0 then begin   //B win
        writeln(fo,'Balitello');
        for i:=1 to n do
            if i <> pos then write(fo,pos,' ')
            else if pos > 1 then write(fo,'1 ')
            else write(fo,'2 ');
    end
    else begin  //R win
        writeln(fo,'Raldono');
        for i:=1 to n do begin
            ok:=true;
            for j:=1 to n do
                if (i <> j) and (lcm(a[i],a[j]) = s) then begin
                    ok:=false;
                    break;
                end;
            if ok then write(fo,i,' ');
        end;
    end;
end;

procedure   sort(l,r:longint);
var i,j:longint;
    p1,p2,t:int64;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=b[i];   p2:=id[i];
    i:=l;   j:=r;
    repeat
        while (b[i] < p1) or ((b[i] = p1) and (id[i] < p2)) do inc(i);
        while (b[j] > p1) or ((b[j] = p1) and (id[j] > p2)) do dec(j);
        if i <= j then begin
            t:=b[i];    b[i]:=b[j];     b[j]:=t;
            t:=id[i];   id[i]:=id[j];   id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;

function    check(i1,i2:longint):boolean;
var i,j,m,l,r,turn:longint;
    ok:array[0..MAX_N] of boolean;
    x:int64;
    found:boolean;
begin
    x:=lcm(a[i1],a[i2]);
    if x mod s = 0 then exit(false);
    fillchar(ok,sizeof(ok),true);
    ok[i1]:=false;  ok[i2]:=false;
    turn:=1;

    for i:=3 to n do begin
        turn:=(turn+1) mod 2;
        m:=0;
        for j:=1 to n do
            if ok[j] then begin
                inc(m);
                b[m]:=a[j] div gcd(x,a[j]);
                id[m]:=j;
                if (b[m]*x) mod s = 0 then exit(turn = 0);
            end;
        randomize;
        sort(1,m);

        l:=1;   found:=false;
        while l <= m do begin
            r:=l;
            while (r <= m) and (b[r] = b[l]) do inc(r);
            if (l-r) mod 2 = 1 then begin
                x:=x*b[l]; found:=true;
                ok[id[l]]:=false;
                break;
            end;
            l:=r;
        end;
        if not found then begin
            x:=x*b[1];
            ok[id[1]]:=false;
        end;
    end;
    exit(turn = 1);
end;

procedure   solve2();
var i,j,c:longint;
    r:array[0..MAX_N] of longint;
begin
    c:=0;
    for i:=1 to n do begin
        r[i]:=0;
        for j:=1 to n do
            if (i <> j) and (check(i,j) = false) then begin
                r[i]:=j;
                break;
            end;
        if r[i] = 0 then inc(c);
    end;

    if c = 0 then begin
        writeln(fo,'Balitello');
        for i:=1 to n do write(fo,r[i],' ');
    end
    else begin
        writeln(fo,'Raldono');
        for i:=1 to n do
            if r[i] = 0 then write(fo,i,' ');
    end;
end;

begin
    assign(fi,'VMIntern.in');   reset(fi);
    assign(fo,'VMIntern.out');  rewrite(fo);
    pos:=0;
    readln(fi,n,s);
    for i:=1 to n do begin
        read(fi,a[i]);
        if (s mod a[i]) > 0 then pos:=i;
    end;
    if pos > 0 then solve1()
    else solve2();
    close(fo);
    close(fi);
end.
