var
    A,B,P,x:int64;
    s:string;

begin
    writeln((1000000000+7*10)/7:0:5);

    {readln(A,B,P);
    x:=((P+B) div 1000000000);
    if x <= A then begin
        write(1,' ');
        str(x,s);
        while length(s) < 9 do s:='0'+s;
        write(s);
    end
    else writeln(2);}
    readln;
end.