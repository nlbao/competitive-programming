uses    math;

const   MAX_N = 210;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            u,v:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,l,r,mid,res,i,j:longint;
    a:array[0..MAX_N,0..MAX_N] of longint;
    e:array[0..MAX_M] of recEdge;
    head,match,list:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    found:boolean;


procedure   add_edge(u0,v0:longint);
begin
    inc(m);
    with e[m] do begin
        u:=u0;   v:=v0;
        link:=head[u];
        head[u]:=m;
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[v] then begin
            ok[v]:=false;
            if match[v] = 0 then found:=true
            else dfs(match[v]);
            if found then begin
                match[v]:=u;
                exit;
            end;
        end;
        i:=link;
    end;
end;

function    check(value:longint):boolean;
var nX,nY,i,j,pnX,c:longint;
begin
    m:=0;
    nX:=n;  nY:=n;
    for i:=1 to n do begin
        head[i]:=0;
        match[i]:=0;
        list[i]:=i;
    end;
    for i:=1 to n do
        for j:=1 to n do
            if a[i][j] <= value then
                add_edge(i,j);
    repeat
        pnX:=nX;
        fillchar(ok,sizeof(ok),true);
        for i:=nX downto 1 do begin
            found:=false;
            dfs(list[i]);
            if found then begin
                list[i]:=list[nX];
                dec(nX);
            end;
        end;
    until nX = pnX;
    c:=0;
    for i:=1 to nY do
        if match[i] > 0 then inc(c);
    if c = n then exit(true);
    exit(false);
end;


begin
    assign(fi,'assign1.in');    reset(fi);
    assign(fo,'assign1.out');   rewrite(fo);
    l:=0;   r:=0;
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,a[i][j]);
            r:=max(r,a[i][j]);
        end;
    res:=r;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if check(mid) = true then begin
            res:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.