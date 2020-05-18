uses    math;

const   MAX_N = 202;
        MODULE = 100000;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,i,j,k,len:longint;
    s:string;
    g:array[0..MAX_N,0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_N] of ll;
    ck,ok:array[0..MAX_N,0..MAX_N] of boolean;
    tmp:ll;


function    mmod(var x:ll):boolean;
begin
    if x < MODULE then exit(false);
    x:=x mod MODULE;
    exit(true);
end;

function    cmp(x,y:char):longint;
begin
    if (x = '(') and (y = ')') then exit(1);
    if (x = '[') and (y = ']') then exit(1);
    if (x = '{') and (y = '}') then exit(1);
    exit(0);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'MREPLBRC.in');    reset(fi);
    assign(fo,'MREPLBRC.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,n);
    readln(fi,s);
    for i:=1 to n do begin
        g[i][i]:=0;
        for j:=i+1 to n do
            if (s[i] = ')') or (s[i] = ']') or (s[i] = '}') then g[i][j]:=0
            else if (s[j] = '(') or (s[j] = '[') or (s[j] = '{') then g[i][j]:=0
            else if (s[i] = '?') and (s[j] = '?') then g[i][j]:=3
            else if (s[i] = '?') or (s[j] = '?') then g[i][j]:=1
            else g[i][j]:=cmp(s[i],s[j]);
    end;

    fillchar(ck,sizeof(ck),false);
    fillchar(ok,sizeof(ok),false);
    for i:=1 to n do f[i][i]:=0;
    for i:=1 to n-1 do begin
        f[i][i+1]:=g[i][i+1];
        ok[i][i+1]:=(f[i][i+1] > 0);
    end;

    len:=4;
    while len <= n do begin
        for i:=1 to n-len+1 do begin
            j:=i+len-1;
            f[i][j]:=0;
            k:=i+1;
            while k < j-1 do begin
                if (ok[i][k]) and (ok[k+1][j]) and (g[i][k] > 0) then begin
                    if (k-i > 1) and (not ok[i+1][k-1]) then begin
                        k:=k+2;
                        continue;
                    end;
                    tmp:=g[i][k];
                    if k-i > 1 then begin
                        tmp:=tmp*f[i+1][k-1];
                        ck[i][j]:=mmod(tmp) or ck[i][j] or ck[i+1][k-1];
                    end;
                    tmp:=tmp*f[k+1][j];
                    f[i][j]:=f[i][j]+tmp;
                    ck[i][j]:=mmod(f[i][j]) or ck[i][j] or ck[k+1][j];
                    ok[i][j]:=true;
                end;
                k:=k+2;
            end;
            if (ok[i+1][j-1]) and (g[i][j] > 0) then begin
                tmp:=g[i][j]*f[i+1][j-1];
                f[i][j]:=f[i][j]+tmp;
                ck[i][j]:=mmod(f[i][j]) or ck[i][j] or ck[i+1][j-1];
                ok[i][j]:=true;
            end;
        end;
        len:=len+2;
    end;

    str(f[1][n],s);
    if ck[1][n] then
        while (length(s) < 5) do s:='0'+s;
    writeln(fo,s);
    close(fi);
    close(fo);
end.