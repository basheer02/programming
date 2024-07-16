df <- scan(file = 'data.txt',what = 'character', sep = ' ')
print('Words in the file')
df
lst = list()
for( word in df){
	str = substr(word,1,1)
	if(!str %in% names(lst))
		lst[[str]] = c(nchar(word))
	else {
	   lst[[str]] = append(lst[[str]],nchar(word))
	} 
}
lst[[length(lst)]] = NULL
print('Length of word starts with each char')
print(lst)
print('Mean of words starts with each character')
print(lapply(lst, mean))

