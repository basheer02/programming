set serveroutput on
declare
	large int;
	small int;
	a int;
	b int;
	c int;
begin
	a := &a;
	b := &b;
	c := &c;
	larr1(a, b, c, large, small);
	dbms_output.put_line('Largest number : '||large);
	dbms_output.put_line('Smallest number : '||small);	
end;
/