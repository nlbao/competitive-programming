

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    x1:=-1;
    for i:=1 to n do begin
        for j:=1 to m do begin
            read(fi,a[i][j]);
            if a[i][j] = 'L' then
                if x1 = -1 then begin   x1:=i;  y1:=j   end
                else begin x2:=i;   y2:=j;  end;
        end;
        readln(fi);
    end;
end;

procedure   solve;
begin

end;

begin
    assign(fi,'labudovi.in');   reset(fi);
    assign(fo,'labudovi.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.