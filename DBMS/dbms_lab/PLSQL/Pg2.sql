set serveroutput on
DECLARE
bal number(10);
minbal number(10):=500;
acnum number(10);
BEGIN
acnum:=&acnum;
select balance into bal from account where acnum=accno;
if ((bal-200)>minbal) then
	bal:=bal-200;
	dbms_output.put_line('Rs. 200 is debited from account number '||acnum||' and new balance is '||bal);
	update account set balance=bal where acnum=accno;
	commit;
else
	dbms_output.put_line('Rs. 200 cannot be debited from account number '||acnum||' since balance is '||bal);
end if;
END;
/
