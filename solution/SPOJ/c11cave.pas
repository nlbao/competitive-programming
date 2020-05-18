{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 200010;
        MAX_H = 500010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,h,i,t,x,y,sum,res,c:longint;
    a,b:array[0..MAX_H] of longint;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'c11cave.in');    reset(fi);
    assign(fo,'c11cave.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n,h);
    for i:=1 to h do begin
        a[i]:=0;
        b[i]:=0;
    end;
    t:=0;
    for i:=1 to n do begin
        t:=(t+1) and 1;
        if t = 1 then begin
            x:=1;
            read(fi,y);
        end
        else begin
            read(fi,x);
            x:=h-x+1;
            y:=h;
        end;
        inc(a[x]);
        inc(b[y]);
    end;

    res:=n; c:=1;
    sum:=0;
    for i:=1 to h do begin
        sum:=sum+a[i];
        if sum < res then begin
            res:=sum;
            c:=1;
        end
        else if sum = res then inc(c);
        sum:=sum-b[i];
    end;
    writeln(fo,res,' ',c);
    close(fi);
    close(fo);
end.

