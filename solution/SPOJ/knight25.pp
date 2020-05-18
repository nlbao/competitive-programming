const   MAX_N = 15;
        dx:array[1..8] of longint = (-2,-1,+1,+2,+2,+1,-1,-2);
        dy:array[1..8] of longint = (+1,+2,+2,+1,-1,-2,-2,-1);

var fi,fo:text;
    n,m,i,j:longint;
    x,y:array[0..sqr(MAX_N)] of longint;
    ok:array[-MAX_N..MAX_N,-MAX_N..MAX_N] of boolean;
    res:boolean;

procedure   init;
var i,j:longint;
begin
    res:=false;
    m:=0;
    fillchar(ok,sizeof(ok),true);
    for i:=1 to n do
        for j:=1 to n do ok[i][j]:=false;
end;

procedure   push(i,j:longint);
begin
    inc(m);
    x[m]:=i;    y[m]:=j;
    ok[i][j]:=true;
end;

procedure   tryf(i,j:longint);
var k,ii,jj:longint;
begin
    if m = n*n then res:=true;
    if res then exit;
    for k:=1 to 8 do begin
        ii:=i+dx[k];
        jj:=j+dy[k];
        if not ok[ii][jj] then begin
            push(ii,jj);
            tryf(ii,jj);
            if res then exit;
            dec(m);
            ok[ii][jj]:=false;
        end;
    end;
end;

begin
    assign(fi,'knight25.in');   reset(fi);
    assign(fo,'knight25.out');  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do begin
        for j:=1 to n do begin
            init;
            push(i,j);
            tryf(i,j);
            if res then break;
        end;
        if res then break;
    end;
    if not res then writeln(fo,'0 0')
    else begin
        for i:=1 to m do
            writeln(fo,x[i],' ',y[i]);
    end;
    close(fo);
    close(fi);
end.