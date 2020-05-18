uses    math;

const   MAX_N = 210;
        MAX_A = 40010;
        oo = 2000000000;

var fi,fo:text;
    n,a,b,i,j,res,d:longint;
    h,s:array[0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_A,0..1] of longint;


begin
    assign(fi,'input.txt');   reset(fi);
    assign(fo,'output.txt');  rewrite(fo);
    readln(fi,n);
    readln(fi,a,b);
    s[0]:=0;    h[0]:=0;
    for i:=1 to n do begin
        read(fi,h[i]);
        s[i]:=s[i-1]+h[i];
    end;

    for j:=0 to a do begin
        f[1][j][0]:=oo;
        f[1][j][1]:=oo;
    end;
    if h[1] <= a then f[1][h[1]][0]:=0;
    if h[1] <= b then f[1][0][1]:=0;

    for i:=2 to n do begin
        d:=min(h[i],h[i-1]);
        for j:=0 to a do begin
            f[i][j][0]:=oo;
            f[i][j][1]:=oo;
            if (0 <= s[i]-j) and (s[i]-j <= b) then begin
                if j >= h[i] then
                    f[i][j][0]:=min(f[i-1][j-h[i]][0], f[i-1][j-h[i]][1] + d);
                f[i][j][1]:=min(f[i-1][j][0] + d, f[i-1][j][1]);
            end;
        end;
    end;

    res:=oo;
    for i:=0 to a do res:=min(res,min(f[n][i][0],f[n][i][1]));
    if res = oo then res:=-1;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
