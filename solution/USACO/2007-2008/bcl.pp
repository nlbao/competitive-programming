uses    math;

var fi,fo:text;
    s,t:ansiString;
    n,i,l,r:longint;
    ch:char;

function    check(l,r:longint):boolean;
begin
    while r > l do begin
        if s[l] < s[r] then exit(true)
        else if s[l] > s[r] then exit(false);
        inc(l); dec(r);
    end;
    exit(true);
end;

begin
    assign(fi,'bcl.in');    reset(fi);
    assign(fo,'bcl.out');   rewrite(fo);
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,ch);
        s:=s+ch;
    end;
    l:=1;   r:=n;
    while l < r do begin
        if check(l,r) = true then begin
            write(fo,s[l]);
            inc(l);
        end
        else begin
            write(fo,s[r]);
            dec(r);
        end;
    end;
    if l = r then write(fo,s[l]);
    close(fo);
    close(fi);
end.
