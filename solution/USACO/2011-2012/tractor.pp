const   MAX_X = 1005;
        oo = 1000000000;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

type    recPoint = record
            x,y:longint;
        end;

var fi,fo:text;
    n,x0,y0:longint;
    l,r:array[0..1] of longint;
    q:array[0..1,0..sqr(MAX_X)] of recPoint;
    a,f:array[-1..MAX_X,-1..MAX_X] of longint;


procedure   enter;
var i,x,y:longint;
begin
    fillchar(a,sizeof(a),0);
    readln(fi,n,x0,y0);
    for i:=1 to n do begin
        readln(fi,x,y);
        a[x][y]:=1;
    end;
end;

procedure   empty(i:longint);   begin   l[i]:=1;    r[i]:=0;    end;

procedure   push(i,xx,yy:longint);
begin
    inc(r[i]);
    q[i][r[i]].x:=xx;
    q[i][r[i]].y:=yy;
end;

procedure   pop(i:longint;  var xx,yy:longint);
begin
    xx:=q[i][l[i]].x;
    yy:=q[i][l[i]].y;
    inc(l[i]);
end;

function    ok(x:longint):boolean;  begin   if (x < 0) or (x > MAX_X) then exit(false);  exit(true); end;

procedure   solve;
var i,j,k,x,y:longint;
begin
    empty(0);   empty(1);
    fillchar(f, sizeof(f), 0);
    f[x0][y0]:=1;
    push(0,x0,y0);

    while (f[0][0] = 0) and ((l[0] <= r[0]) or (l[1] <= r[1])) do begin
        if (l[0] > r[0]) then pop(1,x,y)
        else pop(0,x,y);
        for k:=1 to 4 do begin
            i:=x+dx[k]; j:=y+dy[k];
            if (ok(i)) and (ok(j)) and (f[i][j] = 0) then begin
                f[i][j]:=f[x][y]+a[i][j];
                push(a[i][j],i,j);
            end;
        end;
    end;
    writeln(fo,f[0][0]-1);
end;


begin
    assign(fi,'tractor.in');    reset(fi);
    assign(fo,'tractor.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
