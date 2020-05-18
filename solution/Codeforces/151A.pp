var fi,fo:text;
    n,k,l,c,d,p,nl,np:longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

begin
    assign(fi,'151A.in');   reset(fi);
    assign(fo,'151A.out');  rewrite(fo);
    readln(fi,n,k,l,c,d,p,nl,np);
    writeln(fo,min(min((k*l) div nl, c*d), p div np) div n);
    close(fo);
    close(fi);
end.