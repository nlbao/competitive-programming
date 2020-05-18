const   MAX_N = 110;
        oo = 2000000;

var fi,fo:text;
    n,top,i,x,sum,res:longint;
    a:array[0..MAX_N] of longint;
    s:ansiString;


function    num(x:char):longint;
begin
    case x of
        '(': exit(oo);
        ')': exit(-oo);
        'C': exit(12);
        'H': exit(1);
        'O': exit(16);
        else exit(0);
    end;
end;



begin
    assign(fi,'mmass.in');  reset(fi);
    assign(fo,'mmass.out'); rewrite(fo);
    readln(fi,s);
    n:=length(s);
    top:=0;
    for i:=1 to n do begin
        x:=num(s[i]);
        if x = 0 then a[top]:=a[top]*(ord(s[i])-ord('0'))
        else if x = -oo then begin
            sum:=0;
            while (top > 1) and (a[top] <> oo) do begin
                sum:=sum+a[top];
                dec(top);
            end;
            a[top]:=sum;
        end
        else begin
            inc(top);
            a[top]:=x;
        end;
    end;

    res:=0;
    for i:=1 to top do
        if (a[i] <> oo) and (a[i] <> -oo) then res:=res+a[i];
    writeln(fo,res);
    close(fo);
    close(fi);
end.