var fi,fo:text;
    i:longint;
    ch:char;
    a:array[0..3] of longint;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

begin
    assign(fi,'abc.in');     reset(fi);
    assign(fo,'abc.out');    rewrite(fo);
    readln(fi,a[1],a[2],a[3]);
    if (a[1] > a[2]) then swap(a[1],a[2]);
    if (a[1] > a[3]) then swap(a[1],a[3]);
    if (a[2] > a[3]) then swap(a[2],a[3]);
    for i:=1 to 3 do begin
        read(fi,ch);
        writeln(ch);
        write(fo,a[ord(ch)-ord('A')+1],' ');
    end;
    close(fo);
    close(fi);
end.
