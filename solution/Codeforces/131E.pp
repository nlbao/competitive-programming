const   INPUT = '131E.in';
        OUTPUT = '131E.out';
        MAX_N = 100010;
        MAX_M = 100010;

type    arr = array[0..MAX_M] of longint;

var fi,fo:text;
    n,m:longint;
    x,y,sum,sub,id,c:arr;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to m do begin
        readln(fi,x[i],y[i]);
        sum[i]:=x[i]+y[i];
        sub[i]:=x[i]-y[i];
    end;
end;

procedure   quick_sort(var x,y:arr; l,r:longint);
var i,j,p1,p2,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p1:=x[id[(i+j) shr 1]];
    p2:=y[id[(i+j) shr 1]];
    repeat
        while (x[id[i]] < p1) or ((x[id[i]] = p1) and (y[id[i]] < p2)) do inc(i);
        while (x[id[j]] > p1) or ((x[id[j]] = p1) and (y[id[j]] > p2)) do dec(j);
        if i <= j then begin
            tmp:=id[i]; id[i]:=id[j];   id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,y,l,j);  quick_sort(x,y,i,r);
end;

procedure   cal(var x,y:arr);
var i,j,k:longint;
begin
    for i:=1 to m do id[i]:=i;
    quick_sort(x,y,1,m);
    i:=1;
    while i < m do begin
        j:=i;
        while (j < m) and (x[id[j+1]] = x[id[i]]) do inc(j);
        if j > i then begin
            inc(c[id[i]]);  inc(c[id[j]]);
            for k:=i+1 to j-1 do inc(c[id[k]],2);
        end;
        i:=j+1;
    end;
end;

procedure   solve;
var i:longint;
    t:array[0..8] of longint;
begin
    for i:=1 to m do c[i]:=0;
    cal(x,y);
    cal(y,x);
    cal(sum,x);
    cal(sub,x);
    for i:=0 to 8 do t[i]:=0;
    for i:=1 to m do inc(t[c[i]]);
    for i:=0 to 8 do write(fo,t[i],' ');
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
