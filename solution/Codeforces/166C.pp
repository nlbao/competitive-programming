var fi,fo:text;
    n,x,i,j:longint;
    a,b:array[0..2000] of longint;

procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=b[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while b[i] < p do inc(i);
        while b[j] > p do dec(j);
        if i <= j then begin
            t:=b[i];
            b[i]:=b[j];
            b[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;


begin
    assign(fi,'166C.in');   reset(fi);
    assign(fo,'166C.out');  rewrite(fo);
    randomize;
    readln(fi,n,x);
    for i:=1 to n do read(fi,a[i]);
    for i:=0 to n+10 do begin
        for j:=1 to n do b[j]:=a[j];
        for j:=n+1 to n+i do b[j]:=x;
        sort(1,n+i);
        if b[(n+i+1) div 2] = x then begin
            writeln(fo,i);
            break;
        end;
    end;
    close(fo);
    close(fi);
end.