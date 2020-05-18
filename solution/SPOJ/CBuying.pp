const   INPUT = 'CBuying.in';
        OUTPUT =  'CBuying.out';
        MAX_N = 100010;

var fi,fo:text;
    n:longint;
    b:int64;
    p,c:array[0..MAX_N] of int64;
    id:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,b);
    for i:=1 to n do begin
        readln(fi,p[i],c[i]);
        id[i]:=i;
    end;
end;

procedure   quick_sort(l,r:longint);
var i,j,tmp:longint;
    t:int64;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    t:=p[id[(i+j) shr 1]];
    repeat
        while p[id[i]] < t do inc(i);
        while p[id[j]] > t do dec(j);
        if i <= j then begin
            tmp:=id[i]; id[i]:=id[j];   id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   solve;
var i,j:longint;
    t,res:int64;
begin
    quick_sort(1,n);
    res:=0;
    for i:=1 to n do begin
        j:=id[i];
        if p[j] > b then break
        else begin
            t:=b div p[j];
            if c[j] < t then t:=c[j];
            res:=res+t;
            b:=b-t*p[j];
        end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.