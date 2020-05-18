const   MAX_N = 100010;

var fi,fo:text;
    s,t:ansiString;
    n,i,j,rp,rf,r0:longint;
    c,c2:array[0..9] of longint;


function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   update(x,y:longint);
begin
    s:=chr(x+ord('0'))+s;   dec(c[x]);
    t:=chr(y+ord('0'))+t;   dec(c2[y]);
end;

procedure   solve(x,y,z:longint);
var i,f:longint;
begin
    if (c[x] < 1) or (c2[y] < 1) then exit;
    dec(c[x]);  dec(c2[y]);
    dec(c[0],z);    dec(c2[0],z);
    f:=z;
    for i:=0 to 9 do f:=f+min(c[i],c2[9-i]);
    f:=f+min(c[0]-min(c[0],c2[9]),c2[0]-min(c2[0],c[9]));
    if f > rf then begin
        rf:=f;
        rp:=x;
        r0:=z;
    end;
    inc(c[0],z);    inc(c2[0],z);
    inc(c[x]);  inc(c2[y]);
end;

begin
    assign(fi,'139D.in');   reset(fi);
    assign(fo,'139D.out');  rewrite(fo);
    readln(fi,s);
    n:=length(s);
    for i:=0 to 9 do c[i]:=0;
    for i:=1 to n do inc(c[ord(s[i])-ord('0')]);
    c2:=c;
    rf:=0; rp:=-1; r0:=0;
    for j:=0 to c[0] do
        for i:=1 to 5 do
            solve(i,10-i,j);
    s:='';  t:='';
    for i:=1 to r0 do update(0,0);
    if rp > 0 then begin
        update(rp,10-rp);
        for i:=0 to 9 do
            while (c[i] > 0) and (c2[9-i] > 0) do update(i,9-i);
    end;
    while (c[0] > 0) and (c2[0] > 0) do begin
        s:=s+'0'; dec(c[0]);
        t:=t+'0'; dec(c2[0]);
    end;
    for i:=1 to 9 do
        while (c[i] > 0) and (c2[10-i] > 0) do update(i,10-i);
    for i:=0 to 9 do begin
        while c[i] > 0 do begin s:=chr(i+ord('0'))+s;   dec(c[i]);  end;
        while c2[i] > 0 do begin t:=chr(i+ord('0'))+t;   dec(c2[i]);  end;
    end;
    writeln(fo,s);
    writeln(fo,t);
    close(fo);
    close(fi);
end.
