{$M 16777216}
uses    math;

const   MAX_N = 55;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,k,last:longint;
    a:array[0..4,0..1] of longint;
    f:array[0..MAX_N,0..4] of ll;
    res:string;


procedure   enter;
var ch:char;
begin
    read(fi,ch,n,k);
    case ch of
        'A': last:=0;
        'B': last:=1;
        'D': last:=2;
        'C': last:=3;
    end;
    a[0][0]:=3; a[0][1]:=1;
    a[1][0]:=2; a[1][1]:=0;
    a[2][0]:=1; a[2][1]:=3;
    a[3][0]:=0; a[3][1]:=2;
end;


function    solve:boolean;
var i,j,x:longint;
begin
    fillchar(f,sizeof(f),0);
    f[n][last]:=1;
    for i:=n-1 downto 0 do
        for j:=0 to 3 do
            for x:=0 to 1 do
                f[i][j]:=f[i][j] + f[i+1][a[j][x]];

    if f[0][0] < k then exit(false);

    j:=0;
    res:='';
    for i:=1 to n do begin
        if f[i][a[j][0]] >= k then begin
            res:=res+'0';
            j:=a[j][0];
        end
        else begin
            k:=k-f[i][a[j][0]];
            res:=res+'1';
            j:=a[j][1];
        end;
    end;

    writeln(fo,res);
    exit(true);
end;



begin
//{$IFNDEF ONLINE_JUDGE}
    //assign(fi,'355.in');    reset(fi);
    //assign(fo,'355.out');   rewrite(fo);
//{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
//{$ENDIF}
    enter();
    if not solve() then
        writeln(fo,'impossible');
    close(fo);
    close(fi);
end.