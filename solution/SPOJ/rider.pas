{$M 16777216}
uses    math;

const   MAX_N = 100005;
        oo = 1000000000000000000;

type    ll = int64;

var fi,fo:text;
    n,m:longint;
    s,t:array[0..MAX_N] of double;

procedure   enter();
var i:longint;
begin
    read(fi,m);
    for i:=1 to m do read(fi,t[i]);
    read(fi,n);
    for i:=1 to n do read(fi,s[i]);
end;

procedure   solve_0();
var i,j:longint;
    v,len:double;
begin
    for i:=1 to n do begin
        v:=oo;
        for j:=1 to m do
            if t[j] > s[i] then
                v:=min(v,double(j)/(t[j]-s[i]));
        writeln(fo,v:0:6);
    end;
end;

begin
    assign(fi,'RIDER.inp');   reset(fi);
    assign(fo,'RIDER.out');   rewrite(fo);
    enter();
    solve_0();
    close(fo);
    close(fi);
end.