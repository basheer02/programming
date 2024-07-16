function revealmessage(){
    document.getElementById("hiddenmessage").style.display='block';
}
function countdown(){
    var currentval=document.getElementById("CountButton").innerHTML;
    var newval=currentval-1;
    if(newval==-1){
        alert("don't click again");
        newval=0;
    }
    document.getElementById("CountButton").innerHTML=newval;
}