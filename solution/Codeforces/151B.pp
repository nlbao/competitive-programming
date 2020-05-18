const   MAX_N = 110;

var fi,fo:text;
    n:longint;
    names:array[0..MAX_N] of ansiString;
    c:array[0..MAX_N,0..2] of longint;
    maxC:array[0..2] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

function    is_taxi(s:ansiString):boolean;
var i:longint;
begin
    for i:=1 to 5 do
        if s[i] <> s[i+1] then exit(false);
    exit(true);
end;

function    is_pizza(s:ansiString):boolean;
var i:longint;
begin
    for i:=1 to 5 do
        if s[i] <= s[i+1] then exit(false);
    exit(true);
end;

procedure   enter;
var i,j,m:longint;
    s:ansiString;
begin
    for j:=0 to 2 do maxC[j]:=-1;
    fillchar(c,sizeof(c),0);
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,m,names[i]);
        delete(names[i],1,1);
        for j:=1 to m do begin
            readln(fi,s);
            delete(s,3,1);
            delete(s,5,1);
            if is_taxi(s) then inc(c[i][0])
            else if is_pizza(s) then inc(c[i][1])
            else inc(c[i][2]);
        end;
        for j:=0 to 2 do maxC[j]:=max(maxC[j],c[i][j]);
    end;
end;

procedure   solve;
var i:longint;
    s:ansiString;
begin
    s:='If you want to call a taxi, you should call:';
    for i:=1 to n do
        if c[i][0] = maxC[0] then s:=s+' '+names[i]+',';
    delete(s,length(s),1);
    s:=s+'.';
    writeln(fo,s);

    s:='If you want to order a pizza, you should call:';
    for i:=1 to n do
        if c[i][1] = maxC[1] then s:=s+' '+names[i]+',';
    delete(s,length(s),1);
    s:=s+'.';
    writeln(fo,s);

    s:='If you want to go to a cafe with a wonderful girl, you should call:';
    for i:=1 to n do
        if c[i][2] = maxC[2] then s:=s+' '+names[i]+',';
    delete(s,length(s),1);
    s:=s+'.';
    writeln(fo,s);
end;

begin
    assign(fi,'');   reset(fi);
    assign(fo,'');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.