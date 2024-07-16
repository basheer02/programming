n1 = sum = 0
n2 <- 1
lst <- list()
randNum <- c(sample(100:200,10,replace=FALSE))
cat(" Random numbers : ")
randNum

while(sum < 200){
    sum <- n1 + n2
    n1 <- n2
    n2 <- sum
    if(sum %in% randNum)
        lst <- append(lst,sum)
}

if(length(lst) == 0){
    print(" fibonacci numbers doesn't exist in the random numbers ")
}else{
   print(paste(" fibonacci numbers exist in the random numbers are : ",lst))
}