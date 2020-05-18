const   MAX_N = 20010;

var fi,fo:text;
    n,i,res,c:longint;
    a:array[0..MAX_N] of longint;

procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=a[i];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j];     a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


begin
    assign(fi,'noixich.in');    reset(fi);
    assign(fo,'noixich.out');   rewrite(fo);
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    randomize;
    sort(1,n);

    res:=0;
    c:=n;
    for i:=1 to n do begin
        c:=c-1;
        if a[i] = c-1 then begin
            res:=res+a[i];
            break;
        end
        else if a[i] < c-1 then begin
            res:=res+a[i];
            c:=c-a[i];
        end
        else begin
            res:=res+c;
            break;
        end;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.