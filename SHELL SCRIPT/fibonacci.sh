echo -n " Enter no.of terms to dispaly : "
read n
n1=0
n2=1
echo -n " Fibonacci series : "
if [ $n -eq 1 ]
then
    echo -n "$n1"
elif [ $n -eq 2 ]
then
    echo -n "$n1 $n2"
else
    echo -n "$n1 $n2"
    for(( i = 3; i <= n; i++))
    do
        sum=` expr $n1 + $n2`
        n1=$n2
        n2=$sum
        echo -n " $sum"
    done
fi
echo