const
    INPUT = '108A.inp';
    OUTPUT = '108A.out';

var
    fi,fo:text;
    h,m:longint;

procedure   enter;
var
    s:string;
    err:longint;
begin
    read(fi,s);
    val(copy(s,1,2),h,err);
    val(copy(s,4,2),m,err);
end;

procedure   solve;
var
    i,j:longint;
begin
    if (h = 23) and (m >= 32) then begin
        h:=0;
        m:=0;
    end
    else
        for i:=1 to 23 do begin
            j:=10*(i mod 10)+(i div 10);
            if (j < 60) and (((i = h) and (j > m)) or (i > h)) then begin
                h:=i;   m:=j;
                break;
            end;
        end;
    writeln(fo,h div 10,h mod 10,':',m div 10,m mod 10);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
