const
    INPUT = 'MaKhoa3.inp';
    OUTPUT = 'MaKhoa3.out';
    MAX_M = 35;
    MAX_N = 35;

var
    fi,fo:text;
    M,N:longint;
    A,B,W:array[0..MAX_M,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
{read A}
    for i:=1 to M do begin
        read(fi,A[i,0]);
        for j:=1 to A[i,0] do
            read(fi,A[i,j]);
        readln(fi);
    end;
{read B}
    for i:=1 to N do begin
        read(fi,B[i,0]);
        for j:=1 to B[i,0] do
            read(fi,B[i,j]);
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
function    check_row(i:longint):boolean;
var
    current,left,right:longint;
begin
    current:=1;
    left:=1;
    W[i,N+1]:=-1;
    repeat
        while W[i,left] = 0 do inc(left);
        if left > N then
            if current <= A[i,0] then exit(false)
            else exit(true);
        if current > A[i,0] then exit(false);
        right:=left;
        while W[i,right+1] = 1 do inc(right);
        if right-left+1 <> A[i,current] then exit(false);
        inc(current);
        left:=right+1;
    until false;
end;
{---------------------------------------------------------------------------}
function    check_column(i:longint):boolean;
var
    current,top,bottom:longint;
begin
    current:=1;
    top:=1;
    W[M+1,i]:=-1;
    repeat
        while W[top,i] = 0 do inc(top);
        if top > M then
            if current <= B[i,0] then exit(false)
            else exit(true);
        if current > B[i,0] then exit(false);
        bottom:=top;
        while W[bottom+1,i] = 1 do inc(bottom);
        if bottom-top+1 <> B[i,current] then exit(false);
        inc(current);
        top:=bottom+1;
    until false;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    nTest,i,j:longint;
    s:string;
    res:boolean;
begin
    readln(fi,nTest);
    repeat
        res:=true;
{read W}
        for i:=1 to M do begin
            s:='';
            while (length(s) = 0) or ((s[1] <> '0') and (s[1] <> '1')) do readln(fi,s);
            for j:=1 to N do
                W[i,j]:=ord(s[j])-ord('0');
        end;
{check row}
        for i:=1 to M do begin
            res:=res and check_row(i);
            if res = false then break;
        end;
{check column}
        if res = true then
            for i:=1 to N do begin
                res:=res and check_column(i);
                if res = false then break;
            end;
{print_result}
        if res = true then writeln(fo,'YES')
        else writeln(fo,'NO');
        dec(nTest);
    until nTest = 0;
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
