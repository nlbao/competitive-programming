const
    INPUT = 'VMDomino.inp';
    OUTPUT = 'VMDomino.out';
    MAX_M = 10001;
    MAX_N = 2000;

var
    fi,fo:text;
    M,N,Modulo:longint;
    f:array[0..MAX_M,0..MAX_N] of longint;
    avail:array[0..MAX_M,0..MAX_N] of boolean;

{---------------------------------------------------------------------------}
function    get_bit(x,i:longint):longint;   inline;
begin
    if (i < 1) or (i > N) then exit(-1)
    else exit((x shr (i-1)) and 1);
end;
{---------------------------------------------------------------------------}
function    check1(row,x1,x2:longint):boolean;
var
    i,j,k:longint;
begin
    for i:=1 to N do begin
        j:=get_bit(x1,i);
        if avail[row,i] then
        if (row+i) mod 2 = 1 then begin
            k:=get_bit(x1,i-1);
            if (j < k) and (k > -1) and (avail[row,i-1]) then exit(false);
            k:=get_bit(x1,i+1);
            if (j < k) and (k > -1) and (avail[row,i+1]) then exit(false);
            if (x2 <> -1) and (avail[row-1,i]) then begin
                k:=get_bit(x2,i);
                if (j < k) and (k > -1) then exit(false);
            end;
        end
        else begin
            k:=get_bit(x1,i-1);
            if (j > k) and (k > -1) and (avail[row,i-1]) then exit(false);
            k:=get_bit(x1,i+1);
            if (j > k) and (k > -1) and (avail[row,i+1]) then exit(false);
            if (x2 <> -1) and (avail[row-1,i]) then begin
                k:=get_bit(x2,i);
                if (j > k) and (k > -1) then exit(false);
            end;
        end;
    end;
    exit(true);
end;
{---------------------------------------------------------------------------}

procedure   solve1;
var
    i,j,k,u,v,p,res:longint;
begin
    read(fi,M,N);
    for i:=0 to M+1 do
        for j:=0 to N+1 do
            avail[i,j]:=true;
    read(fi,j);
    for i:=1 to j do begin
        read(fi,u,v);
        avail[u,v]:=false;
    end;
    p:=1;
    for i:=1 to N do p:=p*2;
    dec(p);
    for i:=0 to p do
        if check1(1,i,-1) = true then f[1,i]:=1
        else f[1,i]:=0;
    for i:=2 to M do
        for j:=0 to p do begin
            f[i,j]:=0;
            if check1(i,j,-1) = true then
                for k:=0 to p do
                    if check1(i,j,k) = true then
                        f[i,j]:=(f[i,j]+f[i-1,k]) mod Modulo;
        end;
    res:=0;
    for i:=0 to p do
        res:=(res+f[M,i]) mod Modulo;
    res:=res div 2;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}
function    check2(row,x1,x2:longint):boolean;
var
    i,j,k:longint;
begin
    for i:=1 to N do begin
        j:=get_bit(x1,i);
        if (row+i) mod 2 = 1 then begin
            k:=get_bit(x1,i-1);
            if (j < k) and (k > -1) then exit(false);
            k:=get_bit(x1,i+1);
            if (j < k) and (k > -1) then exit(false);
            if (x2 <> -1) then begin
                k:=get_bit(x2,i);
                if (j < k) and (k > -1) then exit(false);
            end;
        end
        else begin
            k:=get_bit(x1,i-1);
            if (j > k) and (k > -1) then exit(false);
            k:=get_bit(x1,i+1);
            if (j > k) and (k > -1) then exit(false);
            if (x2 <> -1) then begin
                k:=get_bit(x2,i);
                if (j > k) and (k > -1) then exit(false);
            end;
        end;
    end;
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   solve2;
var
    i,j,k,p,res:longint;
begin
    readln(fi,N,M);
    p:=1;
    for i:=1 to N do p:=p*2;
    dec(p);
    for i:=0 to p do
        if check2(1,i,-1) = true then f[1,i]:=1
        else f[1,i]:=0;
    for i:=2 to M do
        for j:=0 to p do begin
            f[i,j]:=0;
            if check2(i,j,-1) = true then
                for k:=0 to p do
                    if check2(i,j,k) = true then
                        f[i,j]:=(f[i,j]+f[i-1,k]) mod Modulo;
        end;
    res:=0;
    for i:=0 to p do
        res:=(res+f[M,i]) mod Modulo;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,Modulo);
    solve1;
    solve2;
    close(fo);
    close(fi);
end.