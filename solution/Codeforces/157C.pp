const   MAX_N = 2003;

var fi,fo:text;
    s,u:ansiString;
    n,m,i,j,d,res:longint;
    f:array[-MAX_N..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

begin
    assign(fi,'157C.in');   reset(fi);
    assign(fo,'157C.out');  rewrite(fo);
    readln(fi,s);   n:=length(s);
    readln(fi,u);   m:=length(u);
    fillchar(f,sizeof(f),0);
    res:=0;
    for i:=1 to n do
        for j:=1 to m do begin
            d:=i-j;
            f[d]:=f[d]+longint(s[i] = u[j]);
            res:=max(res,f[d]);
        end;
    writeln(fo,m-res);
    close(fo);
    close(fi);
end.