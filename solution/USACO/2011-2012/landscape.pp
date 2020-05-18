uses    math;

const   MAX_N = 110;
        MAX_A = 13;
        MAX_M = MAX_N*MAX_A;

var fi,fo:text;
    n,i,j,k,x,y,z:longint;
    m:array[0..1] of longint;
    a:array[0..1,0..MAX_M] of longint;
    f:array[0..MAX_M,0..MAX_M] of longint;

procedure   push(x,c,id:longint);
var i:longint;
begin
    for i:=1 to c do begin
        inc(m[id]);
        a[id][m[id]]:=x;
    end;
end;

begin
    assign(fi,'landscape.in');  reset(fi);
    assign(fo,'landscape.out'); rewrite(fo);
    m[0]:=0;    m[1]:=0;
    readln(fi,n,x,y,z);
    for i:=1 to n do begin
        readln(fi,j,k);
        push(i,j,0);
        push(i,k,1);
    end;
    for i:=1 to m[1] do f[0][i]:=i*x;
    for i:=1 to m[0] do f[i][0]:=i*y;
    f[0][0]:=0;
    for i:=1 to m[0] do
        for j:=1 to m[1] do begin
            f[i][j]:=min(f[i-1][j]+y, f[i][j-1]+x);
            f[i][j]:=min(f[i][j], f[i-1][j-1]+z*abs(a[0][i]-a[1][j]));
        end;
    writeln(fo,f[m[0]][m[1]]);
    close(fo);
    close(fi);
end.