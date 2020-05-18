const   MAX_N = 100010;

type    pList = ^recList;
        recList = record
            x:longint;
            link:pList;
        end;

var fi,fo:text;
    n,m:longint;
    is_prime,off:array[0..MAX_N] of boolean;
    c:array[0..MAX_N] of longint;
    list:array[0..MAX_N] of pList;

procedure   add_list(i,j:longint);
var p:pList;
begin
    new(p);
    with p^ do begin
        x:=j;
        link:=list[i];
    end;
    list[i]:=p;
end;

procedure   init;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do begin
        is_prime[i]:=true;
        list[i]:=nil;
        c[i]:=-1;
    end;
    for i:=2 to n do
        if is_prime[i] then begin
            add_list(i,i);
            j:=i+i;
            while (j <= n) do begin
                is_prime[j]:=false;
                add_list(j,i);
                j:=j+i;
            end;
        end;
end;

function    check(u:longint;    var j:longint):boolean;
var i:longint;
    p:pList;
begin
    p:=list[u];
    while p <> nil do with p^ do begin
        if c[x] > 0 then begin
            j:=c[x];
            exit(false);
        end;
        p:=link;
    end;
    exit(true);
end;

procedure   add(u,d:longint);
var i:longint;
    p:pList;
begin
    off[u]:=(d < 0);
    p:=list[u];
    while p <> nil do with p^ do begin
        c[x]:=u*d;
        p:=link;
    end;
end;

procedure   solve;
var i,j,u:longint;
    ch:char;
begin
    for i:=1 to n do off[i]:=true;
    for i:=1 to m do begin
        read(fi,ch);
        readln(fi,u);
        if ch = '+' then begin
            if not off[u] then writeln(fo,'Already on')
            else if check(u,j) = true then begin
                add(u,1);
                writeln(fo,'Success');
            end
            else writeln(fo,'Conflict with ',j);
        end
        else
            if off[u] then writeln(fo,'Already off')
            else begin
                add(u,-1);
                writeln(fo,'Success');
            end;
    end;
end;

begin
    assign(fi,'155D.in');   reset(fi);
    assign(fo,'155D.out');  rewrite(fo);
    init;
    solve;
    close(fo);
    close(fi);
end.