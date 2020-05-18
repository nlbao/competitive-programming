var fi,fo:text;
    n,k,i,j,c,res:longint;
    p,t:array[0..100] of longint;
    f:array[0..60,0..60] of longint;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

function    cmp(i,j:longint):longint;
begin
    if p[i] < p[j] then exit(-1);
    if p[i] > p[j] then exit(1);
    if t[i] > t[j] then exit(-1);
    if t[i] < t[j] then exit(1);
    exit(0);
end;

begin
    assign(fi,'166A.in');   reset(fi);
    assign(fo,'166A.out');  rewrite(fo);
    readln(fi,n,k);
    fillchar(f, sizeof(f), 0);
    for i:=1 to n do begin
        readln(fi,p[i],t[i]);
        inc(f[p[i]][t[i]]);
    end;
    for i:=1 to n-1 do
        for j:=i+1 to n do
            if cmp(i,j) < 0 then begin
                swap(p[i],p[j]);
                swap(t[i],t[j]);
            end;
    writeln(fo,f[p[k]][t[k]]);
    close(fo);
    close(fi);
end.
