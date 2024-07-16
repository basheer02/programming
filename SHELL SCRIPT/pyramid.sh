echo -n " Enter no.of steps to print : "
read n
m=1
for(( i = 1; i <= n; i++))
do
    for(( j = 1; j <= i; j++))
    do
        echo -n "" $m ""
        m=` expr $m + 1`
    done
    echo
done