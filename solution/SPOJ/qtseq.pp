uses    math;

const   MAX_N = 1000010;

var fi,fo:text;
    n,i,j:longint;
    t,res,c:int64;
    s,f,g:array[0..MAX_N] of longint;
    cf,cg:array[0..MAX_N] of int64;

procedure   solve(var res,c:int64);
var i:longint;
    tf,tg,t:int64;
begin
    f[n-1]:=s[n-1]; cf[n-1]:=1;
    g[n-1]:=s[n-1]; cg[n-1]:=1;
    for i:=n-2 downto 1 do begin
        if s[i] > f[i+1] then begin
            f[i]:=s[i];
            cf[i]:=1;
        end
        else begin
            f[i]:=f[i+1];
            cf[i]:=cf[i+1];
            if s[i] = f[i+1] then inc(cf[i]);
        end;

        if s[i] < g[i+1] then begin
            g[i]:=s[i];
            cg[i]:=1;
        end
        else begin
            g[i]:=g[i+1];
            cg[i]:=cg[i+1];
            if s[i] = g[i+1] then inc(cg[i]);
        end;
    end;

    res:=-1;    c:=0;
    for i:=1 to n-1 do begin
        tf:=abs(s[i]+f[i]-s[n]);
        tg:=abs(s[i]+g[i]-s[n]);
        t:=max(tf,tg);
        if t > res then begin
            res:=t;
            if (tf = tg) and (f[i] <> g[i]) then c:=cf[i]+cg[i]
            else if t = tf then c:=cf[i]
            else c:=cg[i];
        end
        else if t = res then begin
            if (tf = tg) and (f[i] <> g[i]) then c:=c+cf[i]+cg[i]
            else if t = tf then c:=c+cf[i]
            else c:=c+cg[i];
        end;
    end;
end;


begin
    assign(fi,'qtseq.in');  reset(fi);
    assign(fo,'qtseq.out'); rewrite(fo);

    read(fi,n);
    s[0]:=0;
    for i:=1 to n do begin
        read(fi,s[i]);
        s[i]:=s[i-1]+s[i];
    end;

    solve(res,c);
    writeln(fo,res,' ',c);

    close(fo);
    close(fi);
end.


