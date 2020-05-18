{$R+, $I+, $Q+}
{$M+ 16777216}

uses    math;

const   MAX_N = 202;
        eps = 0.0000001;
        oo = 1000000000;


var fi,fo:text;
    n,res,i,j,k:longint;
    x,y:array[0..MAX_N] of double;
    a,b,c:double;
    w:array[0..MAX_N] of longint;
    px,py:array[0..4] of double;


function    in_line(i,j,k:longint):boolean;
begin   exit((x[j]-x[i])*(y[k]-y[i]) = (x[k]-x[i])*(y[j]-y[i]));   end;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'c11trcnt.in');    reset(fi);
    assign(fo,'c11trcnt.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    for i:=1 to n do begin
        read(fi,x[i],y[i]);
        w[i]:=0;
    end;

    res:=0;
    for i:=1 to n do
        for j:=i+1 to n do
            for k:=j+1 to n do
                if not in_line(i,j,k) then begin
                    inc(res);
                    inc(w[i]);
                    inc(w[j]);
                    inc(w[k]);
                end;

    j:=1;
    for i:=2 to n do
        if w[i] < w[j] then j:=i;
    writeln(fo,res,' ',j);
    close(fi);
    close(fo);
end.
