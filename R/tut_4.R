a <- c(1:5)
b <- c(11:15)
c = c(16:20)

d1 <- data.frame(a = a,b = b,c = c(12:16))
d2 <- data.frame(a = b,b = a,c = c)
d1
d2
setdiff(d1,d2)