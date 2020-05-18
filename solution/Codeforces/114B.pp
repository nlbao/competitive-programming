const
    INPUT = '114B.inp';
    OUTPUT = '114B.out';
    MAX_N = 16;

var
    fi,fo:text;
    N,M,nC,nRes:longint;
    vname:array[0..MAX_N] of string;
    a:array[0..MAX_N,0..MAX_N] of boolean;
    c,res:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j,k:longint;
    s,u,v:string;
begin
    readln(fi,N,M);
    for i:=1 to N do
        readln(fi,vname[i]);
    for i:=1 to N do
        for j:=1 to N do
            a[i,j]:=true;

    for i:=1 to M do begin
        readln(fi,s);
        j:=1;
        while s[j+1] <> ' ' do inc(j);
        u:=copy(s,1,j); v:=copy(s,j+2,length(s)-j-1);
        j:=1;   k:=1;
        while vname[j] <> u do inc(j);
        while vname[k] <> v do inc(k);
        a[j,k]:=false; a[k,j]:=false;
    end;
end;
{---------------------------------------------------------------------------}
function    check(x:longint):boolean;
var
    i,j:longint;
begin
    nC:=0;
    for i:=1 to N do
        if ((x shr (i-1)) and 1) = 1 then begin
            inc(nC);
            c[nC]:=i;
        end;
    for i:=1 to nC-1 do
        for j:=i+1 to nC do
            if a[c[i],c[j]] = false then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,p2:longint;
begin
    nRes:=0;
    p2:=1;
    for i:=1 to N do p2:=p2*2;
    for i:=1 to p2-1 do
        if (check(i) = true) and (nC > nRes) then begin
            nRes:=nC;
            for j:=1 to nRes do res[j]:=c[j];
        end;
end;
{---------------------------------------------------------------------------}
procedure   sort;
var
    i,j:longint;
    tmp:string;
begin
    for i:=1 to nRes-1 do
        for j:=i+1 to nRes do
            if vname[res[i]] > vname[res[j]] then begin
                tmp:=vname[res[i]];
                vname[res[i]]:=vname[res[j]];
                vname[res[j]]:=tmp;
            end;
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i:longint;
begin
    writeln(fo,nRes);
    for i:=1 to nRes do
        writeln(fo,vname[res[i]]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    sort;
    print_result;
    close(fo);
    close(fi);
end.