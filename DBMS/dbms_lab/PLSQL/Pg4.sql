CREATE OR REPLACE FUNCTION dc(x in number) RETURN VARCHAR IS msg varchar(8);
BEGIN
	if x>50000 then
		msg:='Platinum';
	elsif x>10000 then
		msg:='Gold';
	else
		msg:='Silver';
	end if;
	return msg;
END;
/

--select name,value,dc(value) from table_name