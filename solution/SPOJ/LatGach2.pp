program latgach;
const
inp='latgach.inp';
out='latgach.out';
var
fi,fo:text;
i,n,t:byte;
a:array[1..100] of STRING;
function cong(x,y:string):string;
var k,z,u,v,d:byte;
tt:integer;
kq,kt:string;
begin
kq:='';
k:=length(x);
z:=length(y);
d:=0;
repeat
val(x[k],u,tt);
val(y[z],v,tt);
d:=d+u+v;
str(d mod 10,kt);
insert(kt[1],kq,1);
d:=d div 10;
if k>0 then dec(k);
if z>0 then dec(z);
until (z=0) and (k=0) and (d=0);
cong:=kq;
end;
begin
assign(fi,inp);
assign(fo,out);
reset(fi);
rewrite(fo);
a[1]:='1';
a[2]:='2';
for i:=3 to 100 do
a[i]:=cong(a[i-1],a[i-2]);
readln(fi,n);
for i:=1 to n do
begin
readln(fi,t);
writeln(fo,a[t]);
end;
close(fi);
close(fo);
end.