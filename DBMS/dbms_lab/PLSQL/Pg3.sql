set serveroutput on
DECLARE
avgmrk number(3);
msg varchar2(20):='Need improvement';
today varchar2(20);
weekday varchar2(20);
BEGIN
	select avg(marks) into avgmrk from student1;
	dbms_output.put_line('Average marks of students in the class = '||avgmrk);
	IF (avgmrk<40) THEN
		dbms_output.put_line(msg);
	END IF;
	select to_char(current_date,'dd-mon-yyyy') into today from dual;
	select to_char(current_date,'DAY') into weekday from dual;
	dbms_output.put_line('Today''s date: '||today);
	dbms_output.put_line('Day of week: '||weekday);
END;
/
