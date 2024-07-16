set serveroutput on
CREATE OR REPLACE TRIGGER T
  BEFORE
    INSERT OR
    UPDATE OF rollno,name,s1g,s2g OR
    DELETE
  ON student1
  FOR EACH ROW
    BEGIN
	CASE
		WHEN INSERTING THEN
			dbms_output.put_line('Trigger message: INSERTING '||:new.name);
		WHEN UPDATING('rollno') THEN
			dbms_output.put_line('Trigger message: UPDATING ROLL NO '||:old.rollno||' TO '||:new.rollno);
		WHEN UPDATING('name') THEN
			dbms_output.put_line('Trigger message: UPDATING NAME '||:old.name||' TO '||:new.name);
		WHEN UPDATING('s1g') THEN
			dbms_output.put_line('Trigger message: UPDATING S1 GRADE '||:old.s1g||' TO '||:new.s1g);
		WHEN UPDATING('s2g') THEN
			dbms_output.put_line('Trigger message: UPDATING S2 GRADE '||:old.s2g||' TO '||:new.s2g);
		WHEN DELETING THEN
			dbms_output.put_line('Trigger message: DELETING '||:old.name);
	END CASE;
    END;
/
