const
    INPUT = '105A.inp';
    OUTPUT = '105A.out';
    MAX_N = 20;
    MAX_M = 20;

procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N,M,K);
    for i:=1 to N do begin
        a[i]:='';
        repeat
            readln(fi,ch);
            if ch = ' ' then break;
            a[i]:=a[i]+ch;
        until false;
        readln(fi,level[i]);
    end;
    for i:=1 to M do begin
        readln(fi,a[N+i]);
        repeat
            j:=length(a[N+i]);
            if (a[N+i][j] >= 'a') and (a[N+i]][j] <= 'z') then break;
            delete(a[N+i],j,1);
        until false;
    end;
end;

procedure   solve;
begin

end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);

    close(fo);
    close(fi);
end.