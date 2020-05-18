uses    math;

const   oo = 1000000000;

var fi,fo:text;
    t,a,s,r:array[0..1] of longint;


procedure   solve(id:longint);
var i,j,crr:longint;
begin
    for i:=0 to 1 do begin
        a[i]:=t[i];
        s[i]:=0;
    end;
    crr:=id;
    dec(a[id]);
    for i:=2 to t[0]+t[1] do
        if (i and 1) = 0 then begin
            j:=1-crr;
            if a[j] > 0 then inc(s[1])
            else begin
                j:=1-j;
                inc(s[0]);
            end;
            crr:=j;
            dec(a[j]);
        end
        else begin
            j:=crr;
            if a[j] > 0 then inc(s[0])
            else begin
                j:=1-j;
                inc(s[1]);
            end;
            crr:=j;
            dec(a[j]);
        end;
    if (s[0] > r[0]) or ((s[0] = r[0]) and (s[1] < r[1])) then begin
        r[0]:=s[0];
        r[1]:=s[1];
    end;
end;


begin
    assign(fi,'257B.in');    reset(fi);
    assign(fo,'257B.out');   rewrite(fo);
    readln(fi,t[0],t[1]);
    r[0]:=-1;
    r[1]:=oo;
    solve(0);
    solve(1);
    writeln(fo,r[0],' ',r[1]);
    close(fo);
    close(fi);
end.