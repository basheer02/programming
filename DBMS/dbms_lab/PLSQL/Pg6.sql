set serveroutput on
accept x char prompt 'Input the consumer number: '
DECLARE
	CURSOR cur IS SELECT * FROM CONSUMER;
	unit float;
	unitc float;
	bill float;
	choice int;
BEGIN
	choice:=&x;
	FOR i IN cur LOOP
		if i.consno = choice then
			bill:=0;
			unit:=i.preread-i.pastread;
			unitc:=unit;
			
			if (unit>500) then
				bill:=bill+100*5+200*7.5+200*15;
				unit:=unit-500;
				bill:=bill+unit*22.5;
			elsif(unit>300) then
				bill:=bill+100*5+200*7.5;
				unit:=unit-300;
				bill:=bill+unit*15;
			elsif(unit>100) then
				bill:=bill+100*5;
				unit:=unit-100;
				bill:=bill+unit*7.5;
			else
				bill:=unit*5;
			END IF;
			dbms_output.put_line('Consumer no: '||i.consno);
			dbms_output.put_line('Consumer name: '||i.name);
			dbms_output.put_line('Units consumed '||unitc);
			dbms_output.put_line('Bill: Rs. '||bill);
		END IF;
	END LOOP;
END;
/
