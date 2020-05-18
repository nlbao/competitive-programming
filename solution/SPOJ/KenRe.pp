const   INPUT = 'KenRe.in';
        OUTPUT = 'KenRe.out';
        MAX_N = 3;
        M = 6;
        MAX_INT = 1000000000;

type    arr = array[0..M] of longint;

var fi,fo:text;
    nTest,n:longint;
    x,y:array[0..M] of longint;
    d:array[1..MAX_N] of arr;


function    min(x,y:longint):longint;   begin   if x < y then exit(x) else exit(y); end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x) else exit(y); end;

procedure   enter;
var i,j:longint;
    p,q:arr;
begin
    for i:=1 to M do read(fi,y[i]);
    for i:=1 to M do read(fi,x[i]);
    readln(fi,n);
    for i:=1 to n do begin
        for j:=1 to M do read(fi,p[j]);
        for j:=1 to M do read(fi,q[j]);
        for j:=1 to M do d[i][j]:=q[j]-p[j];
    end;
end;

function    check:boolean;
var i:longint;
begin
    for i:=1 to M do
        if x[i] < y[i] then exit(false);
    exit(true);
end;

procedure   cal(i,p:longint);
var j:longint;
begin
    for j:=1 to M do
        x[j]:=x[j]+p*d[i][j];
end;

procedure   solve;
var i,j,k,h,p,limit,res:longint;
    t1,t2,t3:arr;
begin
    if check = true then begin
        writeln(fo,0);
        exit;
    end
    else res:=MAX_INT;
    limit:=1000;
    if n > 0 then
        for i:=0 to limit do begin
            t1:=x;
            cal(1,i);
            if check = true then begin
                res:=min(res,i);
                break;
            end
            else if n > 1 then
                for j:=0 to limit-i do begin
                    t2:=x;
                    cal(2,j);
                    if check = true then begin
                        res:=min(res,i+j);
                        break;
                    end
                    else if n > 2 then begin
                        k:=1;
                        for h:=1 to 6 do
                            if (x[h] < y[h]) and (d[3][h] > 0) then begin
                                p:=(y[h]-x[h]) div d[3][h];
                                if (y[h]-x[h]) mod d[3][h] <> 0 then p:=p+1;
                                k:=max(k,p);
                            end;
                        cal(3,k);
                        if check = true then res:=min(res,i+j+k);
                    end;
                    x:=t2;
                end;
            x:=t1;
        end;
    if res = MAX_INT then writeln(fo,':(')
    else writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
   close(fo);
    close(fi);
end.
