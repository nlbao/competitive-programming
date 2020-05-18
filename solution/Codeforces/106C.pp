const   INPUT = '106C.in';
        OUTPUT = '106C.out';
        MAX_N = 1010;
        MAX_M = 15;

var fi,fo:text;
    n,m,nV:longint;
    a,b,c,d:array[0..MAX_M] of longint;
    f:array[0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m,c[0],d[0]);
    for i:=1 to m do readln(fi,a[i],b[i],c[i],d[i]);
    a[0]:=MAXLONGINT;   b[0]:=1;
end;

procedure   solve;
var i,j,k,t,w,v,res:longint;
begin
    fillchar(f,sizeof(f),0);
    for i:=0 to m do begin
        j:=min(a[i] div b[i],n div c[i]);
        k:=1;
        while j > 0 do begin
            k:=min(k,j);
            w:=c[i]*k; v:=d[i]*k;
            for t:=n downto w do f[t]:=max(f[t],f[t-w]+v);
            j:=j-k; k:=k+k;
        end;
    end;
    res:=0;
    for i:=1 to n do res:=max(res,f[i]);
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.