const   INPUT = '136D.in';
        OUTPUT = '136D.out';
        N = 8;

type    recPoint = record
            x,y:longint;
        end;
        arrS = array[0..4] of longint;

var fi,fo:text;
    p:array[0..8] of recPoint;
    id:array[0..8] of longint;
    avail:array[0..8] of boolean;
    s1,s2:arrS;
    res:string;

procedure   enter;
var i:longint;
begin
    for i:=1 to 8 do
        readln(fi,p[i].x,p[i].y);
end;

function    d(p1,p2:recPoint):longint;
begin
    exit(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
end;

function    d90(i,j,k:longint):boolean;
begin
    if d(p[i],p[j])+d(p[j],p[k]) <> d(p[i],p[k]) then exit(false);
    exit(true);
end;

function    is_rectangle(s:arrS):boolean;
begin
    if (not d90(s[1],s[2],s[3])) or (not d90(s[2],s[3],s[4])) or (not d90(s[3],s[4],s[1]))
or (not d90(s[4],s[1],s[2])) then exit(false);
    exit(true);
end;

function    is_square(s:arrS):boolean;
begin
    if not is_rectangle(s) then exit(false);
    if d(p[s[1]],p[s[2]]) <> d(p[s[2]],p[s[3]]) then exit(false);
    exit(true);
end;

function    check:boolean;
var i:longint;
begin
    for i:=1 to 8 do
        if id[i] < 5 then s1[id[i]]:=i
        else s2[id[i]-4]:=i;
    if not is_rectangle(s2) then exit(false);
    exit(is_square(s1));
end;

procedure   tryf(i:longint);
var j:longint;
begin
    if res = 'YES' then exit;
    if i > 8 then begin
        if check = true then res:='YES';
        exit;
    end;
    for j:=1 to 8 do
        if avail[j] then begin
            id[i]:=j;
            avail[j]:=false;
            tryf(i+1);
            avail[j]:=true;
            id[i]:=0;
        end;
end;

procedure   solve;
var i:longint;
begin
    res:='NO';
    for i:=1 to 8 do avail[i]:=true;
    tryf(1);
    writeln(fo,res);
    if res = 'NO' then exit;
    for i:=1 to 4 do write(fo,s1[i],' ');
    writeln(fo);
    for i:=1 to 4 do write(fo,s2[i],' ');
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.