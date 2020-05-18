const
    INPUT = 'LEM4.inp';
    OUTPUT = 'LEM4.out';
    MAX_N = 10000;
    MAX_M = 100000;
    MAX_F = 8*MAX_N;
    WHITE = 0;  BLACK = 1;

var
    fi,fo:text;
    N,M,first,last,newColor:longint;
    F:array[1..MAX_F,0..2] of longint;
    color:array[1..MAX_F] of longint;
    updated:array[1..MAX_F] of boolean;

{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j:longint;
begin
    for i:=1 to 4*N do begin
        for j:=0 to 2 do F[i,j]:=0;
        color[i]:=BLACK;
        updated[i]:=true;
    end;
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   subUpdateF(k,l,r,c:longint);
begin
    color[k]:=c;    updated[k]:=true;
    if c = WHITE then begin
        F[k,0]:=r-l+1;
        F[k,1]:=F[k,0];
        F[k,2]:=F[k,0];
    end
    else begin
        F[k,0]:=0;
        F[k,1]:=0;
        F[k,2]:=0;
    end;
    color[k shl 1]:=c;  color[(k shl 1)+1]:=c;
    updated[k shl 1]:=false;    updated[(k shl 1)+1]:=false;
end;
{---------------------------------------------------------------------------}
procedure   UpdateF(k,l,r:longint);
var
    mid:longint;
begin
    if l > r then exit;
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        subUpdateF(k,l,r,newColor);
        exit;
    end;
    mid:=(l+r) shr 1;
    if not updated[k shl 1] then
        subUpdateF(k shl 1,l,mid,color[k shl 1]);
    if not updated[(k shl 1)+1] then
        subUpdateF((k shl 1)+1,mid+1,r,color[(k shl 1)+1]);

    UpdateF(k shl 1,l,mid);
    UpdateF((k shl 1)+1,mid+1,r);

    F[k,0]:=max(max(F[k shl 1,0],F[(k shl 1)+1,0]),F[k shl 1,2]+F[(k shl 1)+1,1]);
    F[k,1]:=F[k shl 1,1];
    if F[k,1] = mid-l+1 then
        F[k,1]:=F[k,1]+F[(k shl 1)+1,1];
    F[k,2]:=F[(k shl 1)+1,2];
    if F[k,2] = r-mid then
        F[k,2]:=F[k,2]+F[k shl 1,2];
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,types:longint;
begin
    first:=1;   last:=N;
    newColor:=WHITE;
    UpdateF(1,1,N);
    for i:=1 to M do begin
        read(fi,types);
        if types < 3 then begin
            readln(fi,first,last);
            newColor:=types-1;
            UpdateF(1,1,N);
        end
        else
            writeln(fo,F[1,0]);
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,N); read(fi,M);
    Init;
    Solve;
    close(fo);
    close(fi);
end.