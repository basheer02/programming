function myFunction() {
  var txt;
  var person = prompt("Please enter your name:");
  if (person == null || person == "") {
  txt = "Are you cancelled the prompt?";
  } else {
    txt = "Hello " + person + "! How are you today?";
  }
  document.getElementById("demo").innerHTML = txt;
}