const
    INPUT = 'Clock.inp';
    OUTPUT = 'Clock.out';

type
    arrClocks = array[1..3,1..3] of longint;

var
    fi,fo:text;
    a:arrClocks;
    next:array[0..3,1..3] of longint;
    res,count:longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
    ch:char;
begin
    for i:=1 to 3 do begin
        for j:=1 to 3 do begin
            read(fi,ch);
            a[i,j]:=ord(ch)-ord('0');
        end;
        readln(fi);
    end;
    for i:=0 to 2 do next[i,1]:=i+1;
    next[3,1]:=0;
    for i:=0 to 3 do
        for j:=2 to 3 do
            next[i,j]:=next[next[i,j-1],1];
end;
{---------------------------------------------------------------------------}
procedure   fix(types,c:longint);   inline;
begin
    if c = 0 then exit;
    case types of
        1: begin
            a[1,1]:=next[a[1,1],c]; a[1,2]:=next[a[1,2],c];
            a[2,1]:=next[a[2,1],c]; a[2,2]:=next[a[2,2],c];
        end;
        2: begin
            a[1,1]:=next[a[1,1],c]; a[1,2]:=next[a[1,2],c];
            a[1,3]:=next[a[1,3],c];
        end;
        3: begin
            a[1,2]:=next[a[1,2],c]; a[1,3]:=next[a[1,3],c];
            a[2,2]:=next[a[2,2],c]; a[2,3]:=next[a[2,3],c];
        end;
        4: begin
            a[1,1]:=next[a[1,1],c]; a[2,1]:=next[a[2,1],c];
            a[3,1]:=next[a[3,1],c];
        end;
        5: begin
            a[1,2]:=next[a[1,2],c]; a[2,1]:=next[a[2,1],c];
            a[2,2]:=next[a[2,2],c]; a[2,3]:=next[a[2,3],c];
            a[3,2]:=next[a[3,2],c];
        end;
        6: begin
            a[1,3]:=next[a[1,3],c]; a[2,3]:=next[a[2,3],c];
            a[3,3]:=next[a[3,3],c];
        end;
        7: begin
            a[2,1]:=next[a[2,1],c]; a[2,2]:=next[a[2,2],c];
            a[3,1]:=next[a[3,1],c]; a[3,2]:=next[a[3,2],c];
        end;
        8: begin
            a[3,1]:=next[a[3,1],c]; a[3,2]:=next[a[3,2],c];
            a[3,3]:=next[a[3,3],c];
        end;
        9: begin
            a[2,2]:=next[a[2,2],c]; a[2,3]:=next[a[2,3],c];
            a[3,2]:=next[a[3,2],c]; a[3,3]:=next[a[3,3],c];
        end;
    end;
end;
{---------------------------------------------------------------------------}
function    check:boolean;
var
    i,j:longint;
begin
    for i:=1 to 3 do
        for j:=1 to 3 do
            if a[i,j] <> 0 then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   tryf(i:longint);
var
    j:longint;
    tmp:arrClocks;
begin
    if i > 9 then begin
        if (check = true) and (count < res) then res:=count;
        exit;
    end;
    for j:=0 to 3 do begin
        inc(count,j);
        tmp:=a;
        fix(i,j);
        if count < res then tryf(i+1);
        a:=tmp;
        dec(count,j);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
begin
    count:=0;
    res:=MAXLONGINT;
    tryf(1);
    if res = MAXLONGINT then res:=-1;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
