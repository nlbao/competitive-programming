uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n:longint;
    a,s:array[0..MAX_N] of ll;
    res:array[0..MAX_N] of char;
    found:boolean;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    s[0]:=0;
    for i:=1 to n do begin
        read(fi,a[i]);
        s[i]:=s[i-1] + a[i];
    end;
end;


procedure   tryf(i:longint; l,r:ll);
begin
    if (r < -s[i]) or (l > s[i]) then exit;

    if i = 1 then begin
        if (l <= a[i]) and (a[i] <= r) then begin
            res[i]:='+';
            found:=true;
        end
        else if (l <= -a[i]) and (-a[i] <= r) then begin
            res[i]:='-';
            found:=true;
        end;
        exit;
    end;

    res[i]:='+';
    tryf(i-1,l-a[i],r-a[i]);
    if found then exit;
    res[i]:='-';
    tryf(i-1,l+a[i],r+a[i]);
end;


procedure   solve();
var i:longint;
begin
    found:=false;
    tryf(n,0,a[1]);
    for i:=1 to n do write(fo,res[i]);
end;


procedure   gen_test(limit:longint);
var i:longint;
begin
    assign(fo,'257D.in');    rewrite(fo);
    randomize;
    n:=random(limit)+1;
    writeln(fo,n);
    a[0]:=1;
    for i:=1 to n do begin
        a[i]:=a[i-1] + random(a[i-1]+1);
        if a[i] >= oo then a[i]:=a[i-1] + random(limit);
        writeln(fo,a[i]);
    end;
    writeln('!!!!');
    close(fo);
end;


begin
    //gen_test(100000);

    assign(fi,'257D.in');    reset(fi);
    assign(fo,'257D.out');   rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.