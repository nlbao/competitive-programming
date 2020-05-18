var fi,fo:text;
    s,t,rt:ansiString;
    n,sum,count,res,i,j,k:longint;
    ch:char;
    c:array['0'..'9'] of longint;

function    d(c1,c2:char):longint;  begin   exit(ord(c1)-ord(c2));  end;

begin
    assign(fi,'118C.in');   reset(fi);
    assign(fo,'118C.out');  rewrite(fo);
    readln(fi,n,k);
    readln(fi,s);
    res:=1000000000;    rt:=s;
    fillchar(c, sizeof(c), 0);
    for i:=1 to n do inc(c[s[i]]);
    for ch:='0' to '9' do begin
        t:=s;
        sum:=0;
        count:=c[ch];
        for i:=1 to 9 do begin
            for j:=1 to n do
                if count >= k then break
                else
                    if d(t[j],ch) = i then begin
                        t[j]:=ch;
                        inc(count);
                        sum:=sum+i;
                    end;
            for j:=n downto 1 do
                if count >= k then break
                else
                    if d(t[j],ch) = -i then begin
                        t[j]:=ch;
                        inc(count);
                        sum:=sum+i;
                    end;
        end;
        if (sum < res) or ((sum = res) and (t < rt)) then begin
            res:=sum;
            rt:=t;
        end;
    end;
    writeln(fo,res);
    writeln(fo,rt);
    close(fo);
    close(fi);
end.