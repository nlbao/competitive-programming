uses    math;

var fi,fo:text;
    n,id,i,t,pos:longint;
    a,b,res:double;
    s:ansiString;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'12555.in');    reset(fi);
    assign(fo,'12555.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,n);
    for id:=1 to n do begin
        readln(fi,s);
        a:=-1;  b:=0;
        pos:=-1;
        for i:=1 to length(s) do
            if ('0' <= s[i]) and (s[i] <= '9') then begin
                t:=ord(s[i])-ord('0');
                if a = -1 then begin
                    a:=t;
                    pos:=i;
                end
                else if pos = i-1 then a:=a*10+t
                else b:=t;
            end;
        if a = -1 then a:=0;
        res:=0.5*a+0.05*b;
        str(res:0:10,s);
        while (length(s) > 1) and (s[length(s)] = '0') do delete(s,length(s),1);
        if (s[length(s)] = '.') then delete(s,length(s),1);
        writeln(fo,'Case ',id,': ',s);
    end;
    close(fi);
    close(fo);
end.

