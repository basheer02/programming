echo -n " Enter the number : "
read n
sum=1
for(( i = 1; i <= n; i++ ))
do
    sum=` expr $sum '*' $i`
done
echo " Factorial of $n : $sum"