{$M 1000000000}

const   MAX_N = 200010;

type    pNode = ^recNode;
        recNode = record
            is_num:boolean;
            value:string[10];
            left,right:pNode;
            vleft,vright:boolean;
        end;

var fi,fo:text;
    toan_tu:set of char = ['+','-','*'];
    n,top:longint;
    root:pNode;
    stack:array[0..MAX_N] of pNode;
    inp:ansiString;
    ok:array[0..MAX_N] of boolean;


procedure   new_node(var p:pNode;   v:string);
begin
    new(p);
    if (length(v) = 1) and (v[1] in toan_tu) then p^.is_num:=false
    else p^.is_num:=true;
    p^.value:=v;
    p^.left:=nil;   p^.right:=nil;
    p^.vleft:=false;    p^.vright:=false;
end;


procedure   enter();
var i,m:longint;
    s:string;
    p:pNode;
begin
    readln(fi,n);
    readln(fi,inp);
    m:=length(inp);
    top:=0; stack[1]:=nil;
    s:='';
    for i:=1 to m do
        if inp[i] = ' ' then begin
            if length(s) > 0 then begin
                inc(top);
                new_node(stack[top],s);
                s:='';
            end;
        end
        else if (inp[i] in toan_tu) and ((i = m) or (inp[i+1] = ' ')) then begin
            new_node(p,inp[i]);
            p^.left:=stack[top-1];
            p^.right:=stack[top];
            dec(top);
            stack[top]:=p;
        end
        else s:=s+inp[i];
    root:=stack[1];
end;

procedure   print_res();
var i:longint;
begin
    if root = nil then exit;
    top:=1; stack[1]:=root;
    i:=1;
    while i <= top do begin
        if stack[i]^.left <> nil then begin
            inc(top);   stack[top]:=stack[i]^.right;
            inc(top);   stack[top]:=stack[i]^.left;
        end;
        inc(i);
    end;
    for i:=top downto 2 do write(fo,stack[i]^.value,' ');
    write(fo,root^.value);
end;

procedure   solve_1();
begin
    print_res();
    writeln(fo);
end;

procedure   dfs(p:pNode;    change:boolean);
begin
    if p = nil then exit;
    if change then begin
        dfs(p^.left,true);
        if p^.is_num = true then begin
            if p^.value[1] = '-' then delete(p^.value,1,1)
            else p^.value:='-'+p^.value;
        end
        else if p^.value = '+' then dfs(p^.right,true)
        else dfs(p^.right,false)
    end
    else begin
        dfs(p^.left,false);
        dfs(p^.right,p^.value = '-');
    end;
    if p^.value = '-' then p^.value:='+';
end;

procedure   solve_2();
var i:longint;
begin
    dfs(root,false);
    print_res();
end;

begin
    assign(fi,'test.out'{'vmqpofi.in'});    reset(fi);
    assign(fo,'vmqpofi.out');   rewrite(fo);
    enter();
    solve_1();
    solve_2();
    close(fo);
    close(fi);
end.