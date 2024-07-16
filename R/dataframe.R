mark1 = c(5,8,7,4)
mark2 = c(6,8,9,6)

df.mark = data.frame(mark1 = mark1, mark2 = mark2)
df.name = data.frame(name = c('a','b','c','d'))

df = cbind(df.name,df.mark)
df

print('highest mark of each student')
print(paste(df.name$name,apply(df.mark, 1, max)))
print('highest mark')
print(apply(df.mark, 2, max))