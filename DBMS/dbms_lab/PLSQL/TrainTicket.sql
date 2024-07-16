set serveroutput on
accept x char prompt '1. Reservation 2. Cancelation 3. Seats available Enter your choice: ';
DECLARE
	seatsb int;
	seatr int;
	trainn int;
	choice char(1);
BEGIN
	choice := &x;
	trainn := &trainn;
	seatsb := &seatsb;
	select seats into seatr from train where tno=trainn;
	case choice

	when '1' then
		if((seatr-seatsb)>=0) then

		update train set seats=seatr-seatsb where tno=trainn;
		commit;
		seatr := seatr-seatsb;
		dbms_output.put_line('Successfully booked! Train number '||trainn||': '||seatr||' seats remaining');

		else
		dbms_output.put_line('Booking unsuccessful! Train number '||trainn||': '||seatr||' seats remaining');

		end if;

	when '2' then
		update train set seats=seatr+seatsb where tno=trainn;
		commit;
		seatr := seatr+seatsb;
		dbms_output.put_line('Cancellation successful! Train number '||trainn||': '||seatr||' seats remaining');

	when '3' then
		dbms_output.put_line('Train number '||trainn||': '||seatr||' seats remaining');
	end case;
END;
/
