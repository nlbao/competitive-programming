const   MAX_N = 4010;
        MAX_K = 4010;
        M = 86400;

var fi,fo:text;
    n,k,res,i,j:longint;
    t,d:array[0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_K] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   up(var x:longint;   y:longint); begin   x:=min(x,y);    end;

begin
    assign(fi,'158E.in');   reset(fi);
    assign(fo,'158E.out');  rewrite(fo);
    readln(fi,n,k);
    for i:=1 to n do
        readln(fi,t[i],d[i]);
    res:=0;
    fillchar(f,sizeof(f),0);
    for i:=1 to n do begin
        f[i][0]:=max(f[i-1][0]+1,t[i])+d[i]-1;
        res:=max(res,t[i]-f[i-1][0]-1);
        for j:=1 to min(i,k) do begin
            f[i][j]:=f[i-1][j-1];
            if f[i-1][j] >= t[i] then
                up(f[i][j],f[i-1][j]+d[i])
            else begin
                up(f[i][j],t[i]+d[i]-1);
                res:=max(res,t[i]-f[i-1][j]-1);
            end;
        end;
    end;
    res:=max(res,M-f[n][k]);
    writeln(fo,res);
    close(fo);
    close(fi);
end.
