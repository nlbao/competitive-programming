
var fi,fo:text;
    n,m,res:longint;
    x:array[0..1010] of longint;

procedure   enter;
var i,j,a,b:longint;
begin
    res:=0;
    n:=0;   m:=1;
    readln(fi,j);
    for i:=1 to j do begin
        readln(fi,a,b);
        if b > 0 then begin
            res:=res+a;
            m:=m+b-1;
        end
        else begin
            inc(n);
            x[n]:=a;
        end;
    end;
end;

procedure   solve;
var i,j,t:longint;
begin
    for i:=1 to n-1 do
        for j:=i+1 to n do
            if x[i] < x[j] then begin
                t:=x[i];
                x[i]:=x[j];
                x[j]:=t;
            end;
    if m < n then n:=m;
    for i:=1 to n do res:=res+x[i];
    writeln(fo,res);
end;


begin
    assign(fi,'155B.in');   reset(fi);
    assign(fo,'155B.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
