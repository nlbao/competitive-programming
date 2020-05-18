
{   PROB: baleshare
    LANG: PASCAL
    ID: storm59061
}

const   MAX_N = 30;
        oo = 1000000000;

var fi,fo:text;
    n:longint;
    a,id:array[0..MAX_N] of longint;
    g:array[0..1050000] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

function    get_bit(k,x:longint):longint;   begin   exit((x shr (k-1)) and 1);  end;

procedure   cal_g;
var i,j,k,m,s,s2:longint;
begin
    for i:=0 to (1 shl n)-1 do begin
        g[i]:=oo;
        s:=0;   m:=0;
        for j:=1 to n do
            if get_bit(j,i) = 1 then begin
                s:=s+a[j];
                inc(m); id[m]:=j;
            end;
        for k:=0 to (1 shl m)-1 do begin
            s2:=0;
            for j:=1 to m do
                if get_bit(j,k) = 1 then s2:=s2+a[id[j]];
            if s2 >= s-s2 then g[i]:=min(g[i],s2);
        end;
    end;
end;

procedure   solve;
var i,j,k,s,res:longint;
begin
    cal_g;
    res:=oo;
    for i:=0 to (1 shl n)-1 do begin
        s:=0;   k:=0;
        for j:=1 to n do
            if get_bit(j,i) = 1 then s:=s+a[j]
            else k:=k or (1 shl (j-1));
        if s >= g[k] then res:=min(res,s);
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'baleshare.in');  reset(fi);
    assign(fo,'baleshare.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.