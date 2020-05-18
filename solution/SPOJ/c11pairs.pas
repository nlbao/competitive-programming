const   MAX_N = 500010;

type    ll = int64;

var fi,fo:text;
    n,a,top,i,j:longint;
    s,c:array[0..MAX_N] of longint;
    f,res:ll;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'c11pairs.in');    reset(fi);
    assign(fo,'c11pairs.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    res:=0;     top:=0;
    for i:=1 to n do begin
        read(fi,a);
        f:=0;   j:=0;

        while (top > 0) and (s[top] <= a) do begin
            if s[top] = a then j:=c[top]+1;
            f:=f + 1 + c[top];
            dec(top);
        end;
        if top > 0 then f:=f+1;
        res:=res+f;

        inc(top);
        s[top]:=a;
        c[top]:=j;
    end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.