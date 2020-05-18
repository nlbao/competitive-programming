const
    INPUT = '106A.inp';
    OUTPUT = '106A.out';

var
    fi,fo:text;
    trump:char;
    x,y:string;

procedure   enter;
var
    s:string;
begin
    readln(fi,s);
    trump:=s[1];
    readln(fi,s);
    x:=s[1]+s[2];
    y:=s[4]+s[5];
end;

function    rank(x:string):longint;
begin
    case x[1] of
        '6','7','8','9': exit(ord(x[1])-53);
        'T': exit(5);
        'J': exit(6);
        'Q': exit(7);
        'K': exit(8);
        'A': exit(9);
    end;
end;

procedure   solve;
var
    res:string;
begin
    if (x[2] = trump) and (y[2] <> trump) then res:='YES'
    else
        if (x[2] = y[2]) and (rank(x) > rank(y)) then res:='YES'
        else res:='NO';
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.