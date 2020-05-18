const   INPUT = ''{'pogodak.in'};
        OUTPUT = ''{'pogodak.out'};
        MAX_R = 100010;
        MAX_C = 100010;

type    int = int64;

var fi,fo:text;
    r,c,p1,p2,p3,p4,p5,p6,t,res:int;
    i,j:longint;

procedure   roll_right;
begin   t:=p1;  p1:=p4; p4:=p3; p3:=p2; p2:=t;  end;

procedure   roll_left;
begin   t:=p1;  p1:=p2; p2:=p3; p3:=p4; p4:=t;  end;

procedure   roll_down;
begin   t:=p1;  p1:=p6; p6:=p3; p3:=p5; p5:=t;  end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,r,c);
    res:=0;
    p1:=1;  p2:=3;  p3:=6;  p4:=4;  p5:=2;  p6:=5;
    for i:=1 to r do begin
        if (i mod 2) = 1 then roll_left
        else roll_right;
        res:=res+(p1+p2+p3+p4)*(c div 4);
        for j:=1 to (c mod 4) do begin
            if (i mod 2) = 1 then roll_right
            else roll_left;
            res:=res+p1;
        end;
        if i < r then roll_down;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.