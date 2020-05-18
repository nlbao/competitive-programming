const   MAX_N = 110;
        MAX_M = 110;
        oo = 1000000000;

type    myStr = ansiString;

var fi,fo:text;
    n,m:longint;
    s:myStr;
    w:array['a'..'z','a'..'z'] of longint;
    f:array[0..MAX_N,0..MAX_M,'a'..'z'] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i,j:longint;
    x,y:char;
    t:myStr;
begin
    readln(fi,s);
    n:=length(s);
    i:=1;
    while (s[i] <> ' ') do inc(i);
    t:=copy(s,i+1,n-i);
    val(t,m);
    fillchar(w,sizeof(w),0);
    readln(fi,j);
    for i:=1 to j do begin
        read(fi,x);
        read(fi,y); read(fi,y);
        readln(fi,w[x][y]);
    end;
end;

procedure   solve;
var i,j,res:longint;
    k,kk:char;
begin
    res:=0;
    for i:=1 to n do
        for j:=0 to m do
            for k:='a' to 'z' do f[i][j][k]:=-oo;
    f[1][0][s[1]]:=0;
    for k:='a' to 'z' do f[1][1][k]:=0;

    for i:=2 to n do begin
        f[i][0][s[i]]:=f[i-1][0][s[i-1]]+w[s[i-1]][s[i]];
        res:=max(res,f[i][0][s[i]]);
        for j:=1 to min(i,m) do
            for k:='a' to 'z' do begin
                for kk:='a' to 'z' do
                    if k = s[i] then
                        f[i][j][k]:=max(f[i][j][k],f[i-1][j][kk]+w[kk][k])
                    else
                        f[i][j][k]:=max(f[i][j][k],f[i-1][j-1][kk]+w[kk][k]);
                res:=max(res,f[i][j][k]);
                if f[i][j][k] > 100 then writeln('!');
            end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'73C.in');    reset(fi);
    assign(fo,'73C.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.