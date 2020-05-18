const   MAX_N = 1010;
        MAX_M = 100010;

type    recEdge = record
            u,v:longint;
            link:longint;
        end;

var fi,fo:text;
    nX,nY,m:longint;
    head,list,match:array[0..MAX_N] of longint;
    e:array[0..MAX_M] of recEdge;
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

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,nX,nY,j);
    m:=0;
    fillchar(head,sizeof(head),0);
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
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

procedure   solve;
var i,pnX,res:longint;
begin
    fillchar(match,sizeof(match),0);
    for i:=1 to nX do list[i]:=i;
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
    res:=0;
    for i:=1 to nY do
        if match[i] > 0 then inc(res);
    writeln(fo,res);
end;


begin
    assign(fi,'nkbm.in');   reset(fi);
    assign(fo,'nkbm.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.