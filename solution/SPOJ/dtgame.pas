uses    math;

const   MAX_N = 2003;
        oo = 1000000000;

var fi,fo:text;
    n,i,j,k,len,v:longint;
    a:array[0..MAX_N] of longint;
    pos,f:array[0..MAX_N,0..MAX_N] of longint;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'DTGAME.in');    reset(fi);
    assign(fo,'DTGAME.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    a[0]:=0;
    for i:=1 to n do begin
        read(fi,a[i]);
        a[i]:=a[i]+a[i-1];
    end;

    for i:=1 to n do begin
        f[i][i]:=0;
        pos[i][i]:=i;
    end;

    for len:=2 to n do
        for i:=1 to n-len+1 do begin
            j:=i+len-1;
            f[i][j]:=-1;
            for k:=pos[i][j-1] to pos[i+1][j] do begin
                v:=min(a[k-1]-a[i-1]+f[i][k-1], a[j]-a[k-1]+f[k][j]);
                if v > f[i][j] then begin
                    f[i][j]:=v;
                    pos[i][j]:=k;
                end;
            end;
        end;
    writeln(fo,f[1][n]);
    close(fi);
    close(fo);
end.