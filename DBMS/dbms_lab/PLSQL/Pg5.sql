set serveroutput on
DECLARE
	CURSOR cur is select * from student1 where s1g+s2g>12 order by rollno;
	maxg number(2);
BEGIN
	FOR i IN cur LOOP
		IF i.s1g>i.s2g then
			maxg:=i.s1g;
		ELSE
			maxg:=i.s2g;
		END IF;
		dbms_output.put_line(i.name||' Roll number: '||i.rollno||' Highest grade: '||maxg);
	END LOOP;
END;
/
