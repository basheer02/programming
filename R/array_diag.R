display_diag_swap_rows <- function(arr) {
    # Display diagonal elements
    diag_elements <- c(diag(arr[,,1]),diag(arr[,,2]),diag(arr[,,3]))
    cat("Diagonal elements : ", diag_elements, "\n")

    # Swap first and last rows
    arr_dim <- dim(arr)
    a <- arr[1,,]
    arr[1,,] <- arr[arr_dim[1],,]
    arr[arr_dim[1],,] <- a

  return(arr)
}

# Create a 3D array
arr <- array(1:27, dim = c(3, 3, 3))

# Print the original array
print(arr)
#print(dim(arr))

# Call the function to display diagonal elements and swap rows
arr_swapped <- display_diag_swap_rows(arr)

# Print the updated array
print(arr_swapped)
