const   INPUT = 'BINTree.in';
        OUTPUT = 'BINTree.out';
        MAX_N = 50010;

var fi,fo:text;
    n:longint;
    a,b,pos,left,right:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do begin
        read(fi,b[i]);
        pos[b[i]]:=i;
    end;
end;

procedure   get(l,r,i,j:longint);
var p,k:longint;
begin
    if l >= r then exit;
    p:=a[l];    k:=pos[p];
    if k > i then begin
        left[p]:=a[l+1];
        get(l+1,l+k-i,i,k-1);
    end;
    if k < j then begin
        right[p]:=a[l+k-i+1];
        get(l+k-i+1,r,k+1,j);
    end;
end;

procedure   DFS(u:longint);
begin
    if left[u] > 0 then DFS(left[u]);
    if right[u] > 0 then DFS(right[u]);
    write(fo,u,' ');
end;

procedure   solve;
var i,root:longint;
begin
    for i:=1 to n do begin
        left[i]:=0;
        right[i]:=0;
    end;
    root:=a[1];
    get(1,n,1,n);
    DFS(root);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.