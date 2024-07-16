create sequence train_seq;
CREATE OR REPLACE TRIGGER train_insert
BEFORE INSERT ON train
FOR EACH ROW
BEGIN
  SELECT train_seq.nextval INTO :new.tno FROM DUAL;
END;
/
