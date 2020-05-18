const   MAX_N = 100010;

var fi,fo:text;
    n,m,p:longint;
    a:array[0..MAX_N] of char;
    b,f,g,cf,cg,res:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;


procedure   enter;
var i,j:longint;
    ch:char;
begin
    readln(fi,n,m);
    for i:=1 to n do begin
        read(fi,a[i]);
        readln(fi,b[i]);
        if a[i] = '+' then inc(f[b[i]])
        else begin
            inc(g[b[i]]);
            inc(p);
        end;
    end;
end;

procedure   solve;
var i,j,c:longint;
begin
    c:=0;
    for i:=1 to n do begin
        ok[i]:=false;
        cf[i]:=0; cg[i]:=0;
        res[i]:=0;
    end;
    for i:=1 to n do
        if f[i]+(p-g[i]) = m then begin
            inc(c);
            ok[i]:=true;
        end;
    for i:=1 to n do
        if a[i] = '+' then begin
            inc(cg[i],c);
            if ok[b[i]] then begin
                dec(cg[i]);
                inc(cf[i]);
            end;
        end
        else begin
            inc(cf[i],c);
            if ok[b[i]] then begin
                dec(cf[i]);
                inc(cg[i]);
            end;
        end;
    for i:=1 to n do
        if cf[i] = c then begin
            res[i]:=1;
            dec(m);
        end
        else if cg[i] = c then res[i]:=-1;
    for i:=1 to n do
        if res[i] = 1 then writeln(fo,'Truth')
        else if (res[i] = -1) or ((res[i] = 0) and (m = 0)) then writeln(fo,'Lie')
        else writeln(fo,'Not defined');
end;

begin
    assign(fi,'157D.in');   reset(fi);
    assign(fo,'157D.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.