l = list(name='nom', union=T)
names(l) <- NULL
x <- unlist(l)
x
class(x)