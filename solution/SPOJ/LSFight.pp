const
    INPUT = 'LSFight.inp';
    OUTPUT = 'LSFight.out';
    MAX_N = 501;

var
    fi,fo:text;
    N:longint;
    a:array[0..MAX_N,0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_N] of boolean;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N);
    for i:=0 to N-1 do
        for j:=0 to N-1 do
            read(fi,a[i,j]);
end;
{---------------------------------------------------------------------------}
procedure   tinh_f;
var
    i,j,k,t:longint;
begin
    for i:=0 to N-1 do begin
        f[i,i]:=true;
        f[i,(i+1) mod N]:=true;
    end;

    for t:=2 to N-1 do
        for i:=0 to N-1 do begin
            j:=(i+t) mod N;
            f[i,j]:=false;
            k:=(i+1) mod N;
            repeat
                if (f[i,k] = true) and (f[k,j] = true) and ((a[i,k] = 1) or (a[j,k] = 1)) then begin
                    f[i,j]:=true;
                    break;
                end;
                k:=(k+1) mod N;
            until k = j;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,pre_i,nRes:longint;
    res:array[0..MAX_N] of boolean;
begin
    if N = 1 then begin
        writeln(fo,1);
        writeln(fo,1);
        exit;
    end;
    tinh_f;
    nRes:=0;
    for i:=0 to N-1 do res[i]:=false;
    for i:=0 to N-1 do begin
        pre_i:=(i-1+N) mod N;
        for j:=0 to N-1 do
            if (a[j,i] = 0) and (a[j,pre_i] = 1) and (f[i,j] = true) and (f[j,pre_i] = true) then begin
                inc(nRes);
                res[i]:=true;
                break;
            end;
    end;

    writeln(fo,nRes);
    for i:=0 to N-1 do
        if res[i] = true then writeln(fo,i+1);
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