const   MAX_N = 10010;
        MAX_T = 2*1000010;
        MAX_P = 100010;

type    int = int64;

var fi,fo:text;
    nTest,n,maxT:longint;
    a,b,id:array[0..MAX_N] of longint;
    p:array[0..MAX_N] of int;
    t:array[0..MAX_T] of int;

function    max(x,y:int):int;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    maxT:=1;
    for i:=1 to n do begin
        id[i]:=i;
        readln(fi,a[i],b[i],p[i]);
        b[i]:=a[i]+b[i];    inc(a[i]);
        maxT:=max(maxT,b[i]);
    end;
end;

procedure   quick_sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=a[id[l+random(r-l+1)]];
    i:=l;   j:=r;
    repeat
        while a[id[i]] < p do inc(i);
        while a[id[j]] > p do dec(j);
        if i <= j then begin
            t:=id[i];   id[i]:=id[j];   id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   update(i:longint;   value:int);
begin
    if (i < 1) or (i > maxT) then exit;
    t[i]:=max(t[i],value);
    update(i+(i and (-i)),value);
end;

function    get(i:longint):int;
begin
    if (i < 1) or (i > maxT) then exit(0);
    if i = 1 then exit(t[1]);
    exit(max(get(i-(i and (-i))),t[i]));
end;

procedure   solve;
var i,j:longint;
    f,res:int;
begin
    res:=0;
    randomize;
    quick_sort(1,n);
    for i:=1 to maxT do t[i]:=0;
    for i:=1 to n do begin
        j:=id[i];
        f:=p[j]+get(a[j]-1);
        res:=max(res,f);
        update(b[j]+1,f);
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'test.out'{'Rent.in'});   reset(fi);
    assign(fo,'Rent.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
