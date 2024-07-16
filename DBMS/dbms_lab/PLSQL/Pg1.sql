set serveroutput on
accept x char prompt '1. Debit 2. Credit 3. Show balance Enter your choice: '
DECLARE
bal number(10);
minbal number(10):=500;
acnum number(10);
val number(10);
choice char(1);
BEGIN
choice:=&x;
acnum:=&acnum;
val:=&val;
select balance into bal from account where acnum=accno;
CASE
	WHEN choice='1' THEN
		if ((bal-val)>minbal) then
			bal:=bal-val;
			dbms_output.put_line('Rs. '||val||' is debited from account number '||acnum);
			dbms_output.put_line('Current account balance: '||bal);
			update account set balance=bal where acnum=accno;
			commit;
		else
			dbms_output.put_line('Minimum balance violated!');
		end if;
	WHEN choice='2' THEN
		bal:=bal+val;
		dbms_output.put_line('Rs. '||val||' credited into account successfully!');
		dbms_output.put_line('Current account balance: '||bal);
		update account set balance=bal where acnum=accno;
		commit;
	WHEN choice='3' THEN
		dbms_output.put_line('Account No '||acnum||' Balance: '||bal);
END CASE;
END;
/
