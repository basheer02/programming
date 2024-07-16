sal = [4000,3000,1000,2000]
mn,mx = min(sal),max(sal)
s = sum(sal) - (mn+mx)
a = s/(len(sal)-2)
print(" Avg. salary except min and max : ",a)