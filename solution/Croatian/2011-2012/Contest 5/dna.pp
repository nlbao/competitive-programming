const   MAX_N = 1000010;

var fi,fo:text;
    n,i,j,c,res:longint;
    a:array[0..MAX_N] of char;
    s:array[0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    isB(i:longint):boolean;
begin
    if (c mod 2 = 0) and (a[i] = 'B') then exit(true);
    if (c mod 2 = 1) and (a[i] = 'A') then exit(true);
    exit(false);
end;

begin
    assign(fi,'dna.in');    reset(fi);
    assign(fo,'dna.out');   rewrite(fo);
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,ch);
        if ch = 'A' then a[i]:=0
        else a[i]:=1;
    end;
    f[0][0]:=0; f[0][1]:=0;
    t:=0;
    for i:=n downto 1 do begin
        tt:=t;
        t:=(t+1) mod 2;
        for j:=0 to 1 do begin
            jj:=(j+1) mod 2;

        end;

    end;



    close(fo);
    close(fi);
end.
