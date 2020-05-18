

var fi,fo:text;
    n,i:longint;
    a,d,y:double;
    t,v,r:array[0..100010] of double;

begin
    assign(fi,'168C.in');   reset(fi);
    assign(fo,'168C.out');  rewrite(fo);
    readln(fi,n,a,d);
    r[0]:=0;
    for i:=1 to n do begin
        readln(fi,t[i],v[i]);
        r[i]:=sqrt(2*d/a);
        y:=v[i]/a;
        if y <= r[i] then r[i]:=y+(d-a*y*y/2)/v[i];
        r[i]:=r[i]+t[i];
        if r[i] < r[i-1] then r[i]:=r[i-1];
        writeln(fo,r[i]:0:6);
    end;
    close(fo);
    close(fi);
end.