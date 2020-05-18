uses    math;

const   MAX_M = 5003;
        oo = 1000000000;

type    ll = int64;
        recA = record
            x,y:longint;
            d:boolean;
        end;

var fi,fo:text;
    n,m,nQ,i,j,id,res:longint;
    a:array[0..MAX_M] of recA;
    s:string;
    ck:boolean;


procedure   swap(i,j:longint);
var t:recA;
begin   t:=a[i];    a[i]:=a[j];     a[j]:=t;    end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'ILSBIN.in');    reset(fi);
    assign(fo,'ILSBIN.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    randomize;
    readln(fi,n);
    readln(fi,nQ);
    res:=0;
    m:=0;
    for id:=1 to nQ do begin
        inc(m);
        with a[m] do begin
            readln(fi,x,y,s);
            d:=(s[2] = 'o');
        end;

        ck:=true;
        i:=m-1;
        while (i > 0) and (a[i].x >= a[m].x) do dec(i);
        inc(i);
        while (i < m) and (a[i].x <= a[m].x) do begin
            while (i < m) and (a[i].x < a[m].x) do inc(i);
            if (i >= m) or (a[i].x > a[m].x) then break;
            if a[i].y > a[m].y then swap(i,m)
            else if a[i].y = a[m].y then begin
                ck:=(a[i].d = a[m].d);
                dec(m);
                i:=m;
            end
            else begin
                a[m].x:=a[i].y+1;
                a[m].d:=a[m].d xor a[i].d;
            end;
        end;

        if not ck then break;
        res:=id;
        for j:=i to m-1 do swap(j,m);
    end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.