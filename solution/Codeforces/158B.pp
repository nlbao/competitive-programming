var fi,fo:text;
    n,i,t,res:longint;
    c:array[1..4] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

begin
    assign(fi,'158B.in');   reset(fi);
    assign(fo,'158B.out');  rewrite(fo);
    fillchar(c,sizeof(c),0);
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,t);
        inc(c[t]);
    end;

    t:=min(c[3],c[1]);
    dec(c[3],t);
    dec(c[1],t);
    res:=c[4]+t+c[3];

    inc(res,c[2] div 2);
    c[2]:=c[2] mod 2;
    if c[2] = 1 then begin
        inc(res);
        if c[1] >= 1 then dec(c[1]);
        if c[1] >= 1 then dec(c[1]);
    end;

    res:=res+(c[1] div 4);
    if c[1] mod 4 > 0 then inc(res);

    writeln(fo,res);
    close(fo);
    close(fi);
end.