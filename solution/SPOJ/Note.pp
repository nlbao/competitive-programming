const
    INPUT = 'Note.inp';
    OUTPUT = 'Note.out';
    MAX_N = 31;

type
    pR = ^recR;
    recR = record
        up:boolean;
        next:pR;
    end;

var
    fi,fo:text;
    F,P:longint;
    Res:char;


procedure   Find;
var
    first,R,preR:pR;
    S,i,count:longint;
    turn:boolean;
begin
    new(first);
    first^.up:=false;
    first^.next:=nil;
    S:=1;
    for count:=2 to F do
        begin
            new(R);
            R^.up:=true;
            R^.next:=first;
            preR:=first;
            first:=R;
            i:=1;
            turn:=true;     //up
            while i < S+1 do
                begin
                    inc(i);
                    new(R);
                    turn:=not turn;
                    R^.up:=turn;
                    R^.next:=preR^.next;
                    preR^.next:=R;
                    preR:=R^.next;
                end;
            S:=S+S+1;
        end;
    R:=first;
    for i:=2 to P do
        R:=R^.next;
    if R^.up = true then Res:='U'
    else Res:='D';
    R:=first;
    while R <> nil do
        begin
            preR:=R;
            R:=R^.next;
            dispose(preR);
        end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    while not eof(fi) do
        begin
            readln(fi,F,P);
            if F = 0 then break
            else
                begin
                    Find;
                    writeln(fo,Res);
                end;
        end;
    close(fo);
    close(fi);
end.