uses    math;

const   MAX_N = 55;

type    arr = array[0..MAX_N,0..MAX_N] of longint;

var fi,fo:text;
    na,ma,nb,mb,i,j,ii,jj,x,y,s,res,rx,ry,ln,lm:longint;
    a,b:arr;

procedure   enter(var x:arr;    n,m:longint);
var i,j:longint;
    c:char;
begin
    for i:=1 to n do begin
        for j:=1 to m do begin
            read(fi,c);
            x[i][j]:=ord(c)-ord('0');
        end;
        readln(fi);
    end;
end;


begin
    assign(fi,'228B.in');   reset(fi);
    assign(fo,'228B.out');  rewrite(fo);
    readln(fi,na,ma);
    enter(a,na,ma);
    readln(fi,nb,mb);
    enter(b,nb,mb);

    rx:=1;  ry:=1;  res:=0;
    ln:=max(na,nb)+1;
    lm:=max(ma,mb)+1;
    for x:=-ln to ln do
        for y:=-lm to lm do begin
            s:=0;
            for i:=1 to na do
                for j:=1 to ma do begin
                    ii:=i+x;    jj:=j+y;
                    if (1 <= ii) and (ii <= nb) and (1 <= jj) and (jj <= mb) then
                        s:=s+a[i][j]*b[ii][jj];
                end;
            if s > res then begin
                res:=s;
                rx:=x;  ry:=y;
            end;
        end;
    writeln(fo,rx,' ',ry);
    close(fo);
    close(fi);
end.