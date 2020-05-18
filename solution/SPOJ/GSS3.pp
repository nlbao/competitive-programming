const
    INPUT = 'GSS3.inp';
    OUTPUT = 'GSS3.out';
    MAX_N = 50000;
    IT_SIZE = 8*MAX_N;

type
    pIT = ^recIT;
    recIT = record
        leaf:boolean;
        value,sum,maxL,maxR,maxA:longint;
        left,right:pIT;
    end;

var
    fi,fo:text;
    N,M:longint;


begin

end.