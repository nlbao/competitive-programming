{$M 16777216}
uses    math;

const   MAX_N = 40004;
        oo = 2000000000;

type    ll = int64;
        pNode = ^recNode;
        recNode = record
            pos:longint;
            left,right:pNode;
        end;

var fi,fo:text;
    n,m:longint;
    a,f:array[0..MAX_N] of longint;
    b:array[0..MAX_N] of pNode;
    last:pNode;


procedure   enter();
var i:longint;
begin
    read(fi,n,m);
    for i:=1 to n do read(fi,a[i]);
end;


procedure   new_node(var p:pNode;   i:longint);
begin
    if p <> nil then begin
        if p^.left <> nil then p^.left^.right:=p^.right;
        if p^.right <> nil then p^.right^.left:=p^.left
        else last:=p^.left;
    end;
    dispose(p);
    new(p);
    p^.pos:=i;
    p^.left:=last;
    p^.right:=nil;
    if last <> nil then last^.right:=p;
    last:=p;
end;


procedure   solve();
var i,k,c,limit:longint;
    p:pNode;
begin
    for i:=0 to n do b[i]:=nil;
    last:=nil;
    new_node(b[0],0);
    f[0]:=0;

    limit:=trunc(sqrt(n)+4);
    for i:=1 to n do begin
        f[i]:=oo;
        p:=last;    c:=1;
        while p <> nil do begin
            k:=p^.pos;
            if c > limit then break;
            f[i]:=min(f[i], f[k] + c*c);
            if a[k] <> a[i] then inc(c);
            p:=p^.left;
        end;
        new_node(b[a[i]],i);
    end;
    writeln(fo,f[n]);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'CTNCLN.in');    reset(fi);
    assign(fo,'CTNCLN.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.