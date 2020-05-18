const   oo = 1000000010;

var fi,fo:text;
    n,m,x,y,dx,dy,l,r,res:int64;
    i,k:longint;

function    min(x,y:int64):int64;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:int64):int64;   begin   if x > y then exit(x);  exit(y);    end;

procedure   update(ll,rr:int64);
begin
    l:=max(l,ll);
    r:=min(r,rr);
end;

begin
    assign(fi,'152B.in');   reset(fi);
    assign(fo,'152B.out');  rewrite(fo);
    res:=0;
    readln(fi,n,m);
    readln(fi,x,y);
    readln(fi,k);
    for i:=1 to k do begin
        readln(fi,dx,dy);
        l:=-oo; r:=oo;
        if dx > 0 then update((1-x) div dx, (n-x) div dx);
        if dx < 0 then update((n-x) div dx, (1-x) div dx);
        if dy > 0 then update((1-y) div dy, (m-y) div dy);
        if dy < 0 then update((m-y) div dy, (1-y) div dy);
        if (l <= r) and (r < oo) and (r > 0) then begin
            res:=res+r;
            x:=x+dx*r;
            y:=y+dy*r;
        end;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.