{$M+, 10000000}
{$R+}

const   INPUT = '82C.in';
        OUTPUT = '82C.out';
        MAX_N = 100010;
        MAX_M = MAX_N;
        MAX_INT = 1000000000000000000;

var fi,fo:text;
    n,root:longint;
    key:array[0..MAX_N] of double;
    c,des:array[0..MAX_N,0..1] of longint;
    value,sum,count:double;

{---------------------------------------------------------------------------}
function    min(x,y:double):double;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,u:longint;
begin
    readln(fi,n);
    for i:=1 to n do begin
        c[i][0]:=-1;
        c[i][1]:=-1;
    end;
    for i:=1 to n do begin
        readln(fi,u,key[i]);
        if u = -1 then root:=i
        else
            if c[u][0] = -1 then c[u][0]:=i
            else c[u][1]:=i;
    end;
    for i:=1 to n do
        if (c[i][0] > -1) and (key[c[i][0]] > key[c[i][1]]) then begin
            u:=c[i][0];
            c[i][0]:=c[i][1];
            c[i][1]:=u;
        end;
end;
{---------------------------------------------------------------------------}
procedure   init(u:longint);
var i,v:longint;
begin
    des[u][0]:=u;   des[u][1]:=u;
    for i:=0 to 1 do
        if c[u][i] > -1 then begin
            v:=c[u][i];
            init(v);
            des[u][i]:=des[v][i];
        end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var v0,v1:longint;
begin
    if c[u][0] = -1 then exit;
    v0:=des[c[u][0]][1];
    v1:=des[c[u][1]][0];
    if value = key[u] then begin
        sum:=sum+key[v0]+key[v1];
        count:=count+2;
    end
    else if value < key[u] then begin
        sum:=sum+key[v1];
        count:=count+1;
        DFS(c[u][0]);
    end
    else begin
        sum:=sum+key[v0];
        count:=count+1;
        DFS(c[u][1]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,k:longint;
begin
    init(root);
    readln(fi,k);
    for i:=1 to k do begin
        readln(fi,value);
        sum:=0; count:=0;
        DFS(root);
        if count > 0 then sum:=sum/count;
        writeln(fo,sum:0:10);
    end;
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