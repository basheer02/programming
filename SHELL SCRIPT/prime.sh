echo -n " Enter the number : "
read n
for(( i = 2; i <= n/2; i++ ))
do
    if [ `expr $n % $i` -eq 0 ]
    then
        echo " $n not a prime number "
        exit
    fi
done
echo " $n is a prime number "