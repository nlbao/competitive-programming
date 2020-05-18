{$M 16777216}
uses    math;

const   MAX_N = 1000006;
        oo = 1000000000;
        BASE = 10007;

type    ll = int64;

var fi,fo:text;
    n,m,nQ:longint;
    a,b,res:ansiString;
    l,r,u,v:array[0..MAX_N] of longint;
    p,g,h:array[0..MAX_N] of ll;


procedure   enter();
var i:longint;
begin
    readln(fi,n,m);
    readln(fi,a);
    readln(fi,b);
    read(fi,nQ);
    for i:=1 to nQ do
        read(fi,l[i],r[i],u[i],v[i]);
end;

function    cmp(x,y:char):char;
begin
    if x < y then exit('<');
    if x > y then exit('>');
    exit('=');
end;


procedure   solve_0();
var i,j,k,t,x,y,len:longint;
    ch:char;
begin
    res:='';
    for k:=1 to nQ do begin
        x:=l[k];    y:=r[k];
        i:=u[k];    j:=v[k];
        if y-x < j-i then ch:='<'
        else if y-x > j-i then ch:='>'
        else ch:='=';

        len:=min(y-x,j-i);
        for t:=0 to len do
            if a[x+t] <> b[i+t] then begin
                ch:=cmp(a[x+t],b[i+t]);
                break;
            end;
        res:=res+ch;
    end;
    writeln(fo,res);
end;

procedure   init();
var i,k:longint;
begin
    p[0]:=1;
    k:=max(n,m);
    for i:=1 to k do p[i]:=longint(p[i-1]*BASE);

    h[0]:=0;    g[0]:=0;
    for i:=1 to n do h[i]:=longint(h[i-1]*BASE + int64(ord(a[i])));
    for i:=1 to m do g[i]:=longint(g[i-1]*BASE + int64(ord(b[i])));
end;

function    get_h(i,j:longint):longint;
begin   exit(longint(h[j] - h[i-1]*p[j-i+1]));  end;

function    get_g(i,j:longint):longint;
begin   exit(longint(g[j] - g[i-1]*p[j-i+1]));  end;


procedure   solve_1();
var i,j,k,t,x,y,len,left,right,mid:longint;
    ch:char;
begin
    init();

    for k:=1 to nQ do begin
        x:=l[k];    y:=r[k];
        i:=u[k];    j:=v[k];
        if y-x < j-i then ch:='<'
        else if y-x > j-i then ch:='>'
        else ch:='=';

        len:=min(y-x,j-i);  t:=-1;
        left:=0;    right:=len;
        while left <= right do begin
            mid:=(left+right) shr 1;
            if get_h(x,x+mid) = get_g(i,i+mid) then begin
                t:=mid;
                left:=mid+1;
            end
            else right:=mid-1;
        end;

        if t < len then ch:=cmp(a[x+t+1],b[i+t+1]);
        write(fo,ch);
        {if ch <> res[k] then begin
            writeln(fo);
            writeln(fo,'------------------------------------------------');
            exit;
        end;}
    end;
end;


procedure   gen_test(limit:longint);
var i:longint;
begin
    randomize;
    n:=random(limit);
    m:=random(limit);
    a:='';
    b:='';
    for i:=1 to n do a:=a+chr(ord('a')+random(26));
    for i:=1 to m do b:=b+chr(ord('a')+random(26));
    {writeln(a);
    writeln(b);
    writeln(fo,a);
    writeln(fo,b);}
    nQ:=random(limit);
    for i:=1 to nQ do begin
        l[i]:=random(n)+1;
        r[i]:=l[i]+random(n-l[i]);
        u[i]:=random(m)+1;
        v[i]:=u[i]+random(m-u[i]);
    end;
    writeln(n,' ',m);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VOSTR.in');    reset(fi);
    assign(fo,'VOSTR.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    //gen_test(1000000);
    if (n <= 1000) and (m <= 1000) and (nQ <= 1000) then solve_0()
    else solve_1();
    close(fo);
    close(fi);
end.