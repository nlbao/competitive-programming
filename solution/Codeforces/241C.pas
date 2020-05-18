{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 110;
        M = 100000.0;
        oo = 1000000000;
        eps = 0.0001;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n:longint;
    a,b:array[0..MAX_N] of double;
    types,v:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    hl,hr:double;



procedure   enter();
var i:longint;
    ch:char;
begin
    readln(fi,hl,hr,n);
    for i:=1 to n do begin
        read(fi,v[i]);
        read(fi,ch);    read(fi,ch);
        if ch = 'F' then types[i]:=0
        else types[i]:=1;
        readln(fi,a[i],b[i]);
        //writeln(i,'    ',v[i],' ',ch,'    ',a[i],'  ',b[i]);
    end;
end;


function    check(d,x,y:double; pre:longint):longint;
var i,j,sum:longint;
    found:boolean;
begin
    if (x >= 0) or (y <= M) then exit(0);
    sum:=0;
    for i:=1 to n do ok[i]:=true;
    x:=x+d;
    while M-x > eps do begin
        found:=false;
        for j:=1 to n do
            if (types[j] = pre) and (x-a[j] > eps) and (b[j]-x > eps) then
                if not ok[j] then exit(0)
                else begin
                    sum:=sum+v[j];
                    ok[j]:=false;
                    found:=true;
                    writeln(j,'    ',v[j],' ',types[j],' ',a[j]:0:0,' ',b[j]:0:0,'   ',x:0:6);
                    break;
                end;
        if not found then exit(0);
        pre:=(pre+1) and 1;
        x:=x+d;
    end;
    if abs(x-y) > eps then exit(0);

    writeln;
    writeln;

    exit(sum);
end;


procedure   solve();
var i,j,res:longint;
    d,x,y:double;
begin
    res:=0;
    for i:=2 to n+1 do begin
// //
        {d:=(hr-hl)/100+i-1;
        if d > 0 then begin
            d:=M/d;
            x:=(-hl/100)*d;
            y:=(1-hr/100)*d+M;
            res:=max(res,check(d,x,y,1));
        end;
// /\
        d:=-(hl+hr)/100+i;
        if d > 0 then begin
            d:=M/d;
            x:=(-hl/100)*d;
            y:=(hr/100)*d+M;
            res:=max(res,check(d,x,y,1));
        end;
// \/
        d:=(hl+hr)/100-2+i;
        if d > 0 then begin
            d:=M/d;
            x:=(hl/100-1)*d;
            y:=(1-hr/100)*d + M;
            res:=max(res,check(d,x,y,0));
        end;}

        if i < 10 then continue;
// \\
        d:=(hl-hr)/100-1+i;
        if d > 0 then begin
            d:=M/d;
            x:=(hl/100-1)*d;
            y:=(hr/100)*d+M;
            res:=max(res,check(d,x,y,0));
        end;

        if (res = 5857) then begin
            writeln(i,' ',d:0:3,'     ',x:0:4,' ',y:0:4);
            for j:=1 to n do
                if not ok[j] then
                    writeln(j,'    ',v[j],' ',types[j],' ',a[j]:0:0,' ',b[j]:0:0);
            break;
        end;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'241C.in');    reset(fi);
    assign(fo,'241C.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.

