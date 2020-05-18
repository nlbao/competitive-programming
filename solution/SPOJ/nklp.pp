uses    math;

const   MAX_N = 100010;

var fi,fo:text;
    n,i,j,t,res,maxR:longint;
    a:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;


procedure   check(p:longint);
var i,j,r,d:longint;
    ck:boolean;
begin
    res:=max(res,1);
    ok[1]:=true;
    d:=1;   r:=p;
    for i:=p-1 downto 1 do
        if ok[a[i]] then exit
        else begin
            ok[a[i]]:=true;
            d:=max(d,a[i]);
            if (i+d-1 > n) or (i+d-1 < p) then continue;
            ck:=true;
            while (r < i+d-1) and (ck) do begin
                inc(r);
                if (ok[a[r]]) or (a[r] > d) then ck:=false
                else ok[a[r]]:=true;
            end;
            maxR:=max(maxR,r);
            if ck = false then dec(r);
            while (r > i+d-1) do begin
                ok[a[r]]:=false;
                dec(r);
            end;
            if (r = i+d-1) and (ck) then res:=max(res,d);
        end;
end;

procedure   solve;
var i,j,pre:longint;
begin
    fillchar(ok,sizeof(ok),false);
    pre:=1;
    for i:=1 to n do
        if a[i] = 1 then begin
            maxR:=max(maxR,i);
            for j:=pre to maxR do ok[a[j]]:=false;
            pre:=i;
            check(i);
        end;
end;

begin
    assign(fi,'nklp.in');   reset(fi);
    assign(fo,'nklp.out');  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    res:=0;
    solve;
    for i:=1 to (n shr 1) do begin
        t:=a[i];
        a[i]:=a[n-i+1];
        a[n-i+1]:=t;
    end;
    solve;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
