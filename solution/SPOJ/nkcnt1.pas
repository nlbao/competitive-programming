uses    math;

const   MAX_N = 5003;

var fi,fo:text;
    m,n,i,j,t,tt,g:longint;
    a:ansiString;
    h:array[0..MAX_N] of longint;
    f:array[0..1,0..MAX_N] of longint;
    res:int64;

begin
    assign(fi,'nkcnt1.in');     reset(fi);
    assign(fo,'nkcnt1.out');    rewrite(fo);
    readln(fi,m,n);

    res:=0;
    t:=0;
    for i:=0 to n+1 do begin
        h[i]:=0;
        f[t][i]:=0;
    end;

    for i:=1 to m do begin
        readln(fi,a);
        tt:=t;
        t:=(t+1) and 1;
        g:=0;
        for j:=1 to n do begin
            if a[j] = '0' then begin
                inc(h[j]);
                inc(g);
            end
            else begin
                h[j]:=0;
                g:=0;
            end;
            f[t][j]:=min(min(h[j],g), f[tt][j-1]+1);
            res:=res + int64(f[t][j]);
        end;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.


