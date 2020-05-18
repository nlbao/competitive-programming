const   INPUT = 'Power.in';
        OUTPUT = 'Power.out';
        MAX_R = 1000000000010;

function    log(a,x:double):double; begin   exit(ln(x)/ln(a));  end;

function    solve(x,y:double):int64;
begin
    for k:=1 to 40 do begin
        l:=1;   r:=
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        readln(fi,l,r);
        writeln(fo,'Case #',i,': ',solve(l,r));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.