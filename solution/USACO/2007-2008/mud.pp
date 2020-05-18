const   MAX_N  = 10010;
        MAX_X = 510;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

var fi,fo:text;
    n,x,y,i,j,k,l,r:longint;
    mud:array[-MAX_X..MAX_X,-MAX_X..MAX_X] of boolean;
    c:array[-MAX_X..MAX_X,-MAX_X..MAX_X] of longint;
    qx,qy:array[0..sqr(2*MAX_X)] of longint;

function    ok(x:longint):boolean;  begin   if (x > MAX_X) or (x < -MAX_X) then exit(false);    exit(true); end;

procedure   push(i,j,cc:longint);
begin
    if (not ok(i)) or (not ok(j)) or (mud[i][j]) or (c[i][j] > 0) then exit;
    inc(r);
    qx[r]:=i;   qy[r]:=j;
    c[i][j]:=cc;
end;

procedure   pop(var i,j:longint);
begin
    i:=qx[l];   j:=qy[l];
    inc(l);
end;

begin
    assign(fi,'mud.in');    reset(fi);
    assign(fo,'mud.out');   rewrite(fo);
    fillchar(mud,sizeof(mud),false);
    readln(fi,x,y,n);
    for i:=1 to n do begin
        readln(fi,j,k);
        mud[j][k]:=true;
    end;

    fillchar(c,sizeof(c),0);
    l:=1;   r:=0;
    push(0,0,1);
    repeat
        pop(i,j);
        for k:=1 to 4 do
            push(i+dx[k],j+dy[k],c[i][j]+1);
    until (c[x][y] > 0) or (l > r);
    writeln(fo,c[x][y]-1);
    close(fo);
    close(fi);
end.