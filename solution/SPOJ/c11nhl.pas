uses    math;

const   MAX_N = 505;
        exp = 0.000000001;

type    recP = record
            x,y:longint;
            v:extended;
        end;

var fi,fo:text;
    m,n,d,i,j,ii,jj,x2,y2,nP,nRes:longint;
    s:array[0..MAX_N,0..MAX_N] of extended;
    p:array[0..MAX_N*MAX_N] of recP;
    ok:array[0..MAX_N,0..MAX_N] of boolean;
    rx,ry:array[0..MAX_N*MAX_N] of longint;


procedure   sort(l,r:longint);
var i,j,p2,p3:longint;
    p1,d:extended;
    t:recP;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=p[i].v;
    p2:=p[i].x;
    p3:=p[i].y;
    i:=l;   j:=r;
    repeat
        while (p[i].v-p1 > exp) or
              ((abs(p[i].v-p1) <= exp) and (p[i].x < p2)) or
              ((abs(p[i].v-p1) <= exp) and (p[i].x = p2) and (p[i].y < p3))
        do inc(i);

        while (p1-p[j].v > exp) or
            ((abs(p[j].v-p1) <= exp) and (p[j].x > p2)) or
            ((abs(p[j].v-p1) <= exp) and (p[j].x = p2) and (p[j].y > p3))
        do dec(j);

        if i <= j then begin
            t:=p[i];
            p[i]:=p[j];
            p[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


begin
    assign(fi,'c11nhl.in');     reset(fi);
    assign(fo,'c11nhl.out');    rewrite(fo);
    readln(fi,m,n,d);
    for i:=0 to max(m,n)+1 do begin
        s[0][i]:=0;
        s[i][0]:=0;
    end;
    for i:=1 to m do
        for j:=1 to n do begin
            read(fi,ii);
            s[i][j]:=ln(ii);
        end;
    for i:=1 to m do
        for j:=1 to n do
            s[i][j]:=s[i-1][j] + s[i][j-1] - s[i-1][j-1] + s[i][j];

    nP:=0;
    for i:=1 to m-d+1 do
        for j:=1 to n-d+1 do begin
            inc(nP);
            ii:=i+d-1;  jj:=j+d-1;
            with p[nP] do begin
                x:=i;   y:=j;
                v:=s[ii][jj] - s[ii][j-1] - s[i-1][jj] + s[i-1][j-1];
            end;
        end;
    randomize;
    sort(1,nP);


    nRes:=0;
    for i:=1 to m do
        for j:=1 to n do ok[i][j]:=true;
    for i:=1 to nP do with p[i] do begin
        x2:=x+d-1; y2:=y+d-1;
        if (not ok[x][y]) or (not ok[x][y2]) or (not ok[x2][y]) or (not ok[x2][y2]) then continue;
        inc(nRes);
        rx[nRes]:=x;    ry[nRes]:=y;
        for ii:=x to x2 do
            for jj:=y to y2 do
                ok[ii][jj]:=false;
    end;

    writeln(fo,nRes);
    for i:=1 to nRes do
        writeln(fo,rx[i],' ',ry[i]);
    close(fo);
    close(fi);
end.

