uses    math;

const   MAX_M = 1501;
        MAX_N = 1501;
        MAX_P = MAX_M*MAX_N;
        oo = 1000000000;
        dx:array[1..4] of longint = (+1,-1,0,0);
        dy:array[1..4] of longint = (0,0,+1,-1);


type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    s:ansiString;
    m,n,x1,y1,x2,y2:longint;
    l,r:array[0..1] of longint;
    a:array[0..MAX_M] of ansiString;
    ok:array[0..MAX_M,0..MAX_N] of boolean;
    qx,qy:array[0..1,0..MAX_P] of longint;
    in_queue:array[0..1,0..MAX_M,0..MAX_N] of boolean;



procedure   enter();
var i,j:longint;
begin
    x1:=-1;
    readln(fi,m,n);
    for i:=1 to m do begin
        readln(fi,a[i]);
        for j:=1 to n do begin
            if a[i][j] = 'L' then
                if x1 = -1 then begin   x1:=i;  y1:=j;  end
                else begin x2:=i;   y2:=j;  end;
            ok[i][j]:=true;
        end;
    end;
    j:=max(n,m)+1;
    for i:=0 to j do begin
        ok[0][i]:=false;    ok[0][j]:=false;
        ok[i][0]:=false;    ok[j][0]:=false;
    end;
end;


procedure   push(i,x,y:longint);
begin
    if in_queue[i,x,y] then exit;
    inc(r[i]);
    qx[i][r[i]]:=x;
    qy[i][r[i]]:=y;
    in_queue[i,x,y]:=true;
end;


procedure   pop(i:longint;  var x,y:longint);
begin
    x:=qx[i][l[i]];
    y:=qy[i][l[i]];
    inc(l[i]);
end;


function    check(i,j:longint):boolean;
var k,x,y:longint;
begin
    if in_queue[0][i][j] then exit(false);
    for k:=1 to 4 do begin
        x:=i+dx[k];
        y:=j+dy[k];
        if (ok[x][y]) and (in_queue[0][x][y]) then exit(true);
    end;
    exit(false);
end;


function    solve():longint;
var i,j,k,x,y,res,pL,pR:longint;
begin
    res:=0;
    for i:=1 to m do
        for j:=1 to n do
            for k:=0 to 1 do
                in_queue[k][i][j]:=false;

    l[0]:=1;    r[0]:=0;
    l[1]:=1;    r[1]:=0;
    push(0,x1,y1);
    for i:=1 to m do
        for j:=1 to n do
            if a[i][j] <> 'X' then
                push(1,i,j);

    repeat
        while l[0] <= r[0] do begin
            pop(0,i,j);
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if (ok[x][y]) and (a[x][y] <> 'X') then
                    push(0,x,y);
            end;
        end;
        if in_queue[0][x2][y2] then exit(res);

        res:=res+1;

        pR:=r[1];
        while l[1] <= pR do begin
            pop(1,i,j);
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if (ok[x][y]) and (a[x][y] = 'X') then begin
                    a[x][y]:='.';
                    push(1,x,y);
                    if check(x,y) then push(0,x,y);
                end;
            end;
        end;
    until false;
    exit(-1);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,{'test.in'}'LABUDOVI.in');   reset(fi);
    assign(fo,'LABUDOVI.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    writeln(fo,solve());
    close(fi);
    close(fo);
end.