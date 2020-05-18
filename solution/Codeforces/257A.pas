uses    math;

var fi,fo:text;
    n,m,k,t,sum,res,i,j:longint;
    a:array[0..111] of longint;


begin
    assign(fi,'257A.in');    reset(fi);
    assign(fo,'257A.out');   rewrite(fo);
    readln(fi,n,m,k);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do
        for j:=i+1 to n do
            if a[j] > a[i] then begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
            end;

    res:=0;
    sum:=k;
    while (res < n) and (m > sum) do begin
        inc(res);
        sum:=sum - 1 + a[res];
    end;

    if m > sum then res:=-1;
    writeln(fo,res);
    close(fo);
    close(fi);
end.

