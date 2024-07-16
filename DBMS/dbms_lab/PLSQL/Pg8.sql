set serveroutput on
CREATE OR REPLACE TRIGGER stud_marks
  BEFORE
  INSERT
  ON studrep
  FOR EACH ROW
  BEGIN
	update studrep set studrep.total = studrep.subj1 + studrep.subj2 + studrep.subj3;
	update studrep set studrep.avrg = studrep.total/3;
  END;
/
