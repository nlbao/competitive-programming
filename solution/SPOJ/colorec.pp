const   MAX_N = 100010;
        MAX_X = 210;

type    int = int64;

var fi,fo:text;
    n:longint;
    a:array[-MAX_X..MAX_X,-MAX_X..MAX_X] of longint;

procedure   enter;
var i,j,k,t:longint;
begin
    fillchar(a,sizeof(a),0);
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,j,k,t);
        a[j][k]:=t;
    end;
end;

procedure   solve;
var i,j,k:longint;
    res:int;
    c:array[0..7] of int;
begin
    res:=0;
    for i:=-MAX_X to MAX_X do
        for j:=i+1 to MAX_X do begin
            fillchar(c,sizeof(c),0);
            for k:=-MAX_X to MAX_X do
                if (a[i][k] > 0) and (a[j][k] > 0) then
                    inc(c[a[i][k] xor a[j][k]]);
            res:=res+c[1 xor 2]*c[3 xor 4]+c[1 xor 3]*c[2 xor 4]+c[1 xor 4]*c[2 xor 3];
            {res:=res+c[3]*c[7]+c[2]*c[6]+c[5]*c[1];}
        end;
    writeln(fo,res);
end;

begin
    assign(fi,'colorec.in');    reset(fi);
    assign(fo,'colorec.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.