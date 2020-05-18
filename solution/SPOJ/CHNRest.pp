const
    INPUT = 'CHNRest.inp';
    OUTPUT = 'CHNRest.out';
    MAX_N = 10;
    MAX_M = 30;
    MAX_nF = 33000;
    MAX_INT = MAXLONGINT;

type
    recF = record
        c,v:longint;
    end;

var
    fi,fo:text;
    p2,p3:array[0..MAX_M] of longint;
    M,N:longint;
    nF:array[1..2] of longint;
    f:array[1..2,0..MAX_nF] of recF;
    value:array[0..MAX_M] of longint;
    favorite:array[0..MAX_N,0..MAX_M] of boolean;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M,N);
    for i:=1 to M do read(fi,value[i]);
    for i:=1 to N do
        for j:=1 to M do favorite[i][j]:=false;
    readln(fi);
    for i:=1 to N do begin
        while not eoln(fi) do begin
            read(fi,j);
            favorite[i,j]:=true;
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    get_bit(x,i:longint):longint;   inline;
begin
    exit(1 and (x shr (i-1)));
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    p2[0]:=1;
    for i:=1 to MAX_M do p2[i]:=p2[i-1]*2;
    p3[0]:=1;
    for i:=1 to MAX_N do p3[i]:=p3[i-1]*3;
end;
{---------------------------------------------------------------------------}
procedure   phan_tap;
var
    nM1,nM2,sumV:longint;
    x,i,j,k:longint;
    count:array[0..MAX_N] of longint;
    {---------------------------------------------------------------------------}
    function    check:boolean;
    var
        i:longint;
    begin
        for i:=1 to N do
            if count[i] > 2 then exit(false);
        exit(true);
    end;
    {---------------------------------------------------------------------------}
    procedure   newF(id:longint);
    var
        i:longint;
    begin
        inc(nF[id]);
        f[id][nF[id]].c:=0;
        for i:=1 to N do
            inc(f[id][nF[id]].c,count[i]*p3[i-1]);
        f[id][nF[id]].v:=sumV;
    end;
    {---------------------------------------------------------------------------}
begin
//f[1]
    nM1:=M shr 1;   nF[1]:=0;
    for x:=1 to p2[nM1]-1 do begin
        for i:=1 to N do count[i]:=0;
        sumV:=0;
        for i:=1 to nM1 do
            if get_bit(x,i) = 1 then begin
                for k:=1 to N do
                    if favorite[k,i] then inc(count[k]);
                inc(sumV,value[i]);
            end;
        if check = true then newF(1);
    end;
//f[2]
    nM2:=M-nM1;   nF[2]:=0;
    for x:=1 to p2[nM2]-1 do begin
        for i:=1 to N do count[i]:=0;
        sumV:=0;
        for i:=1 to nM2 do
            if get_bit(x,i) = 1 then begin
                j:=i+nM1;
                for k:=1 to N do
                    if favorite[k,j] then inc(count[k]);
                inc(sumV,value[j]);
            end;
        if check = true then newF(2);
    end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p:longint;
    tmp:recF;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=f[2][(i+j) shr 1].c;
    repeat
        while f[2][i].c < p do inc(i);
        while f[2][j].c > p do dec(j);
        if i <= j then begin
            tmp:=f[2][i];
            f[2][i]:=f[2][j];
            f[2][j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   update;
var
    i,j,k,minV:longint;
begin
    f[2][nF[2]+1].c:=-1;
    i:=1;
    repeat
        j:=i;
        minV:=f[2][i].v;
        while f[2][j+1].c = f[2][i].c do begin
            inc(j);
            minV:=min(minV,f[2][j].v);
        end;
        for k:=i to j do f[2][k].v:=minV;
        i:=j+1;
    until i > N;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,l,r,mid:longint;
    sum,tmp,res:longint;
begin
    sum:=0;
    for i:=1 to N do sum:=sum+2*p3[i-1];
    res:=MAX_INT;
    for i:=1 to nF[1] do begin
        tmp:=sum-f[1][i].c;
        if tmp = 0 then res:=min(res,f[1][i].v);
        l:=1;   r:=nF[2];
        while l <= r do begin
            mid:=(l+r) shr 1;
            if f[2][mid].c = tmp then begin
                res:=min(res,f[1][i].v+f[2][mid].v);
                break;
            end
            else
                if f[2][mid].c < tmp then l:=mid+1
                else r:=mid-1;
        end;
    end;
    if res = MAX_INT then res:=-1;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    phan_tap;
    {randomize;}
    quick_sort(1,nF[2]);
    update;
    solve;
    close(fo);
    close(fi);
end.