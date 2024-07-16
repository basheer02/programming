set serveroutput on
create or replace procedure revv(x in int) 
is
rev int := 0;
n int;
begin
	n := x;
	while n>0 loop
		rev := (rev*10) + mod(n, 10);
		n := floor(n/10);
	end loop;
	dbms_output.put_line('Reverse of the number '||x||' is '||rev);
end;
/