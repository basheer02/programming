find_outliers <- function(data, coef = 1.5) {
  # calculate the lower and upper bounds using Tukey's fences
  Q1 <- quantile(data, 0.25)
  Q3 <- quantile(data, 0.75)
  IQR <- Q3 - Q1
  lower_bound <- Q1 - coef*IQR
  upper_bound <- Q3 + coef*IQR

  # identify the outliers
  outliers <- data[data < lower_bound | data > upper_bound]
  
  # return the outliers
  return(outliers)
}

# create some sample data
data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20)

# find the outliers
outliers <- find_outliers(data)

# print the outliers
print(outliers)
