{$M 16777216}
uses    math;

const   MAX_N = 504;
        oo = 1000001000;

var fi,fo:text;
    m,n,k:longint;
    s,res:ansiString;
    ok:array[0..MAX_N,0..MAX_N] of boolean;
    f:array[0..MAX_N,0..MAX_N] of longint;


procedure   enter;
var i,j:longint;
begin
    readln(fi,m,n,k);
    fillchar(ok,sizeof(ok),false);
    for i:=1 to m do begin
        readln(fi,s);
        for j:=1 to n do
            ok[i][j]:=(s[j] <> '#');
    end;
end;

procedure   up(var x:longint;   y:longint); begin   x:=x+y; end;

function    solve:boolean;
var i,j:longint;
begin
    fillchar(f,sizeof(f),0);
    f[m][n]:=1;
    for i:=m downto 1 do
        for j:=n downto 1 do
            if ok[i][j] then begin
                f[i][j]:=min(f[i][j],oo);
                up(f[i-1][j], f[i][j]);
                up(f[i][j-1], f[i][j]);
            end
            else f[i][j]:=0;

    if f[1][1] = 0 then exit(false);

    res:='';
    i:=1;   j:=1;
    while (i <> m) or (j <> n) do
        if f[i+1][j] >= k then begin
            i:=i+1;
            res:=res+'D';
        end
        else if f[i][j] >= k then begin
            k:=k-f[i+1][j];
            j:=j+1;
            res:=res+'R';
        end
        else exit(false);

    if k > 1 then exit(false);
    writeln(fo,res);
    exit(true);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'286.in');    reset(fi);
    assign(fo,'286.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    if not solve() then
        writeln(fo,'impossible');
    close(fo);
    close(fi);
end.