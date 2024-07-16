library(stringi)
a1 <- c(sample(1000:2000,9,replace = FALSE))
a2 <- c(sample(3000:5000,9,replace = FALSE))
x <- array(c(a1,a2),dim = c(3,3,2))
x

for(i in x){
    if(stri_reverse(i) == i){
        num <- i
        cat(num, file = "text_file.txt",append = TRUE, sep = "\n")
    }
}

print(read.table("text_file.txt"))