uses    math;

const   MAX_N = 110;

var fi,fo:text;
    n,m,i,j,x,y,res:longint;
    s:array[0..MAX_N,0..MAX_N] of longint;


function    get_s(x1,y1,x2,y2:longint):longint;
begin   exit(s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1]);    end;


begin
    assign(fi,'mnered.in');     reset(fi);
    assign(fo,'mnered.out');    rewrite(fo);
    readln(fi,n,m);
    fillchar(s,sizeof(s),0);
    for i:=1 to m do begin
        read(fi,x,y);
        inc(s[x][y]);
    end;

    for i:=1 to n do
        for j:=1 to n do begin
            if s[i][j] > 0 then s[i][j]:=0
            else s[i][j]:=1;
            s[i][j]:=s[i-1][j] + s[i][j-1] - s[i-1][j-1] + s[i][j];
        end;

    res:=m+100;
    for i:=1 to n do
        for j:=1 to n do
            for x:=1 to min(m,n-i+1) do
                if m mod x = 0 then begin
                    y:=m div x;
                    if y <= n-j+1 then
                        res:=min(res,get_s(i,j,i+x-1,j+y-1));
                end;

    if res > m then res:=-1;
    writeln(fo,res);
    close(fo);
    close(fi);
end.