uses    math;

const   MAX_N = 100010;
        MAX_F = 4*MAX_N;
        MODULE = 1000000007;

type    ll = int64;

var fi,fo:text;
    n,m,value:longint;
    a:array[0..MAX_N] of longint;
    c:array[0..MAX_F] of longint;
    f:array[0..MAX_F,0..6] of longint;
    delete:boolean;


procedure   init(k,l,r:longint);
var mid,left,right,j,i:longint;
begin
    if l > r then exit;
    for j:=0 to 6 do f[k][j]:=1;
    if l = r then begin
        f[k][1]:=a[l];
        c[k]:=1;
        exit;
    end;

    mid:=(l+r) shr 1;
    left:=k shl 1;
    right:=(k shl 1)+1;
    init(left,l,mid);
    init(right,mid+1,r);

    c[k]:=c[left]+c[right];
    for i:=0 to 6 do begin
        j:=(i+c[left]) mod 7;
        f[k][j]:=(int64(f[left][j])*int64(f[right][i])) mod MODULE;
    end;

end;


procedure   update(k,l,r,i:longint);
var mid,left,right,j:longint;
begin
    if l > r then exit;
    if l = r then begin
        for j:=0 to 6 do f[k][j]:=1;
        f[k][1]:=value;
        c[k]:=longint(delete = false);
        exit;
    end;

    mid:=(l+r) shr 1;
    left:=k shl 1;
    right:=(k shl 1)+1;
    if c[left] >= i then update(left,l,mid,i)
    else update(right,mid+1,r,i-c[left]);


    c[k]:=c[left]+c[right];
    for i:=0 to 6 do begin
        j:=(i+c[left]) mod 7;
        f[k][j]:=(int64(f[left][j])*int64(f[right][i])) mod MODULE;
    end;
end;


procedure   enter();
var i:longint;
begin
    read(fi,n,m);
    for i:=1 to n do read(fi,a[i]);
    init(1,1,n);
end;


procedure   solve();
var i,types,j,v:longint;
begin
    for i:=1 to m do begin
        read(fi,types);
        if types = 1 then begin
            read(fi,j);
            inc(j);
            value:=1;
            delete:=true;
            update(1,1,n,j);
        end
        else if types = 2 then begin
            read(fi,j,value);
            inc(j);
            delete:=false;
            update(1,1,n,j);
        end
        else begin
            read(fi,j);
            writeln(fo,f[1][(j+1) mod 7]);
        end;
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'C11SEVEN.in');    reset(fi);
    assign(fo,'C11SEVEN.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.

