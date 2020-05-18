const   INPUT = 'mono.in';
        OUTPUT = 'mono.out';
        MAX_N = 510;
        MAX_M = 510;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do begin
        for j:=1 to m do read(fi,a[i][j]);
        readln(fi);
    end;
    readln(fi,v);
    for i:=1 to p do read(fi,x[i],y[i]);
    x[p+1]:=x[1]; y[p+1]:=y[1];
end;

function    check(u,v:longint):boolean;
begin
    ch:=a[u][v];
    for k:=2 to n+1 do
        if x[k] <> u then begin
            if x[k] < u then d:=-1
            else d:=1;
            if a[u]
            while u <> x[k] do begin

            end;
        end
        else if y[k] <> v then begin

        end;
    exit(true);
end;

procedure   solve;
var i,j,k,u,v,front,rear,res:longint;
    qx,qy:array[0..MAX_N*MAX_M] of longint;
    avail:array[0..MAX_N,0..MAX_N] of boolean;
begin
    res:=0;
    front:=1;   rear:=1;
    qx[1]:=x[1];    qy[1]:=y[1];
    fillchar(avail,sizeof(avail),true);
    avail[x[1]][y[1]]:=false;
    repeat
        i:=qx[front];   j:=qy[front];   inc(front);
        for k:=1 to 4 do begin
            u:=i+dx[k]; v:=j+dy[k];
            if (avail[u][v]) and (check(u,v) = true) then begin
                inc(res);
                inc(rear);  qx[rear]:=u;    qy[rear]:=v;
            end;
            avail[u][v]:=false;
        end;
    until front > rear;
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