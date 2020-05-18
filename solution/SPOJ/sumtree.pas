{$M+ 2000000}
{$R-, $I-, $Q-}

uses    math;

const   MAX_N = 1000006;
        oo = 1000000000;
        MODULE = 2097152-1;
        R = 10007;

type    ll = int64;

var fi,fo:text;
    n,nE,s,top:longint;
    a,e,link,head,stack,num:array[0..MAX_N] of longint;
    h,c:array[0..MODULE] of longint;
    ok:array[0..MODULE] of boolean;
    res:ll;


procedure   enter();
var i,j:longint;
begin
    nE:=0;
    read(fi,n,s);
    for i:=0 to n+1 do head[i]:=0;
    for i:=1 to n do begin
        read(fi,j,a[i]);
        inc(nE);
        e[nE]:=i;
        link[nE]:=head[j];
        head[j]:=nE;
    end;
end;


function    find(x:ll):longint;
var i:ll;
begin
    i:=x and MODULE;
    if i < 0 then i:=(i+MODULE+1) and MODULE;
    while (ok[i]) and (h[i] <> x) do
        i:=(i+R) and MODULE;
    ok[i]:=true;
    h[i]:=x;
    exit(i);
end;


{procedure   dfs(u:longint);
var i,j,v:longint;
begin
    res:=res + int64(c[find(a[u]-s)]);
    j:=find(a[u]);
    c[j]:=c[j]+1;

    i:=head[u];
    while i <> 0 do begin
        v:=e[i];
        a[v]:=a[u]+a[v];
        dfs(v);
        i:=link[i];
    end;

    c[j]:=c[j]-1;
end;}


procedure   solve();
var i,j,u,v:longint;
    check:boolean;
begin
    res:=0;
    for i:=0 to MODULE do begin
        ok[i]:=false;
        c[i]:=0;
    end;
    for i:=0 to n do num[i]:=-1;

    a[0]:=0;
    //dfs(0);
    top:=1;
    stack[1]:=0;
    i:=find(0); c[i]:=1;
    num[0]:=i;

    while top > 0 do begin
        u:=stack[top];
        check:=true;

        i:=head[u];
        while i <> 0 do begin
            v:=e[i];
            if num[v] < 0 then begin
                a[v]:=a[u]+a[v];
                inc(top);
                stack[top]:=v;

                res:=res + int64(c[find(a[v]-s)]);
                num[v]:=find(a[v]);
                inc(c[num[v]]);

                check:=false;
                head[u]:=link[i];
                break;
            end;
            i:=link[i];
        end;

        if check then begin
            dec(c[num[u]]);
            dec(top);
        end;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'sumtree.in');   reset(fi);
    assign(fo,'sumtree.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.
