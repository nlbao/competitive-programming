const
    INPUT = '';
    OUTPUT = '';
    MAX_N = 100010;

var
    fi,fo:text;
    N:longint;
    a,f:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,a[i]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,k,l,r,mid:longint;
begin
    k:=1;
    f[1]:=1;
    for i:=2 to N do begin
        if a[i] < a[f[k]] then begin
            inc(k);
            f[k]:=i;
        end
        else
            if a[i] >= a[f[1]] then
                f[1]:=i
            else begin
                l:=1;   r:=k;
                while l < r do begin
                    mid:=(l+r) shr 1;
                    if a[f[mid]] > a[i] then l:=mid+1
                    else r:=mid;
                end;
                mid:=(l+r) shr 1;
                f[mid]:=i;
            end;
    end;
    writeln(fo,k);
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