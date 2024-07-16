package main

import "fmt"

func main() {
	age := 32

	//var agePointer *int

	agePointer := &age

	fmt.Println(" Age :", *agePointer)
	getAdultYears(agePointer)
	fmt.Println("\n Adult since", age, "years ago")
}

func getAdultYears(age *int) {
	//return *age - 18

	*age -= 18
}
