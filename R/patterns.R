find_pat = function(df,pat) {
    for( i in 1:nrow(df)){
        r = df[i,]
        if(all(r[i:length(pat)] == pat))
            print(pat)
        
    }
}



df = data.frame(1:3,4:6,7:9)
df
for (row in 2:3){
        row_va = df[row,]
        pat = row_va[1:2]
        print(pat)
        find_pat(df,pat)
}