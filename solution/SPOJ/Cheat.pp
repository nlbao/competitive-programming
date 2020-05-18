const
    INPUT = 'Cheat.inp';
    OUTPUT = 'Cheat.out';
    MAX_N = 100000;

var
    N:longint;
    C:string;
procedure   Enter;
var
    fi:text;
    i,j,k,pre:longint;
    avail:array[1..MAX_N] of boolean;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    C:='NO';
    pre:=0;
    for i:=1 to N do avail[i]:=true;
    for i:=1 to N do
        begin
            readln(fi,j);
            avail[j]:=false;
            if pre > j then
                for k:=j+1 to pre-1 do
                    if avail[k] then
                        begin
                            C:='YES';
                            exit;
                        end;
            pre:=j;
        end;
    close(fi);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,C);
    close(fo);
end;

begin
    Enter;
    Print_result;
end.
