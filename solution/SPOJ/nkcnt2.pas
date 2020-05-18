uses    math;

const   MAX_N = 3003;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,m:longint;
    ok:array[0..MAX_N,0..MAX_N,0..1] of boolean;
    f:array[0..1,0..MAX_N] of longint;


procedure   enter();
var i,j,k,t:longint;
begin
    read(fi,n,m);
    fillchar(ok,sizeof(ok),true);
    for i:=n downto 1 do begin
        for j:=1 to n+1-i do ok[i][j][1]:=false;
        for j:=1 to n-i do ok[i][j][0]:=false;
    end;
    t:=(n+1) and 1;
    while m > 0 do begin
        read(fi,i,j,k);
        ok[i][j][(i+j+k+t) and 1]:=true;
        dec(m);
    end;
end;


procedure   solve();
var i,j,k,t,tt:longint;
    res:ll;
begin
    res:=0;
    t:=0;
    fillchar(f,sizeof(f),0);
    for i:=n downto 1 do begin
        tt:=t;
        t:=(t+1) and 1;
        for j:=1 to n+1-i do begin
            if ok[i][j][1] then f[t][j]:=0
            else
                if ok[i][j-1][0] then f[t][j]:=1
                else f[t][j]:=min(f[t][j-1],f[tt][j-1])+1;
            res:=res+int64(f[t][j]);
        end;
    end;

    t:=0;
    fillchar(f,sizeof(f),0);
    for i:=n downto 1 do begin
        tt:=t;
        t:=(t+1) and 1;
        for j:=1 to n-i do begin
            if ok[i][j][0] then f[t][j]:=0
            else
                if ok[i+1][j][1] then f[t][j]:=1
                else f[t][j]:=min(f[tt][j-1],f[tt][j])+1;
            res:=res+int64(f[t][j]);
        end;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKCNT2.in');    reset(fi);
    assign(fo,'NKCNT2.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.