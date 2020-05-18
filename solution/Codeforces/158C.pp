const   MAX_N = 100010;

var fi,fo:text;
    n:longint;
    names:array[0..MAX_N] of ansiString;
    p:array[0..MAX_N] of longint;

function    take(var s:ansiString;  var j:longint):ansiString;
var t:ansiString;
begin
    t:='';
    while (j <= length(s)) and (s[j] <> '/') do begin
        t:=t+s[j];
        inc(j);
    end;
    inc(j);
    exit(t);
end;

function    add(var s:ansiString;   crr:longint):longint;
begin
    inc(n);
    names[n]:=s;
    p[n]:=crr;
    exit(n);
end;

function    find(var s:ansiString;  parent:longint):longint;
var i:longint;
begin
    i:=0;
    while (i <= n) and ((names[i] <> s) or (p[i] <> parent)) do inc(i);
    if i > n then add(s,parent);
    exit(i);
end;

procedure   print(i:longint);
var s:ansiString;
begin
    s:='/';
    while i > 0 do begin
        s:='/'+names[i]+s;
        i:=p[i];
    end;
    writeln(fo,s);
end;

procedure   solve;
var i,j,q,crr:longint;
    s,t:ansiString;
begin
    n:=0;   crr:=0;
    names[0]:='';
    fillchar(p,sizeof(p),0);

    readln(fi,q);
    for i:=1 to q do begin
        readln(fi,s);
        if s[1] = 'p' then print(crr)
        else begin
            j:=4;
            if s[4] = '/' then crr:=0
            else begin
                t:=take(s,j);
                if t = '..' then crr:=p[crr]
                else crr:=find(t,crr);
            end;

            while (j <= length(s)) do begin
                t:=take(s,j);
                if length(t) > 0 then
                    if t = '..' then crr:=p[crr]
                    else crr:=add(t,crr);
            end;
        end;
    end;
end;


begin
    assign(fi,'158C.in');   reset(fi);
    assign(fo,'158C.out');  rewrite(fo);
    solve;
    close(fo);
    close(fi);
end.
