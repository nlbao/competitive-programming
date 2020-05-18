const
    INPUT = 'E.in';
    OUTPUT = 'E.out';
    MAX_N = 1010;

var
    fi,fo:text;
    N,count:longint;
    a:array[0..MAX_N] of string;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do readln(fi,a[i]);
end;

function    check:boolean;
var
    i,j,pre:longint;
begin
    i:=1;
    while (i <= N) and (a[i] = 'unknown') do inc(i);
    if i > N then exit(false);
    pre:=i;
    count:=1;
    while i < N do begin
        inc(i);
        if (a[i] <> 'unknown') and (a[i] <> a[pre]) then begin
            inc(count);
            for j:=pre-1 downto 1 do
                if a[j] = a[i] then exit(false);
            pre:=i;
        end;
    end;
    exit(true);
end;

function    solve:boolean;
var
    l,r,i,j,x:longint;
begin
    if (count = 0) or (N mod count <> 0) then exit(false);
    if count = 1 then begin
        writeln(fo,1);
        exit(true);
    end;
    x:=N div count;
    l:=1;   r:=x;
    while r <= N do begin
        i:=l;   j:=r;
        while (i <= r) and (a[i] = 'unknown') do inc(i);
        while (j >= l) and (a[j] = 'unknown') do dec(j);
        if (i > j) or (a[i] <> a[j]) then exit(false);
        l:=r+1; r:=r+x;
    end;
    write(fo,count);
    i:=x;
    while i <= N do begin
        write(fo,' ',i);
        i:=i+x;
    end;
    writeln(fo);
    exit(true);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    if (check = false) or (solve = false) then
        writeln(fo,'Igor is wrong.');
    close(fo);
    close(fi);
end.