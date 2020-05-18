const
    INPUT = '122D.inp';
    OUTPUT = '122D.out';
    MAX_N = 100010;
    MAX_M = 1000000010;

var
    fi,fo:text;
    N,M,top:longint;
    a:array[0..MAX_N] of char;
    stack:array[0..MAX_N] of longint;
    used:array[0..MAX_N] of boolean;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to N do read(fi,a[i]);
end;



procedure   solve;
var
    i,j,k,t,count:longint;
begin
    a[N+1]:='0';
    i:=1;
    while (i < N) and (M > 0) do begin
        while (i < N) and (a[i] <> '4') and (a[i] <> '7') do inc(i);
        if i = N then break;
        j:=i;
        while (a[j+1] = '4') or (a[j+1] = '7') do inc(j);
        {writeln(i,' ',j);}
        for k:=i to j do used[k]:=false;
        top:=0;
        k:=i;
        while k < j do begin
            if (a[k] = '4') and (a[k+1] = '7') then begin
                if (k mod 2) = 1 then a[k+1]:='4'
                else a[k]:='7';
                {writeln(k);}
                dec(M);
                if M <= 0 then break;
                inc(top);
                stack[top]:=k;
                if used[k] then begin
                    count:=0;
                    repeat
                        dec(top);
                        inc(count);
                    until stack[top] = k;
                    M:=M mod count;
                end;
                if a[k] = '7' then dec(k,2);
            end;
            {writeln('   ',k,' ',M);
            for t:=1 to N do write(a[t]);
            writeln;}
            if M <= 0 then break;
            inc(k);
        end;
        i:=j+1;
    end;
    for i:=1 to N do write(fo,a[i]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.