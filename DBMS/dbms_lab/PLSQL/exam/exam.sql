set serveroutput on
create or replace procedure cde 
is
counter int;
begin
    select count(*) into counter from employee where salary > 50000;
    dbms_output.put_line(counter);
end;
/