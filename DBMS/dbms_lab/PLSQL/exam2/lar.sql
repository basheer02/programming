set serveroutput on
create or replace procedure larr1(x in int, y in int, z in int, l out int, s out int) is
begin
	l:=x;
	if l<y then
		l:=y;
	end if;
	if l<z then
		l:=z;
	end if;
	s:=x;
	if s>y then
		s:=y;
	end if;
	if s>z then
		s:=z;
	end if;
end;
/