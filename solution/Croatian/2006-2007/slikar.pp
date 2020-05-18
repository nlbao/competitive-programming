const   MAX_N = 100;
        MAX_M = 100;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

var fi,fo:text;
    n,m,xS,yS,xD,yD,i,j,k,t,tl,tr,x,y:longint;
    a:array[0..MAX_N,0..MAX_M] of char;
    f:array[0..MAX_N,0..MAX_M] of longint;
    l,r:array[0..1] of longint;
    qx,qy:array[0..1,0..MAX_N*MAX_M] of longint;

procedure   up(var x,y:longint; xx,yy:longint);  begin   x:=xx;  y:=yy;  end;

procedure   push(id,x,y:longint);
begin
    inc(r[id]);
    up(qx[id][r[id]],qy[id][r[id]],x,y);
end;

procedure   pop(id:longint; var x,y:longint);
begin
    up(x,y,qx[id][l[id]],qy[id][l[id]]);
    inc(l[id]);
end;

begin
    assign(fi,'slikar.in');     reset(fi);
    assign(fo,'slikar.out');    rewrite(fo);
    l[0]:=1;    l[1]:=1;
    fillchar(r,sizeof(r),0);
    readln(fi,n,m);
    for i:=0 to n+1 do
        for j:=0 to m+1 do a[i][j]:='X';
    for i:=1 to n do begin
        for j:=1 to m do begin
            read(fi,a[i][j]);
            if a[i][j] = 'S' then up(xS,yS,i,j)
            else if a[i][j] = 'D' then up(xD,yD,i,j)
            else if a[i][j] = '*' then push(1,i,j);
        end;
        readln(fi);
    end;

    push(0,xS,yS);
    fillchar(f,sizeof(f),0);
    repeat
        tl:=l[0];   tr:=r[0];
        for t:=tl to tr do begin
            pop(0,i,j);
            if a[i][j] = '*' then continue;
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if (a[x][y] <> 'X') and (a[x][y] <> '*') and (a[x][y] <> 'S') then begin
                    a[x][y]:='S';
                    f[x][y]:=f[i][j]+1;
                    push(0,x,y);
                end;
            end;
        end;

        tl:=l[1];   tr:=r[1];
        for t:=tl to tr do begin
            pop(1,i,j);
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if (a[x][y] <> 'X') and (a[x][y] <> 'D') and (a[x][y] <> '*') then begin
                    a[x][y]:='*';
                    push(1,x,y);
                end;
            end;
        end;
    until (f[xD][yD] > 0) or (l[0] > r[0]);

    if f[xD][yD] = 0 then writeln(fo,'KAKTUS')
    else writeln(fo,f[xD][yD]);
    close(fo);
    close(fi);
end.