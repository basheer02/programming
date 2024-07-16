echo -n " Enter total no.of numbers : "
read n
declare -a num
echo -n " Enter elements : "
read -a num
echo -n " Numbers before sorting : "
for i in "${num[@]}"
do
    echo -n $i ""
done

for(( i = 0; i < n; i++))
do
    for(( j = i+1 ; j < n; j++))
    do
        if [ ${num[$i]} -gt ${num[$j]} ]
        then
            temp=${num[$i]}
            num[$i]=${num[$j]}
            num[$j]=$temp
        fi
    done
done

echo
echo -n " Numbers after sorting : "
for i in "${num[@]}"
do
    echo -n $i ""
done
echo