const   INPUT = '75D.in';
        OUTPUT = '75D.out';
        MAX_N = 60;
        MAX_M = 250010;
        MAX_L = 5010;
        MAX_INT = 1000000000000000000;

type    int = int64;

var fi,fo:text;
    n,m:longint;
    sum,left,right,mid:array[0..MAX_N] of int64;
    id:array[0..MAX_M] of longint;

function    max(x,y:int):int;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var i,j,len:longint;
    s:int64;
    a:array[0..MAX_L] of int64;
begin
    readln(fi,n,m);
    for i:=1 to n do begin
        read(fi,len);
        sum[i]:=0;  left[i]:=-MAX_INT;  mid[i]:=-MAX_INT;   s:=0;
        for j:=1 to len do begin
            read(fi,a[j]);
            sum[i]:=sum[i]+a[j];
            left[i]:=max(left[i],sum[i]);
            s:=max(s+a[j],a[j]);
            mid[i]:=max(mid[i],s);
        end;
        right[i]:=-MAX_INT;    s:=0;
        for j:=len downto 1 do begin
            s:=s+a[j];
            right[i]:=max(right[i],s);
        end;
    end;
    for i:=1 to m do read(fi,id[i]);
end;

procedure   solve;
var i,j:longint;
    s,res:int64;
begin
    s:=right[id[1]];    res:=mid[id[1]];
    for i:=2 to m do begin
        j:=id[i];
        res:=max(res,mid[j]);
        res:=max(res,s+left[j]);
        s:=max(s+sum[j],right[j]);
        s:=max(s,0);
    end;
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