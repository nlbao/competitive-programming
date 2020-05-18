{$N+}
const
    INPUT = '';
    OUTPUT = '';
    MAX_N = 100000;
    Eps = 0.00001;

type
    point = record
        x,y:double;
    end;
    lines = record
        p1,p2:point;
        a,b,c:double;
    end;

var
    fi,fo:text;
    N:longint;
    L:array[1..MAX_N] of lines;

procedure   extract(p1,p2:point;    var a,b,c:double);
begin
    a:=p1.y-p2.y;
    b:=p2.x-p1.x;
    c:=-(a*p1.x+b*p1.y);
end;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do begin
        readln(fi,L[i].p1.x,L[i].p1.y,L[i].p2.x,L[i].p2.y);
        extract(L[i].p1,L[i].p2,L[i].a,L[i].b,L[i].c);
    end;
end;

function    intersect(i,j:longint):boolean;
var
    t1,t2:double;
begin
    with L[i] do
        t1:=(L[j].a*p1.x+L[j].b*p1.y+L[j].c)*(L[j].a*p2.x+L[j].b*p2.y+L[j].c);
    with L[j] do
        t2:=(L[i].a*p1.x+L[i].b*p1.y+L[i].c)*(L[i].a*p2.x+L[i].b*p2.y+L[i].c);
    exit((t1 < Eps) and (t2 < Eps));
end;

procedure   solve;
var
    i,j:longint;
begin
    for i:=1 to N do
        for j:=i-1 downto 1 do
            if intersect(i,j) then begin
                writeln(fo,i);
                exit;
            end;
    writeln(fo,-1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.